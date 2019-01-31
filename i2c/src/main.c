#include "stm32f0xx.h"
#include "def.h"

#define I2C_SCL 9
#define I2C_SDA 10

#define TEST 5



void i2c_init(void);

char arr[37] = {0x80, 0xa8, 0x80, 0x3f, 0x80, 0xd3, 0x80, 0x00, 0x80, 0x40, 0x80, 0xA1, 0x80, 0xC8, 0x80, 0xDA, 0x80, 0x12, 0x80, 0x81, 0x80, 0xFF, 0x80, 0xA4, 0x80, 0xA6, 0x80, 0xD5, 0x80, 0x80, 0x80, 0x8D, 0x80, 0x14, 0x80, 0xAF};
int arr_ch;
void main(void) {
  
  
 
  

  i2c_init();
  I2C1->CR2 |= I2C_CR2_START;
      
  arr_ch = 0;
  while(1) {
    




//I2C1->CR1 |= I2C_CR1_PE;

    if (arr_ch < 36 && ((I2C1->ISR && I2C_ISR_TXE) == I2C_ISR_TXE)) {
      while((I2C1->ISR & I2C_ISR_TXIS) != I2C_ISR_TXIS);
      I2C1->TXDR = arr[arr_ch]; 

//      while((I2C1->ISR & I2C_ISR_TXIS) != I2C_ISR_TXIS);



      arr_ch++;
    }
  }
  
}

void i2c_init() {
  
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
  
  
  
  ///////////////////////
 GPIOA->MODER |= MODER_01(TEST);
 ///////////////////////
  
  GPIOA->MODER |= MODER_10(I2C_SCL) | MODER_10(I2C_SDA);

  GPIOA->PUPDR &= ~PUPDR_11(I2C_SCL) & ~PUPDR_11(I2C_SDA); 
  GPIOA->PUPDR |= PUPDR_01(I2C_SCL) | PUPDR_01(I2C_SDA); 

  
  GPIOA->AFR[1] &= ~AFRH(I2C_SCL,) & ~AFRH(I2C_SDA,);
  GPIOA->AFR[1] |= AFRH(I2C_SCL,4) | AFRH(I2C_SDA,4);
  
  NVIC_EnableIRQ(I2C1_IRQn);
  
  I2C1->CR1 |= I2C_CR1_STOPIE;
  I2C1->CR1 |= I2C_CR1_NACKIE;
  I2C1->CR1 |= I2C_CR1_TCIE;

  
  I2C1->TIMINGR = (uint32_t)0x00201D2B;
  I2C1->CR1 |= I2C_CR1_PE;
  I2C1->CR2 = I2C_CR2_AUTOEND | (36 << 16) | (0x3C << 1);
  
}

void I2C1_IRQHandler(void) {
  I2C1->ICR |= I2C_ICR_STOPCF;
  GPIOA->BSRR |= BS(TEST);
  
}