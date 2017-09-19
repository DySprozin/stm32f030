#include "stm32f0xx.h"
#include "lcd.h"
#include "flash.h"

uint32_t flash_read(uint32_t addr);

volatile int sleep = 1, tic = 0, water_ch = 0, water_ch_total = 0, water_display = 1, water_per_min = 0, sleep_dog = 0;

void delay (int ms);
void deep_sleep();

#define cyr_D       0x0
#define cyr_L       0x1
#define cyr_G       0x2
#define cyr_I       0x3

#define WATER_ADDR      0x8003400

#define WAKEUP          0
#define LCD_ST_CP       1
#define LCD_DATA        2
#define LCD_RS          3
#define LCD_E           4
#define LCD_SH_CP       5
#define SENSOR          6
#define RESET_CH        7
#define LCD_LED         1 //PB
#define TIMER           9

#define TEMPF(ARG1, ARG2, ARG3)         ARG1##ARG2##ARG3
 
#define MODER_11(MOD_PORT)       TEMPF(GPIO_MODER_MODER, MOD_PORT,)
#define MODER_01(MOD_PORT)       TEMPF(GPIO_MODER_MODER, MOD_PORT,_0)
#define MODER_10(MOD_PORT)       TEMPF(GPIO_MODER_MODER, MOD_PORT,_1)

#define OTYPER(OTYPER_PORT)      TEMPF(GPIO_OTYPER_OT, _ , OTYPER_PORT)
#define IDR(IDR_PORT)            TEMPF(GPIO_IDR, _ , IDR_PORT)
#define BS(BS_PORT)            TEMPF(GPIO_BSRR_BS, _ , BS_PORT)
#define BR(BR_PORT)            TEMPF(GPIO_BSRR_BR, _ , BR_PORT)

#define PUPDR_11(PUPDR_PORT)     TEMPF(GPIO_PUPDR_PUPDR, PUPDR_PORT,)
#define PUPDR_01(PUPDR_PORT)     TEMPF(GPIO_PUPDR_PUPDR, PUPDR_PORT,_0)
#define PUPDR_10(PUPDR_PORT)     TEMPF(GPIO_PUPDR_PUPDR, PUPDR_PORT,_1)



void lcd_cyr_D();
void lcd_cyr_G();
void lcd_cyr_L();
void lcd_cyr_I();


void TIM1_BRK_UP_TRG_COM_IRQHandler(void) {
  
  TIM1->SR &= ~TIM_SR_UIF;
  
  if (tic++ > 1000) {
    sleep_dog++;
    tic = 0;
    water_display = 1;
  }
  sleep = 0;
}

void main(void)
{


  
__enable_irq();

NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);






 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
 RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

   
 GPIOA->MODER |= MODER_01(LCD_ST_CP) | MODER_01(LCD_DATA) | MODER_01(LCD_RS) |
                 MODER_01(LCD_E) | MODER_01(LCD_SH_CP) | MODER_10(TIMER) ;
 
 GPIOB->MODER |= MODER_01(LCD_LED);
 
 GPIOB->BSRR |= BS(LCD_LED);
 
 GPIOA->MODER &= ~MODER_11(SENSOR);
 GPIOA->MODER &= ~MODER_11(RESET_CH);
 GPIOA->PUPDR |= PUPDR_10(SENSOR);
 GPIOA->PUPDR |= PUPDR_10(RESET_CH);

 
////
//Enable TIMER (TIM1, PA9)
 GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH1);
 GPIOA->AFR[1] |= 2 << ((TIMER-8)*4);
 TIM1->ARR = 8000;
 TIM1->CR1 |= TIM_CR1_CEN;
 TIM1->DIER |= TIM_DIER_UIE;
//
////
 
 
 
 lcd_delay(500);
 
 lcd_init();

 
 flash_enable();

 uint16_t water_flash;
 uint16_t water_tmp_flash;
 water_flash = flash_read(WATER_ADDR);
 water_tmp_flash = flash_read(WATER_ADDR+4);
 

lcd_cyr_D();  
lcd_cyr_G();  
lcd_cyr_L();  
lcd_cyr_I();  

int secsor_flag = 0;
int water_ch_tmp;

