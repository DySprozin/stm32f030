#include "stm32f0xx.h"
#include "def.h"
#include "tim3.h"
#include "usart.h"
#include "adc.h"
#include "lcd.h"
 

volatile int ch_rots, 
            ch_rots_slow,
            ch_rots_permin,
            rots_set,
            rots_set_tmp,
            pin_state,
            pin_state_tmp,
            adc_diff;

void AdcGo(void);
void AdcDiff(void);
void ChRots(void);
void CheckPinChRots(void);
void CheckChRotsTime(void);
void CheckChRotsTimeSlow(void);

struct {
  unsigned check_pin : 1;
  unsigned check_pertime : 1;
  unsigned check_pertime_slow : 1;
  unsigned lcd_show : 1;
} chrotf;

volatile static struct {
  int check_rots; //таймер подсчета оборотов
  int ch_rots; //таймер вывода значений об/сек
  int ch_rots_slow; //таймер точного вывода значений об/сек
  int lcd_show;
} timer;

void main(void) {

  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  
  
 ////
 //Подготовка портов 13,14
 GPIOA->MODER &= ~(GPIO_MODER_MODER13 | GPIO_MODER_MODER14);
 GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_13 | GPIO_OTYPER_OT_14);
 GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR13 | GPIO_PUPDR_PUPDR14);
 //
 //
  
  
  GPIOB->MODER |= MODER_01(DEBUG_B);
  GPIOA->MODER &= ~MODER_11(PIN_CHROT_A);
  GPIOA->PUPDR |= PUPDR_10(PIN_CHROT_A);
  
  
  
  GPIOA->OSPEEDR |= OSPEEDR_11(PIN_CHROT_A);
  GPIOB->OSPEEDR |= OSPEEDR_11(DEBUG_B);
  
  
//SysTick->VAL
 SysTick_Config(799); //per 100 us
    pwm_tim31();
 usart1_init(833);
 usart1_tx_init();
 usart1_rx_init();
 
 timer.ch_rots_slow = 60000;
 timer.ch_rots = 10000;
 timer.check_rots = 1;
 
  adc_init(); 
  usart1_tx_str("@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
 lcd_init();



 // LCD_WRITE('G', LCD_RSDATA);
 // LCD_WRITE('P', LCD_RSDATA);
 // LCD_WRITE('N', LCD_RSDATA);
 // LCD_WRITE('R', LCD_RSDATA);

 
  //timer_lcd.write = 100;
/*
 while (p++ < 100000);
 p = 0;
 */
   int debug = 0;
  lcd_str(" ", 80);
 timer.lcd_show = 5000;
 while(1) {
  GPIOB->BSRR |= BR(DEBUG_B);
  if (chrotf.check_pin) CheckPinChRots();
  if (chrotf.check_pertime) CheckChRotsTime();
  if (chrotf.check_pertime_slow) CheckChRotsTimeSlow();
  if (adcf.start) adc_select();
  if (adcf.go) AdcGo();
  if (adcf.diff) AdcDiff();
  if (lcd.e) lcd_e();
  if (chrotf.lcd_show) {

    chrotf.lcd_show = 0;
    timer.lcd_show = 1000;
    
    //LCD_WRITE(b00000001, LCD_RSCMD);
    lcd_str("anabot.ru", 0);
    lcd_str("SUPER-SITE ;-)", 40);
    debug++;
    //LCD_WRITE('0'+debug%10, LCD_RSDATA);
  }
 }
}


void SysTick_Handler(void) { 
  
  //Timers
  if (timer.check_rots > 1) timer.check_rots--;
  else if (timer.check_rots == 1) chrotf.check_pin = 1;
  
  if (timer.ch_rots > 1) timer.ch_rots--;
  else if (timer.ch_rots == 1) chrotf.check_pertime = 1;
  
  if (timer.ch_rots_slow > 1) timer.ch_rots_slow--;
  else if (timer.ch_rots_slow == 1) chrotf.check_pertime_slow = 1;
  
  if (timer_adc.start > 1) timer_adc.start--;
  else if (timer_adc.start == 1) adcf.go = 1;
  
  if (timer_adc.diff > 1) timer_adc.diff--;
  else if (timer_adc.diff == 1) adcf.diff = 1;
  
  if (timer_lcd.start  > 1) timer_lcd.start--;
  else if (timer_lcd.start == 1) lcd.e = 1;
  
  if (timer.lcd_show > 1) timer.lcd_show--;
  else if (timer.lcd_show == 1) chrotf.lcd_show = 1;
  //Timers
  
  

}

