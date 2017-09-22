#include "stm32f0xx.h"
#include "def.h"
#include "tim3.h"
#include "usart.h"

void pwm_tim31() {
  
 
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
  
 GPIOA->MODER |= MODER_10(TIM31);
 GPIOA->OSPEEDR |= OSPEEDR_11(TIM31);
 GPIOA->AFR[0] |= AFRL(TIM31,1);
 
 TIM3->PSC = TIM3_PSC; //prescaler
 TIM3->ARR = TIM3_ARR; //upcount
 TIM3->CCR1 = TIM3_CCR1; //count to reset level
 TIM3->CCMR1 |= H_BEFORE_CCR1; //reset hight to low after reach CCR1
  
 TIM3->CCER |= TIM_CCER_CC1E;
  
 TIM3->CR1 |= TIM_CR1_CEN;
 
}

