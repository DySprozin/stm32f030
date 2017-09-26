#include "stm32f0xx.h"
#include "def.h"
#include "tim3.h"
#include "usart.h"
#include "adc.h"
 
#define DEBUG_A          0
#define PIN_CHROT_A       4

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
} chrotf;

volatile static struct {
  int check_rots; //таймер подсчета оборотов
  int ch_rots; //таймер вывода значений об/сек
  int ch_rots_slow; //таймер точного вывода значений об/сек
  int adc_start;
  int adc_diff;
} timer;

void main(void) {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  GPIOA->MODER |= MODER_01(DEBUG_A);
  GPIOA->MODER &= ~MODER_11(PIN_CHROT_A);
  GPIOA->PUPDR |= PUPDR_10(PIN_CHROT_A);
  
  
  GPIOA->OSPEEDR |= OSPEEDR_11(DEBUG_A) | OSPEEDR_11(PIN_CHROT_A);
  
  
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
 
 while(1) {
  GPIOA->BSRR |= BR(DEBUG_A);
  if (chrotf.check_pin) CheckPinChRots();
  if (chrotf.check_pertime) CheckChRotsTime();
  if (chrotf.check_pertime_slow) CheckChRotsTimeSlow();
  if (adcf.start) adc_select();
  if (adcf.go) AdcGo();
  if (adcf.diff) AdcDiff();
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
  
  if (timer.adc_start > 1) timer.adc_start--;
  else if (timer.adc_start == 1) adcf.go = 1;
  
  if (timer.adc_diff > 1) timer.adc_diff--;
  else if (timer.adc_diff == 1) adcf.diff = 1;
  //Timers
  
  

}

void ADC1_COMP_IRQHandler() {
  if ((ADC1->ISR & ADC_ISR_ADRDY) == ADC_ISR_ADRDY) {
    ADC1->ISR |= ADC_ISR_ADRDY;
    timer.adc_start = 100;
    timer.adc_diff = 1000;
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
  usart_tx_num(rots_set,4);
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
  usart_tx_num(rots_set,4);
  usart1_tx('\r');
  usart1_tx('\n');
  usart_tx_num(ch_rots_permin,4);
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
    GPIOA->BSRR |= BS(DEBUG_A);
  }
}

void AdcGo() {
 adcf.go = 0;
 timer.adc_start = 100; 
 rots_set = getadc();
 rots_set = rots_set / 10;
 rots_set = rots_set * 10;
 if (rots_set > 1999) rots_set = 1999;
 TIM3->CCR1 = rots_set;
}


void AdcDiff() {
 adc_diff = (rots_set_tmp - rots_set);
 if(adc_diff > 10 || adc_diff < -10) {
  usart1_tx('!');
  timer.ch_rots_slow = 60000;
  timer.ch_rots = 10000;
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


