#include "stm32f0xx.h"
#include "def.h"
 
#define LED1    1
  
volatile int led, led_ch;
 
void main(void) {
    
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 GPIOA->MODER |= MODER_01(LED1);
 SysTick_Config(7999999); /* (1) */
  
 while (1) {
  if (led == 1) GPIOA->BSRR |= BS(LED1);
  else GPIOA->BSRR |= BR(LED1);
 }
}
 
void SysTick_Handler(void) { /* (2) */
  if (led_ch++ > 10) {
    led ^= 1;
    led_ch = 0;
  }
}