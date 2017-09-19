#include "stm32f0xx.h"

void delay (int a);

void main(void) {

 /* GPIOA Periph clock enable */
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

 /* Configure PA3 and PA4 in output mode */
 GPIOA->MODER |= (GPIO_MODER_MODER3_0 | GPIO_MODER_MODER4_0) ;

 /* push pull mode */
 GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_3 | GPIO_OTYPER_OT_4) ;
 

 while (1) {
  GPIOA->BSRR = GPIO_BSRR_BS_3;
  GPIOA->BSRR = GPIO_BSRR_BR_4;
  delay(1000000);
  GPIOA->BSRR = GPIO_BSRR_BR_3;
  GPIOA->BSRR = GPIO_BSRR_BS_4;
  delay(1000000);
 }

}

void delay (int a) {

 for (int i=0 ; i < a ; i++) {
  asm("nop");
  asm("nop");
  asm("nop");
 }

 return;
}