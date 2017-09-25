#include "stm32f0xx.h"
#include "def.h"
#include "tim3.h"
#include "usart.h"
#include "adc.h"
 
#define DEBUG_A          0
#define PIN_CHROT_A       4

volatile int ch_rots, ch_rots_slow, ch_rots_permin;

void ChRots(void);
void CheckPinChRots(void);
void CheckChRotsTime(void);
void CheckChRotsTimeSlow(void);

struct {
  unsigned pin_chrot : 1;
  unsigned pin_chrot_tmp : 1;
  unsigned pin_check_rots : 1;
  unsigned check_rots_time : 1;
  unsigned check_rots_time_slow : 1;
  
  unsigned adc_ready : 1;
} fl;

volatile static struct {
  int check_rots; //таймер подсчета оборотов
  int ch_rots; //таймер вывода значений об/сек
  int ch_rots_slow; //таймер точного вывода значений об/сек
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
  if (fl.pin_chrot) ChRots();
  if (fl.pin_check_rots) CheckPinChRots();
  if (fl.check_rots_time) CheckChRotsTime();
  if (fl.check_rots_time_slow) CheckChRotsTimeSlow();
  if (fl.adc_ready) ////////////////////////////////////////////////
 }
}


void SysTick_Handler(void) { 
  
  //Timers
  if (timer.check_rots > 1) timer.check_rots--;
  else if (timer.check_rots == 1) fl.pin_check_rots = 1;
  
  if (timer.ch_rots > 1) timer.ch_rots--;
  else if (timer.ch_rots == 1) fl.check_rots_time = 1;
  
  if (timer.ch_rots_slow > 1) timer.ch_rots_slow--;
  else if (timer.ch_rots_slow == 1) fl.check_rots_time_slow = 1;
  //Timers
  
  

}

void ADC1_COMP_IRQHandler() {
  if ((ADC1->ISR & ADC_ISR_ADRDY) == ADC_ISR_ADRDY) {
    ADC1->ISR |= ADC_ISR_ADRDY;
    usart1_tx_str("\r\nok\r\n");
  }
}


void CheckChRotsTimeSlow() {
  fl.check_rots_time = 0;
  fl.check_rots_time_slow = 0;
  timer.ch_rots = 0;
  
  timer.ch_rots_slow = 60000; //6 sec
  ch_rots_permin = ch_rots_slow * 10;
  usart_tx_num(ch_rots_permin,4);
  usart1_tx('\r');
  usart1_tx('\n');
  ch_rots = 0;
  ch_rots_slow = 0;
}

void CheckChRotsTime() {
  fl.check_rots_time = 0;
  timer.ch_rots = 10000; //1 sec
  ch_rots_permin = ch_rots * 60;
  usart_tx_num(ch_rots_permin,4);
  usart1_tx('\r');
  usart1_tx('\n');
  ch_rots = 0;
}

void CheckPinChRots() {
  fl.pin_check_rots = 0;
  timer.check_rots = 1;
  
  if ((GPIOA->IDR) & (IDR(PIN_CHROT_A))) {
    fl.pin_chrot = 1;
  }
  else {
    fl.pin_chrot = 0;
    fl.pin_chrot_tmp = 0;
  }
}

void ChRots(void) {
  if (fl.pin_chrot != fl.pin_chrot_tmp) {
    fl.pin_chrot_tmp = fl.pin_chrot;
    ch_rots++;
    ch_rots_slow++;
    GPIOA->BSRR |= BS(DEBUG_A);
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


