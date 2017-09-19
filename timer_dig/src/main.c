#include "stm32f0xx.h"

#define	RESET_ALL	GPIOA->BSRR |= GPIO_BSRR_BR_0 | GPIO_BSRR_BR_1 | GPIO_BSRR_BR_2 | GPIO_BSRR_BR_3 | GPIO_BSRR_BR_4 | GPIO_BSRR_BR_5 | GPIO_BSRR_BR_6 | GPIO_BSRR_BR_7 

#define	NUM1	GPIOA->BSRR |= GPIO_BSRR_BS_5 | GPIO_BSRR_BS_3
#define	NUM2	GPIOA->BSRR |= GPIO_BSRR_BS_7 | GPIO_BSRR_BS_5 | GPIO_BSRR_BS_4 | GPIO_BSRR_BS_0 | GPIO_BSRR_BS_1 
#define	NUM3	GPIOA->BSRR |= GPIO_BSRR_BS_7 | GPIO_BSRR_BS_5 | GPIO_BSRR_BS_4 | GPIO_BSRR_BS_3 | GPIO_BSRR_BS_1
#define	NUM4	GPIOA->BSRR |= GPIO_BSRR_BS_6 | GPIO_BSRR_BS_5 | GPIO_BSRR_BS_5 | GPIO_BSRR_BS_3 | GPIO_BSRR_BS_4
#define	NUM5	GPIOA->BSRR |= GPIO_BSRR_BS_7 | GPIO_BSRR_BS_6 | GPIO_BSRR_BS_4 | GPIO_BSRR_BS_3 | GPIO_BSRR_BS_1
#define	NUM6	GPIOA->BSRR |= GPIO_BSRR_BS_7 | GPIO_BSRR_BS_6 | GPIO_BSRR_BS_4 | GPIO_BSRR_BS_3 | GPIO_BSRR_BS_1 | GPIO_BSRR_BS_0
#define	NUM7	GPIOA->BSRR |= GPIO_BSRR_BS_5 | GPIO_BSRR_BS_3 | GPIO_BSRR_BS_7
#define	NUM8	GPIOA->BSRR |= GPIO_BSRR_BS_7 | GPIO_BSRR_BS_6 | GPIO_BSRR_BS_4 | GPIO_BSRR_BS_3 | GPIO_BSRR_BS_1 | GPIO_BSRR_BS_0 | GPIO_BSRR_BS_5
#define	NUM9	GPIOA->BSRR |= GPIO_BSRR_BS_7 | GPIO_BSRR_BS_6 | GPIO_BSRR_BS_4 | GPIO_BSRR_BS_3 | GPIO_BSRR_BS_1 | GPIO_BSRR_BS_5
#define	NUM0	GPIOA->BSRR |= GPIO_BSRR_BS_7 | GPIO_BSRR_BS_6 | GPIO_BSRR_BS_3 | GPIO_BSRR_BS_1 | GPIO_BSRR_BS_0 | GPIO_BSRR_BS_5

#define DIG1_S GPIOB->BSRR |= GPIO_BSRR_BS_1
#define DIG2_S GPIOF->BSRR |= GPIO_BSRR_BS_0
#define DIG3_S GPIOF->BSRR |= GPIO_BSRR_BS_1
#define DIG_R GPIOB->BSRR |= GPIO_BSRR_BR_1; GPIOF->BSRR |= GPIO_BSRR_BR_0 | GPIO_BSRR_BR_1




void dig_show(int d);
void sleep_ms(int ms);
volatile int z = 0, y = 0, d1=0, d2=0, d3=0, sleep_flag=0;

void TIM1_BRK_UP_TRG_COM_IRQHandler(void) {
  
  TIM1->SR &= ~TIM_SR_UIF;
  
  sleep_flag = 0;
  
  if (y++ == 1001) {
    z++;
    if (z > 999) {z = 0;} 
    d1 = z%10;
    d2 = (z/10)%10;
    d3 = (z/100)%10;
    y = 0;
  }
  
  
}

void main(void)
{
  z = 0;
__enable_irq();

NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);


 RCC->CR &= ~RCC_CR_HSEON;
 
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOFEN | RCC_AHBENR_GPIOBEN;
 RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

 GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 | 
                 GPIO_MODER_MODER3_0 | GPIO_MODER_MODER4_0 | GPIO_MODER_MODER5_0 | 
                 GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0 | GPIO_MODER_MODER9_1;
 GPIOF->OTYPER = 0;
 GPIOF->AFR[0] = 0;
 GPIOF->AFR[1] = 0;
 GPIOF->MODER &= ~GPIO_MODER_MODER0 & ~GPIO_MODER_MODER1;
 GPIOF->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0;
 GPIOB->MODER |= GPIO_MODER_MODER1_0;
 
 //GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;
 GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH1);
 GPIOA->AFR[1] |= 2 << ((9-8)*4);
 TIM1->ARR = 8000;
 //TIM1->PSC = 0;
 TIM1->CR1 |= TIM_CR1_CEN; 
 TIM1->DIER |= TIM_DIER_UIE;


 while(1) {
  

     RESET_ALL;

     
     DIG_R; 
     DIG1_S;
     dig_show(d1);
     sleep_ms(5);
     if (d2 != 0 || d3 != 0) {RESET_ALL; DIG_R; DIG2_S; dig_show(d2); sleep_ms(5);}
     
     if (d3 != 0) {RESET_ALL; DIG_R; DIG3_S; dig_show(d3); sleep_ms(5);}
     



 }
}

void dig_show(int d) {
     if (d == 0) NUM0;
     if (d == 1) NUM1;
     if (d == 2) NUM2;
     if (d == 3) NUM3;
     if (d == 4) NUM4;
     if (d == 5) NUM5;
     if (d == 6) NUM6;
     if (d == 7) NUM7;
     if (d == 8) NUM8;
     if (d == 9) NUM9;
}


void sleep_ms(int ms) {
  for (int i = 0; i < ms; i++) {
    while (sleep_flag);
    sleep_flag = 1;
  }
}