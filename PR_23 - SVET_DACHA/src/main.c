#include "stm32f0xx.h"
#include "def.h"
#include "usart.h"

//This project for light on "DACHA"

//Это проект светильника на дачу
 
volatile int led;

void main(void) {
   
 
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN; 
  
 GPIOA->MODER |= MODER_01(MANAGE_LAMP);
 
 SysTick_Config(7999999);
 
 while(1) {
   if (led) GPIOA->BSRR |= BS(MANAGE_LAMP);
   else GPIOA->BSRR |= BR(MANAGE_LAMP);
 }
 
}

void SysTick_Handler(void) {
  led ^= 1;
}