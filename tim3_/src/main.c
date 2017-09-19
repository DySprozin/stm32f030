#include "stm32f0xx.h"
#include "def.h"
#include "usart.h"

volatile int ccr1, ccr2, over;

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
 
 
 GPIOA->MODER |= MODER_10(TIM31) | MODER_10(TIM32); /* (3) */
 GPIOA->OSPEEDR |= OSPEEDR_11(TIM31) | OSPEEDR_11(TIM32) ; /* (4) */
 GPIOA->AFR[0] |= AFRL(TIM31,1) | AFRL(TIM32,1); /* (5) */
 
 TIM3->PSC = 79;
 
 TIM3->ARR = 1000;

 TIM3->CCMR1 |= TIM_CCMR1_CC2S_0 | TIM_CCMR1_CC1S_0;

 TIM3->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;
 
 TIM3->CR1 |= TIM_CR1_CEN; /* (10) */

 usart1_init(833); /* (11) */
 usart1_tx_init(); /* (12) */
 usart1_rx_init(); /* (13) */

 int tmp;
 TIM3->CNT = 100;
 while (1) {
    if (TIM3->CNT != tmp) {usart1_tx(TIM3->CNT); tmp = TIM3->CNT;}
    if (TIM3->CNT > 150) {TIM3->CNT = 100; tmp = TIM3->CNT;}
    if (TIM3->CNT < 50) {TIM3->CNT = 100; tmp = TIM3->CNT;}
    
 }
}