void ADC1_COMP_IRQHandler() {
  if ((ADC1->ISR & ADC_ISR_ADRDY) == ADC_ISR_ADRDY) {
    ADC1->ISR |= ADC_ISR_ADRDY;
    timer_adc.start = 100;
    timer_adc.diff = 1000;
    adcf.start = 1;
  }
}


void CheckChRotsTimeSlow() {
  chrotf.check_pertime = 0;
  chrotf.check_pertime_slow = 0;
  timer.ch_rots = 0;
  
  timer.ch_rots_slow = 60000; //6 sec
  ch_rots_permin = ch_rots_slow * 10;
  usart1_tx('\r');
  usart1_tx('\n');
  usart_tx_num(ch_rots_permin,4);
  usart1_tx('\r');
  usart1_tx('\n');
  usart1_tx_str("set 6 s: ");
  usart_tx_num(rots_set,4);
  //usart_tx_num(debug,4);
  usart1_tx('\r');
  usart1_tx('\n');
  ch_rots = 0;
  ch_rots_slow = 0;
}

void CheckChRotsTime() {
  chrotf.check_pertime = 0;
  timer.ch_rots = 10000; //1 sec
  ch_rots_permin = ch_rots * 60;
  usart1_tx('\r');
  usart1_tx('\n');
  usart_tx_num(ch_rots_permin,4);
  usart1_tx('\r');
  usart1_tx('\n');
  usart1_tx_str("set 1 s: ");

  usart_tx_num(rots_set,4);
 // usart_tx_num(lcd_ch_sum,4);
  usart1_tx('\r');
  usart1_tx('\n');
  ch_rots = 0;
}

void CheckPinChRots() {
  chrotf.check_pin = 0;
  timer.check_rots = 1;
  
  if ((GPIOA->IDR) & (IDR(PIN_CHROT_A))) {
    pin_state = 1;
    ChRots();
  }
  else {
    pin_state = 0;
    pin_state_tmp = 0;
  }
}

void ChRots() {
  if (pin_state != pin_state_tmp) {
    pin_state_tmp = pin_state;
    ch_rots++;
    ch_rots_slow++;
    GPIOB->BSRR |= BS(DEBUG_B);
  }
}

void AdcGo() {
 adcf.go = 0;
 timer_adc.start = 100; 
 rots_set = getadc();
 rots_set = rots_set / 10;
 rots_set = rots_set * 10;
 if (rots_set > 1999) rots_set = 1999;
 TIM3->CCR1 = rots_set;
}


void AdcDiff() {
 adc_diff = (rots_set_tmp - rots_set);
 if(adc_diff > 50 || adc_diff < -50) {
  usart1_tx('!');
  timer.ch_rots_slow = 60000;
  timer.ch_rots = 10000;
  ch_rots = 0;
  ch_rots_slow = 0;
  rots_set_tmp = rots_set;
 }
}




/*
@ считать обороты+++++++++
@ делать шим
@ показывать обороты
@@ (текущие и реальные)
volatile int pin0_tmp;
volatile int pin0_period;
volatile int rot_ch;
volatule int rot_min_ch;
volatile int ticks;
int rot_min_set;
main() {
 pin0  as read;
}
systick_irq_per_ms( ) {
 rot_min_set = pin_ADC>>1;
 if (( rot_min_set - rot_min_ch) < -10) PWM--;
 if (( rot_min_set - rot_min_ch) > 10) PWM++;
if (PWM>PWM_MAX) PWM=PWM_MAX;
if (PWM<0) PWM=0;
 ticks++;
 if (pin0 != pin0_tmp){
  rot_ch++;
  pin0_tmp = pin0;
 }
 if (ticks == 1000) {
  rot_ch = rot_ch>>1;
  rot_min_ch = rot_ch * 60;
  rot_ch = 0;
  ticks = 0;
 }
 display("rot/min current:"+rot_min_ch,1)
display("rot/min set:"+rot_min_set,2)
}

*/


