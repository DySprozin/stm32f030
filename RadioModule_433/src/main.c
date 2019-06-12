#include "stm32f0xx.h"
#include "def.h"
#include "uart.h"
#include "flash.h"

volatile uint32_t tim_ch=0;
volatile uint32_t tmp=0;
volatile char signal[2010];
volatile uint16_t flash;

int work = 0;

#define MEM_ADDR      0x8003400


 void main(void) {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 GPIOA->MODER &= ~MODER_11(SENS);
  GPIOA->MODER &= ~MODER_11(LOCK);
 GPIOA->MODER &= ~MODER_11(SIG);
 GPIOA->MODER |= MODER_01(SIG);
   
 GPIOA->PUPDR |= PUPDR_10(SENS);
 GPIOA->PUPDR |= PUPDR_10(LOCK);
   SysTick_Config(8000); /* (1) */

  //usart_init(13333);
  //usart_tx_init();
   
 flash_enable();
 
  if (GPIOA->IDR & IDR(LOCK)) work = 1;
  if (work != 1) {
     flash_erase(MEM_ADDR);
    flash_write_start();
  }
   
  while(1) {
  }
 //
 ////
  
}

void SysTick_Handler(void) {

  if (tim_ch++ > 2000 || work == 1) {
    tim_ch--;
    GPIOA->BSRR |= BS(SIG);
    for(int i = 0; i < 2000; i++) {
     // GPIOA->BSRR |= BS(SIG);
      if ((char)flash_read(MEM_ADDR+4*i) == 0) GPIOA->BSRR |= BR(SIG);
      else GPIOA->BSRR |= BS(SIG);
    }
  }
  else {
    if (work != 1) {
     if (GPIOA->IDR & IDR(SENS)) {
      flash_write(MEM_ADDR+4*tim_ch, 0, 1);
     }
     else {
       flash_write(MEM_ADDR+4*tim_ch, 0, 1);
     }
    }
  }
//usart_tx_str("[ANABOT] ");*/
}