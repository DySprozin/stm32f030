#include "stm32f0xx.h"
#include "def.h"
#include "lcd.h"

void delay (int a);

void main(void) {
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
 RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
 GPIOA->MODER |= MODER_01(LCD_SH_CP) | MODER_01(LCD_ST_CP) | MODER_01(LCD_DATA) | MODER_01(LCD_RS) | MODER_01(LCD_E);
 GPIOB->MODER &= ~MODER_11(ADC_PORT);
 GPIOB->PUPDR &= ~PUPDR_11(ADC_PORT);
 lcd_init();
 
 //ADC1->CR &= ~ADC_CR_ADEN;
 while((ADC1->CR & ADC_CR_ADEN));
 ADC1->CR |= ADC_CR_ADCAL;
 while((ADC1->CR & ADC_CR_ADCAL));
 
 ADC1->CR |= ADC_CR_ADEN;
 while((ADC1->ISR & ADC_ISR_ADRDY) == 0);
 
 ADC1->CHSELR |= ADC_CHSELR_CHSEL9;
 
 ADC1->CFGR1 &= ~ADC_CFGR1_CONT;
int pot = 0;
int adc = 0;
int adc_tmp = 0;
int adc_arr[100];
int adc_min;
 while(1) {

   adc_min = 10000;
   for (int j = 0; j < 50; j++) {
   for (int k = 0; k < 100; k++) {

    ADC1->CR |= ADC_CR_ADSTART;
    while(ADC1->CR & ADC_CR_ADSTART);
    
    adc_arr[k] = ADC1->DR & ADC_DR_DATA;

     
   }


   for (int i = 0; i < 100; i++) {
     if (adc_arr[i] < adc_min) adc_min = adc_arr[i];
   }
   }
   adc = adc_min;

    //фильтр нижних частот
 //   pot = (double)(0.99*pot) + (double)(0.01*(double)adc);
 //   if (adc_tmp != (int)pot) {
 //    adc_tmp = (int)pot;
 //    continue;
 //   }
     adc_tmp = adc_min;
    
if (adc_tmp >= 3295) pot = 0;
if (adc_tmp < 3295) pot = 0;
if (adc_tmp < 3293) pot = 10;
if (adc_tmp < 3280) pot = 20;
if (adc_tmp < 3260) pot = 30;
if (adc_tmp < 3240) pot = 40;
if (adc_tmp < 3200) pot = 50;
if (adc_tmp < 3180) pot = 60;
if (adc_tmp < 3150) pot = 70;
if (adc_tmp < 3120) pot = 80;
if (adc_tmp < 3080) pot = 90;
if (adc_tmp < 3050) pot = 100;
if (adc_tmp < 3020) pot = 110;
if (adc_tmp < 2980) pot = 120;
if (adc_tmp < 2950) pot = 130;
if (adc_tmp < 2900) pot = 140;
if (adc_tmp < 2875) pot = 150;
if (adc_tmp < 2850) pot = 160;
if (adc_tmp < 2810) pot = 170;
if (adc_tmp < 2780) pot = 180;
if (adc_tmp < 2750) pot = 190;
if (adc_tmp < 2710) pot = 200;
if (adc_tmp < 2680) pot = 210;
if (adc_tmp < 2640) pot = 220;
if (adc_tmp < 2610) pot = 230;
if (adc_tmp < 2580) pot = 240;
   //delay(50000);
   lcd_str("www.lab.su<-COOL!", 0);
   lcd_num_to_str (pot, 4, 41);
   lcd_str(" V ", -1);
   //lcd_num_to_str (adc_tmp, 4, -1);
 }
 
}

void delay (int a) {
 int i,j;
 for (i=0 ; i < a ; i++) {
  j++;
 }
}