#include "stm32f0xx.h"
#include "def.h"
#include "uart.h"

void delay (int a);
int getadc(void);

void main(void) {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
  
  //ADC
  RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
  GPIOA->MODER &= ~MODER_11(ADC_PORT);
  GPIOA->PUPDR &= ~PUPDR_11(ADC_PORT);
  while((ADC1->CR & ADC_CR_ADEN));
  ADC1->CR |= ADC_CR_ADCAL;
  while((ADC1->CR & ADC_CR_ADCAL));
  ADC1->CR |= ADC_CR_ADEN;
  while((ADC1->ISR & ADC_ISR_ADRDY) == 0);
  ADC1->CHSELR |= ADC_CHSELR_CHSEL0;
  ADC1->CFGR1 &= ~ADC_CFGR1_CONT;
  
  GPIOA->MODER |= MODER_10(UART_RX) | MODER_10(UART_TX);
  GPIOB->MODER |= MODER_01(SW_PORT);
  GPIOB->PUPDR &= ~PUPDR_01(SW_PORT);
  GPIOB->OTYPER &= ~OTYPER(SW_PORT);
  
  usart_init();
  int tmp;
  for (int i = 0; i < 10; i++) {
   usart_tx(i);
  }
  
  int sw_flag = 0;
  
  while(1) {
    
   tmp = getadc();
   
   usart_tx(tmp);
   
   if (tmp < 100) {
     delay(666666);
     tmp = getadc();
     if (tmp < 100) {
      sw_flag = 1;
      GPIOB->BSRR |= BS(SW_PORT);
     }
   }
   else {
     if (sw_flag == 1) {
      delay(300000);
      sw_flag = 0;
     }
     GPIOB->BSRR |= BR(SW_PORT);
   }
   delay(50000);
  }
}

void delay (int a) {

volatile int i,j;

for (i=0 ; i < a ; i++) {
 j++;
}

return;
}

int getadc(void) {
   //ADC
   int tmp;
   ADC1->CR |= ADC_CR_ADSTART;
   while(ADC1->CR & ADC_CR_ADSTART);
   tmp = (ADC1->DR & ADC_DR_DATA) >> 4;
   return tmp;
}