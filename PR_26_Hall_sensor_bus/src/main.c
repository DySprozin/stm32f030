#include "stm32f0xx.h"
#include "def.h"
#include "flash.h"



#define CHECK(SENS_NUM) \
     if ((GPIOA->IDR & IDR(TEMPF(SENS,SENS_NUM,)))) { \
       flag[SENS_NUM] = 1; \
     } \
     else if (!(GPIOA->IDR & IDR(TEMPF(SENS,SENS_NUM,))) && flag[SENS_NUM] == 1) { \
       rots[SENS_NUM]++; \
       flag[SENS_NUM] = 0; \
     }

#define ROT_WRITE(SENS_NUM) \
     tmp = MEM_ADDR+1024*SENS_NUM+nbytes; \
     flash_write_int32(tmp, rots[SENS_NUM]); \
     rots[SENS_NUM] = 0;


volatile uint32_t tim_ch=0, nbytes=0, flag[8]={0,0,0,0,0,0,0,0}, rots[8]={0,0,0,0,0,0,0,0};


int work = 0;

#define MEM_ADDR      0x8001400

 void main(void) {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  GPIOA->MODER &= (~MODER_11(SENS0) |
                   ~MODER_11(SENS1) |
                   ~MODER_11(SENS2) |
                   ~MODER_11(SENS3) |
                   ~MODER_11(SENS4) |
                   ~MODER_11(SENS5) |
                   ~MODER_11(SENS6) |
                   ~MODER_11(SENS7));

  GPIOA->PUPDR |= PUPDR_10(SENS0) | //PULL DOWN
                 PUPDR_10(SENS1) |
                 PUPDR_10(SENS2) |
                 PUPDR_10(SENS3) |
                 PUPDR_10(SENS4) |
                 PUPDR_10(SENS5) |
                 PUPDR_10(SENS6) |
                 PUPDR_10(SENS7);
                   


 flash_enable();
 
  if ((GPIOA->IDR & IDR(SENS0)) &&
      (GPIOA->IDR & IDR(SENS1)) &&
      (GPIOA->IDR & IDR(SENS2)) &&
      (GPIOA->IDR & IDR(SENS3)) &&
      (GPIOA->IDR & IDR(SENS4)) &&
      (GPIOA->IDR & IDR(SENS5)) &&
      (GPIOA->IDR & IDR(SENS6)) &&
      (GPIOA->IDR & IDR(SENS7)) ) work = 1;
  
  
  if (work == 1) {
    for (int i=0; i<10; i++) {
     flash_erase(MEM_ADDR+1024*i);
    }
    flash_write_start();
  }
   

  SysTick_Config(7999999); /* (1) */
  
  
  while(1) {
   CHECK(0)
   CHECK(1)
   CHECK(2)
   CHECK(3)
   CHECK(4)
   CHECK(5)
   CHECK(6)
   CHECK(7)
  }
 //
 ////
  
}

void SysTick_Handler(void) {
  if (tim_ch++ > 3600) {//////////////
    int tmp;

    ROT_WRITE(0)
    ROT_WRITE(1)
    ROT_WRITE(2)
    ROT_WRITE(3)
    ROT_WRITE(4)
    ROT_WRITE(5)
    ROT_WRITE(6)
    ROT_WRITE(7)

    tim_ch=0;
    nbytes += 4;
  }
}