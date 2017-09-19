#include "stm32f0xx.h"
#include "def.h"
#include "uart.h"


void usart_init(void) {
//init brr=4800
RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
  
  GPIOA->MODER |= MODER_10(UART_RX) | MODER_10(UART_TX);
  GPIOA->PUPDR &= ~PUPDR_11(UART_RX);
  GPIOA->PUPDR &= ~PUPDR_11(UART_TX);
  GPIOA->OTYPER &= ~OTYPER(UART_RX);
  GPIOA->OTYPER &= ~OTYPER(UART_TX);
  //GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;
  GPIOA->AFR[1]    |= 0x0110;
  
 ////
 //TX
  USART1->CR1 &= ~USART_CR1_M;
  USART1->BRR = 0x681;
  USART1->CR2 &= ~USART_CR2_STOP;
  USART1->CR1 |= USART_CR1_UE;
  USART1->CR1 |= USART_CR1_TE;
}

void usart_tx(int a) {
  while((USART1->ISR & USART_ISR_TC) != USART_ISR_TC);
  USART1->TDR = a  & (uint16_t)0x01FF;
}