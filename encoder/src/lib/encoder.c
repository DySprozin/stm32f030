#include "stm32f0xx.h"
#include "def.h"
#include "encoder.h"

void encoder_init() {

 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
  
 /* (1-3) Настройка каналов CH1,CH2 таймера TIM3 в режим AF1 на максимальной скорости */
 /* (4) Максимальное значение таймера */
 /* (5) Настраиваем каналы 1,2 на вход */
 /* (6) Настройка триггеров в режим энкодера */
  
 GPIOA->MODER |= MODER_10(TIM31) | MODER_10(TIM32); /* (1) */
 GPIOA->OSPEEDR |= OSPEEDR_11(TIM31) | OSPEEDR_11(TIM32) ; /* (2) */
 GPIOA->AFR[0] |= AFRL(TIM31,1) | AFRL(TIM32,1); /* (3) */
  
 TIM3->ARR = -1; /* (4) */
 
 TIM3->CCMR1 |= TIM_CCMR1_CC2S_0 | TIM_CCMR1_CC1S_0; /* (5) */
 
 TIM3->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1; /* (6) */
  
 TIM3->CR1 |= TIM_CR1_CEN;
}

int encoder() {
  return TIM3->CNT;
}

void encoder_set(int set) {
  TIM3->CNT = set;
}