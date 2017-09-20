#include "stm32f0xx.h"
#include "def.h"
#include "usart.h"

void pwm_tim3_init() {
#define TIM31      6
  
 GPIOA->MODER |= MODER_10(TIM31);
 GPIOA->OSPEEDR |= OSPEEDR_11(TIM31);
 GPIOA->AFR[0] |= AFRL(TIM31,1);
}