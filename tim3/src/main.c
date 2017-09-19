#include "stm32f0xx.h"
#include "def.h"
#include "usart.h"
 
 
void main(void) {
   
 
 /* (1,2) ���������� ���������� GPIOA � TIM3 */
 /* (3,4) ����������� ���� �� AF � �������� �� �������� */
 /* (5) ����������� �������������� ������� ����� */
 /* (6) �� ������� ����� ������ ������ */
 /* (7) ������ �������� */
 /* (8) �� ���������� CCR1 � ������������ � ���� */
 /* (9) ���� � �� �����! */
 /* (10) ��������� ������ */
 /* (11,12,13) ������������� USART, TX, RX */
 /* (14) ���������� ������ RX (������ ����� ��������) � ����� */
 /* (15) ���� ����� �� ����������, ������, ���� */
 /* (16) ������� ���, ��� ��������� � ��������� */
 
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN; /* (1) */
 RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; /* (2) */
  
  
 GPIOA->MODER |= MODER_10(TIM31); /* (3) */
 GPIOA->OSPEEDR |= OSPEEDR_11(TIM31); /* (4) */
 GPIOA->AFR[0] |= AFRL(TIM31,1); /* (5) */
  
 TIM3->PSC = 799;
 TIM3->ARR = 9; /* (6) */
 TIM3->CCR1 = 1; /* (7) */
 TIM3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; /* (8) */
  
 TIM3->CCER |= TIM_CCER_CC1E; /* (9) */
  
 TIM3->CR1 |= TIM_CR1_CEN; /* (10) */
 
 usart1_init(833); /* (11) */
 usart1_tx_init(); /* (12) */
 usart1_rx_init(); /* (13) */
 
 int brg;
 while (1) {
   brg = (rx_buf[0] - '0'); /* (14) */
   if (brg > 10 || brg < 0) brg = 5; /* (15) */
   TIM3->CCR1 = brg; /* (16) */
 }
}