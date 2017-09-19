#include "stm32f0xx.h"

void delay(int);

void main(void)
{
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 | GPIO_MODER_MODER3_0;
  GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0 | GPIO_OSPEEDER_OSPEEDR1 | GPIO_OSPEEDER_OSPEEDR2| GPIO_OSPEEDER_OSPEEDR3;
  
  
  while(1) {
    //PA0 - 1. Blue
    //PA1 - 2. Pink
    //PA2 - 3. Yellow
    //PA3 - 4. Orange


    
  
    GPIOA->BSRR |= GPIO_BSRR_BS_0 | GPIO_BSRR_BR_2;
    delay(2500);
    GPIOA->BSRR |= GPIO_BSRR_BR_0 | GPIO_BSRR_BR_2;
        delay(50);

    GPIOA->BSRR |= GPIO_BSRR_BS_3 | GPIO_BSRR_BR_1;
    delay(2500);
    GPIOA->BSRR |= GPIO_BSRR_BR_3 | GPIO_BSRR_BR_1;
    delay(50);
    GPIOA->BSRR |= GPIO_BSRR_BR_0 | GPIO_BSRR_BS_2;
    delay(2500);
    GPIOA->BSRR |= GPIO_BSRR_BR_0 | GPIO_BSRR_BR_2;
    delay(50);
    GPIOA->BSRR |= GPIO_BSRR_BR_3 | GPIO_BSRR_BS_1;
    delay(2500);
    GPIOA->BSRR |= GPIO_BSRR_BR_3 | GPIO_BSRR_BR_1;
    delay(50);
  }
}

void delay (int a) {

 for (int i=0 ; i < a ; i++) {
  asm("nop");
  asm("nop");
  asm("nop");
 }

 return;
}