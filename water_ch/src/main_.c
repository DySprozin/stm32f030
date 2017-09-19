#include "stm32f0xx.h"
#include "lcd.h"
#include "flash.h"

uint32_t flash_read(uint32_t addr);

volatile int sleep = 1, y = 0, h, m, s;

void delay (int ms);

#define cyr_D       0x0
#define cyr_L       0x1
#define cyr_G       0x2
#define cyr_I       0x3

void lcd_cyr_D();
void lcd_cyr_G();
void lcd_cyr_L();
void lcd_cyr_I();


void TIM1_BRK_UP_TRG_COM_IRQHandler(void) {
  
  TIM1->SR &= ~TIM_SR_UIF;
}

void main(void)
{



  
__enable_irq();

NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);

 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

 GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 |
                 GPIO_MODER_MODER3_0 | GPIO_MODER_MODER4_0 | GPIO_MODER_MODER5_0 |
                 GPIO_MODER_MODER9_1;

 GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH1);
 GPIOA->AFR[1] |= 2 << ((9-8)*4);
 TIM1->ARR = 8000;
 TIM1->CR1 |= TIM_CR1_CEN;
 TIM1->DIER |= TIM_DIER_UIE;
 
 lcd_delay(500);
 
 lcd_init();

 h = 13;
 m = 29;
 s = 0;
 
 flash_enable();


 uint16_t tmp1;
 uint16_t tmp2;
 uint16_t tmp3;
 uint16_t tmp4;
 uint16_t tmp5;
 uint16_t tmp6;
 uint16_t tmp7;
 uint16_t tmp8;

 tmp1 = flash_read(0x8003400);
 tmp2 = flash_read(0x8003400+4);
 tmp3 = flash_read(0x8003400+8);
 tmp4 = flash_read(0x8003400+12);
 tmp5 = flash_read(0x8003400+16);
 tmp6 = flash_read(0x8003400+20);
 tmp7 = flash_read(0x8003400+24);
 tmp8 = flash_read(0x8003400+28);
 
 
  lcd_char(tmp1,41); 
  lcd_char(tmp2,-1); 
  lcd_char(tmp3,-1); 
  lcd_char(tmp4,-1); 
  lcd_char(tmp5,-1); 
  lcd_char(tmp6,-1); 
  lcd_char(tmp7,-1); 
  lcd_char(tmp8,-1); 
lcd_char('!',0);
 // delay(5000);
 
lcd_cyr_D();  
lcd_cyr_G();  
lcd_cyr_L();  
lcd_cyr_I();  

 while(1) {
   

   
   lcd_str(" PACXO", 0); lcd_char(cyr_D,-1);
   lcd_str("  | ", -1); lcd_char(cyr_I,-1);
   lcd_str("TO", -1); lcd_char(cyr_G,-1);
   lcd_str("O", -1);

   lcd_str("6000 M",41); lcd_char(cyr_L,-1);
   lcd_str("/M|2549 ",-1); lcd_char(cyr_L,-1);


   lcd_char(':',-1);


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
