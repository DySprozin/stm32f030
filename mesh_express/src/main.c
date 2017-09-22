#include "stm32f0xx.h"
#include "def.h"
#include "tim3.h"
#include "usart.h"
 


volatile long ch=0;

void main(void) {
//SysTick->VAL
 SysTick_Config(79);
    pwm_tim31();
 usart1_init(833);
 usart1_tx_init();
 usart1_rx_init();
 
 while(1);
}


void SysTick_Handler(void) {
  (long)ch++;
  if ((long)ch > 100000) {
    usart1_tx('!');
    ch = 0;
  }
}












/*
@ считать обороты
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