water_ch_total = water_flash;
water_ch_tmp = water_tmp_flash;
if (water_ch_total == 0xFFFF) water_ch_total = 0;
if (water_ch_tmp == 0xFFFF) water_ch_tmp = 0;

 while(1) {
   lcd_delay(100);
   if (GPIOA->IDR & IDR(RESET_CH)) {
     delay(5000);
     if (GPIOA->IDR & IDR(RESET_CH)) {
       water_ch_total = 0;
       sleep_dog = 0;
       flash_erase(WATER_ADDR);
       deep_sleep();
     }
   }
   if (GPIOA->IDR & IDR(SENSOR)) {
     if (secsor_flag == 1) {
      secsor_flag = 0;
      sleep_dog = 0;
      water_ch++;
      water_ch_tmp++;
      //в одном литре — 2933 импульса
      if (!(water_ch_tmp % 2933)) {
        water_ch_tmp = 0;
        water_ch_total++;
      }
     }
   }
   else {
     secsor_flag = 1;
   }

////
//DeepSleep Mode Enable (выход по плюсу на PA0) */
   if (sleep_dog > 5) {

     //copy water_ch_total to flash
     flash_erase(WATER_ADDR);
     flash_write_start();
     flash_write(WATER_ADDR, (water_ch_total >> 8), (water_ch_total & 0xFF));
     flash_write(WATER_ADDR+4, (water_ch_tmp >> 8), (water_ch_tmp & 0xFF));
     flash_write_stop();

     deep_sleep();     
   }
//
////
   
   if (water_display == 1) {
    water_per_min = (water_ch >> 1) * 60;
    water_ch = 0;   
    water_display = 0;


    lcd_str(" PACXO", 0); lcd_char(cyr_D,-1); //РАСХОД
    lcd_str("  | ", -1); lcd_char(cyr_I,-1); // | И
    lcd_str("TO", -1); lcd_char(cyr_G,-1);   //   ТОГ
    lcd_str("O", -1);                        //      О
    
/*    lcd_str("6000 M",41); lcd_char(cyr_L,-1); //МЛ
    lcd_str("/M|2549 ",-1); lcd_char(cyr_L,-1); // /М | Л*/
    
    lcd_num_to_str(water_per_min, 4, 41);
    lcd_str(" M",-1); lcd_char(cyr_L,-1); lcd_str("/M|", -1);
    lcd_num_to_str(water_ch_total, 4, -1);
    lcd_char(' ',-1); lcd_char(cyr_L,-1);
    
  }


 }
}

void delay (int ms) {
  for (int i = 0; i <= ms; i++) {
    while (sleep);
    sleep = 1;
  }
}

void lcd_cyr_D() {
   lcd_cmd(0x40, 0);
   lcd_cmd(0x06, 1);
   lcd_cmd(0x0A, 1);
   lcd_cmd(0x0A, 1);
   lcd_cmd(0x0A, 1);
   lcd_cmd(0x0A, 1);
   lcd_cmd(0x0A, 1);
   lcd_cmd(0x1F, 1);
   lcd_cmd(0x11, 1);
   lcd_cmd(0x80, 0);

}


void lcd_cyr_L() {
   lcd_cmd(0x40+8, 0);
   lcd_cmd(0x07, 1);
   lcd_cmd(0x09, 1);
   lcd_cmd(0x09, 1);
   lcd_cmd(0x09, 1);
   lcd_cmd(0x09, 1);
   lcd_cmd(0x09, 1);
   lcd_cmd(0x11, 1);
   lcd_cmd(0x00, 1);
   lcd_cmd(0x80, 0);

}


void lcd_cyr_G() {
   lcd_cmd(0x40+16, 0);
   lcd_cmd(0x1F, 1);
   lcd_cmd(0x10, 1);
   lcd_cmd(0x10, 1);
   lcd_cmd(0x10, 1);
   lcd_cmd(0x10, 1);
   lcd_cmd(0x10, 1);
   lcd_cmd(0x10, 1);
   lcd_cmd(0x00, 1);
   lcd_cmd(0x80, 0);

}



void lcd_cyr_I() {
   lcd_cmd(0x40+24, 0);
   lcd_cmd(0x11, 1);
   lcd_cmd(0x11, 1);
   lcd_cmd(0x13, 1);
   lcd_cmd(0x15, 1);
   lcd_cmd(0x19, 1);
   lcd_cmd(0x11, 1);
   lcd_cmd(0x11, 1);
   lcd_cmd(0x00, 1);
   lcd_cmd(0x80, 0);

}

void deep_sleep() {
 RCC->APB1ENR |= RCC_APB1ENR_PWREN; /* PWR enable */
 SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
 PWR->CR |= PWR_CR_PDDS;
 PWR->CSR |= PWR_CSR_EWUP1;
 PWR->CR |= PWR_CR_CWUF;
 __WFI();
}