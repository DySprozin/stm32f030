#include "stm32f0xx.h"

void delay (int a);
volatile int z = 0, y = 0;

void TIM1_BRK_UP_TRG_COM_IRQHandler(void) {
  
  TIM1->SR &= ~TIM_SR_UIF;
  
  if (y++ == 1001) {z = z ^ 1; y = 0;}
}

void main(void)
{
  z = 0;
__enable_irq();

NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);

 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

 GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER9_1;
 //GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;
 GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH1);
 GPIOA->AFR[1] |= 2 << ((9-8)*4);
 TIM1->ARR = 8000;
 //TIM1->PSC = 0;
 TIM1->CR1 |= TIM_CR1_CEN;
 TIM1->DIER |= TIM_DIER_UIE;
 
 while(1) {
   
 /*  
   for (int i = 0; i < 1000; i++) {
     while(TIM1->CNT > 0);
     //TIM1->CNT = 0;
   }
   
   */

if (z == 1)    GPIOA->BSRR |= GPIO_BSRR_BS_0;
/*   
   for (int i = 0; i < 1000; i++) {
     while(TIM1->CNT > 0);
     //TIM1->CNT = 0;
   }
  */ 
  if (z == 0) GPIOA->BSRR |= GPIO_BSRR_BR_0;
   
  
  if (z > 10) {
    GPIOA->BSRR |= GPIO_BSRR_BS_0;
    while(1);
  }
  // TIM1->CNT = 0;
 }
}

