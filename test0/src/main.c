#include "stm32f0xx.h"

void delay (int a);

void main(void) {
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 GPIOA->MODER |= (GPIO_MODER_MODER3_0) ;
 GPIOA->MODER &= ~(GPIO_MODER_MODER4);
 GPIOA->OTYPER &= ~GPIO_OTYPER_OT_3;
 GPIOA->PUPDR |= GPIO_PUPDR_PUPDR4_1;

 for (int i = 0; i < 5; i++) { 
   GPIOA->BSRR |= GPIO_BSRR_BS_3;
   delay(250000);
   GPIOA->BSRR |= GPIO_BSRR_BR_3;
   delay(250000);
 }
 
 delay(500000);
 GPIOA->BSRR |= GPIO_BSRR_BS_3;
 delay(500000);
 RCC->APB1ENR |= RCC_APB1ENR_PWREN;
 SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
 PWR->CR |= PWR_CR_PDDS;
 PWR->CSR |= PWR_CSR_EWUP1;
 PWR->CR |= PWR_CR_CWUF;
 __WFI();
 
 while (1) {
   GPIOA->BSRR |= GPIO_BSRR_BS_3;
   delay(500000);
   GPIOA->BSRR |= GPIO_BSRR_BR_3;
 }


}



void delay (int a) {
 int i,j;
 for (i=0 ; i < a ; i++) {
  j++;
 }
}