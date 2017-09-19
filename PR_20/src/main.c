#include "stm32f0xx.h"
#include "lcd.h"
#include "def.h"

void main() {
   RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
   GPIOA->MODER |= MODER_01(LCD_SH_CP) | MODER_01(LCD_ST_CP) | MODER_01(LCD_DATA) | MODER_01(LCD_RS) | MODER_01(LCD_E);
   
 GPIOA->MODER &= ~MODER_11(ADC_PORT);
 GPIOA->PUPDR &= ~PUPDR_11(ADC_PORT);

 
 //ADC1->CR &= ~ADC_CR_ADEN;
 while((ADC1->CR & ADC_CR_ADEN));

 ADC1->CR |= ADC_CR_ADCAL;
 while((ADC1->CR & ADC_CR_ADCAL));

 ADC1->CR |= ADC_CR_ADEN;
 while((ADC1->ISR & ADC_ISR_ADRDY) == 0);
      lcd_init();
 ADC1->CHSELR = ADC_CHSELR_CHSEL6;
 
 ADC1->CFGR1 &= ~ADC_CFGR1_CONT;
   
   
   lcd_delay(500);

   int ch = 0;
   long int adc_sum = 0;
   long int adc_result = 0;
   while(1) {
   ch++;
    ADC1->CR |= ADC_CR_ADSTART;
    while(ADC1->CR & ADC_CR_ADSTART);
    
    adc_sum += ADC1->DR & ADC_DR_DATA;
    
    if (ch == 127) {
      adc_result = adc_sum >> 7;
      adc_sum = 0;
      ch = 0;
    }
     
  lcd_str("ANABOT", 0);
  lcd_num_to_str(adc_result, 4, 41);
   }
  return;
}