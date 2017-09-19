#include "stm32f0xx.h"
#include "def.h"
#include "uart.h"




void main(void) {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

  
  
  usart_init();

  for (int i = 0; i < 10; i++) {
   usart_tx(i);
  }

  
 //
 ////
  
}