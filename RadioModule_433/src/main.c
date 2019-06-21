#include "stm32f0xx.h"
#include "def.h"
#include "uart.h"
#include "flash.h"

volatile uint32_t tim_ch=0, byte_ch = 0;
volatile uint32_t tmp=0;
volatile uint16_t flash, for_chi=0, for_chj=0;
volatile char bytes[2];

int work = 0;

#define MEM_ADDR      0x8001400


 void main(void) {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 GPIOA->MODER &= ~MODER_11(SENS);
  GPIOA->MODER &= ~MODER_11(LOCK);
 GPIOA->MODER &= ~MODER_11(SIG);
 GPIOA->MODER |= MODER_01(SIG);
 GPIOA->PUPDR |= PUPDR_10(SENS);
 GPIOA->PUPDR |= PUPDR_10(LOCK);

  //usart_init(13333);
  //usart_tx_init();
   
 flash_enable();
 
  if (GPIOA->IDR & IDR(LOCK)) work = 1;
  if (work != 1) {
    for (int i=0; i<10; i++) {
     flash_erase(MEM_ADDR+1024*i);
    }
    flash_write_start();
  }
   
  
   SysTick_Config(8000); /* (1) */
  while(1) {
  }
 //
 ////
  
}

void SysTick_Handler(void) {

  if (tim_ch++ > 10000 || work == 1) {//////////////
    tim_ch--;
    //GPIOA->BSRR |= BS(SIG);
    for_chi++;
    for_chj++;
     // GPIOA->BSRR |= BS(SIG);
    if ((for_chj) == 1) {
      if ((flash_read(MEM_ADDR+4*(for_chi >> 2)) & 0x000000FF) == 0) GPIOA->BSRR |= BR(SIG);
      else GPIOA->BSRR |= BS(SIG);
    }
    if ((for_chj) == 2) {
      if (((flash_read(MEM_ADDR+4*(for_chi >> 2)) & 0x0000FF00) >> 8) == 0) GPIOA->BSRR |= BR(SIG);
      else GPIOA->BSRR |= BS(SIG);
    }
    if ((for_chj) == 3) {
      if (((flash_read(MEM_ADDR+4*(for_chi >> 2)) & 0x00FF0000) >> 16) == 0) GPIOA->BSRR |= BR(SIG);
      else GPIOA->BSRR |= BS(SIG);
    }
    if ((for_chj) == 4) {
      if (((flash_read(MEM_ADDR+4*(for_chi >> 2)) & 0xFF000000) >> 24) == 0) GPIOA->BSRR |= BR(SIG);
      else GPIOA->BSRR |= BS(SIG);
    }

     if (for_chi == 10000) for_chi = 0;
     if ((for_chj) == 4) for_chj = 0;
  }
  else {
    if (work != 1) {
     byte_ch++;
     if (GPIOA->IDR & IDR(SENS)) {
      bytes[byte_ch] = 1;
     }
     else {
      bytes[byte_ch] = 0;
     }
     if (byte_ch == 2) {
      flash_write((MEM_ADDR+2*(tim_ch>>1)), bytes[0], bytes[1]);
      byte_ch = 0;
     }
    }
  }
//usart_tx_str("[ANABOT] ");*/
}