#include "stm32f0xx.h"
#include "def.h"
#include "usart.h"

volatile int ccr1, ccr2, over;

void main(void) {
  

 /* (1,2) Подключаем тактование GPIOA и TIM3 */
 /* (3,4) Настраиваем порт на AF и скорость на максимум */
 /* (5) Настраиваем альтернативную функцию порта */
 /* (6) До скольки будет таймер тикать */
 /* (7) Ширина импульса */
 /* (8) По достижению CCR1 — сбрасываться в ноль */
 /* (9) Порт — на выход! */
 /* (10) Запустить таймер */
 /* (11,12,13) Инициализация USART, TX, RX */
 /* (14) Превратить символ RX (пришел через терминал) в число */
 /* (15) Если число не получилось, значит, ноль */
 /* (16) Светить так, как приказано в терминале */

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

