#include "stm32f0xx.h"
#include "def.h"
#include "adc.h"

void adc_init() {
 RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
 RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
 GPIOB->MODER &= ~MODER_11(ADC_PORT_B);
 GPIOB->PUPDR &= ~PUPDR_11(ADC_PORT_B);
 
 if ((ADC1->CR & ADC_CR_ADEN) != 0) {
  ADC1->CR &= (uint32_t)(~ADC_CR_ADEN);
 }
 
 ADC1->IER |= ADC_IER_ADRDYIE;
 NVIC_EnableIRQ(ADC1_COMP_IRQn);
 
 
// ADC1->CR |= ADC_CR_ADCAL;
 //while((ADC1->CR & ADC_CR_ADCAL));
 
 ADC1->CR |= ADC_CR_ADEN;
}


///////
//Ниже нужно будет создать флаг/прерывание для while(ADC1->CR & ADC_CR_ADSTART);
void adc_select() {
  ADC1->CHSELR = ADC_CHSELR_CHSEL0;
  ADC1->CFGR1 &= ~ADC_CFGR1_CONT;
}

int getadc(void) {
   //ADC
   int tmp;
   ADC1->CR |= ADC_CR_ADSTART;
   while(ADC1->CR & ADC_CR_ADSTART);
   tmp = (ADC1->DR & ADC_DR_DATA) >> 1;
   return tmp;
}