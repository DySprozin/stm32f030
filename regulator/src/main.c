#include "stm32f0xx.h"
#include "def.h"
#include "display_seg.h"

void delay (int a);

void init();

void main(void) {
  
init();

 
 SEG_R;


 int tmp = 0;
 int tmp2 = 0;
 ADC_SEL_V;
 ADC->CCR |= ADC_CCR_TSEN;
 
 int adc = 0;
 int adc_tmp = 0;
 int adc_arr[100];
 int adc_min = 10000;
 int temp = 0;
 int pot_vi;
 int pot_temp;
 while(1) {

  seg_num(adc);
   
  
  for (int k = 0; k < 100; k++) {
   ADC1->CR |= ADC_CR_ADSTART;
   while(ADC1->CR & ADC_CR_ADSTART);
   adc_arr[k] = ADC1->DR & ADC_DR_DATA;
  }
  
  
  for (int i = 0; i < 100; i++) {
    if (adc_arr[i] < adc_min) adc_min = adc_arr[i];
  }
  
    //фильтр нижних частот
   pot_vi = (double)(0.99*pot_vi) + (double)(0.01*(double)adc_min);
   pot_temp = (double)(0.99*pot_temp) + (double)(0.01*(double)adc_min);

  
  
  if (tmp2++ > 500) {
   tmp2 = 0;
    
   if (temp == 0) {
    if (pot_vi < 3018) adc = 30;
    if (pot_vi < 3005) adc = 40;
    if (pot_vi < 2980) adc = 50;
    if (pot_vi < 3940) adc = 60;
    if (pot_vi < 2900) adc = 70;
    if (pot_vi < 2860) adc = 80;
    if (pot_vi < 2820) adc = 90;
    if (pot_vi < 2780) adc = 100;
    if (pot_vi < 2740) adc = 110;
    if (pot_vi < 2700) adc = 120;
    if (pot_vi < 2660) adc = 130;
    if (pot_vi < 2620) adc = 140;////
    if (pot_vi < 2580) adc = 150;
    if (pot_vi < 2540) adc = 160;
    if (pot_vi < 2460) adc = 170;
    if (pot_vi < 2420) adc = 180;
    if (pot_vi < 2380) adc = 190;
    if (pot_vi < 2340) adc = 200;
    if (pot_vi < 2300) adc = 210;
    if (pot_vi < 2260) adc = 220;
    if (pot_vi < 2220) adc = 230;
    if (pot_vi < 2170) adc = -1;
    temp = 1;
    ADC_SEL_TEMP;
    //adc = pot_vi%1000;  
   }
   else {
     ADC_SEL_V;
     adc = pot_temp >> 2;
     temp = 0;
   }
    adc_min = 10000;
  }  
 }
 
}

void delay (int a) {
 int i,j;
 for (i=0 ; i < a ; i++) {
  j++;
 }
}

void init() {
 GPIOF->PUPDR = 0;
 GPIOA->PUPDR = 0;
 
 RCC->CR &= ~RCC_CR_HSEON;  
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->AHBENR |= RCC_AHBENR_GPIOFEN;
 RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
 RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
  
 GPIOF->OTYPER = 0;
 GPIOF->AFR[0] = 0;
 GPIOF->AFR[1] = 0;
 GPIOF->MODER &= ~GPIO_MODER_MODER0 & ~GPIO_MODER_MODER1;
 GPIOF->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0;
 
 GPIOA->MODER &= ~GPIO_MODER_MODER13 & ~GPIO_MODER_MODER14;
 
 
 GPIOA->OTYPER = 0;

 

 
 GPIOF->OTYPER |= OTYPER(SEG1) | OTYPER(SEG2);
 GPIOA->OTYPER |= OTYPER(SEG3);
 

 
 GPIOA->MODER |= MODER_01(SEG_A) |
                 MODER_01(SEG_B) |
                 MODER_01(SEG_C) |
                 MODER_01(SEG_D) |
                 MODER_01(SEG_E) |
                 MODER_01(SEG_F) |
                 MODER_01(SEG_G) |
                 MODER_01(SEG3);
         
 GPIOB->MODER |= MODER_01(1);
 


//ADC
//
 while((ADC1->CR & ADC_CR_ADEN));
 ADC1->CR |= ADC_CR_ADCAL;
 while((ADC1->CR & ADC_CR_ADCAL));
 
 ADC1->CR |= ADC_CR_ADEN;

 while((ADC1->ISR & ADC_ISR_ADRDY) == 0);
 
 ADC1->CFGR1 &= ~ADC_CFGR1_CONT;
 
 GPIOB->MODER &= ~MODER_11(ADC_PORT_V);
 GPIOB->PUPDR &= ~PUPDR_11(ADC_PORT_V);

 GPIOA->MODER &= ~MODER_11(ADC_PORT_I);
 GPIOA->PUPDR &= ~PUPDR_11(ADC_PORT_I);
 

 
//
////
 
}