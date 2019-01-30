#include "stm32f0xx.h"
#include "def.h"

#define I2C_SCL 9
#define I2C_SDA 10

#define TEST 5



void i2c_init(void);

char arr[19] = {0xa8, 0x3f, 0xd3, 0x00, 0x40, 0xA1, 0xC8, 0xDA, 0x12, 0x81, 0xFF, 0xA4, 0xA6, 0xD5, 0x80, 0x8D, 0x14, 0xAF};
int arr_ch;
void main(void) {
  
  
 
  

  i2c_init();
  arr_ch = 0;
  while(1) {
    
if (!(GPIOA->IDR & IDR(TEST))) {
   arr_ch++;
}




//I2C1->CR1 |= I2C_CR1_PE;
    if (arr_ch < 18 && ((I2C1->ISR && I2C_ISR_TXE) == I2C_ISR_TXE)) {
      I2C1->TXDR = arr[arr_ch]; /* Byte to send */
      I2C1->CR2 = I2C_CR2_RELOAD | (1 << 16) | I2C_CR2_START | (0x78 << 1);
      while((I2C1->ISR & I2C_ISR_TXIS) != I2C_ISR_TXIS);
      arr_ch++;
    }
  }
  
}

void i2c_init() {
  
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
  
  
  
  ///////////////////////
 GPIOA->MODER &= ~MODER_11(TEST);
 GPIOA->PUPDR |= PUPDR_01(TEST); 
 ///////////////////////
  
  GPIOA->MODER |= MODER_10(I2C_SCL) | MODER_10(I2C_SDA);

  GPIOA->OTYPER &= ~OTYPER(I2C_SCL)  & ~OTYPER(I2C_SDA); ///////////?????????
  GPIOA->PUPDR &= ~PUPDR_11(I2C_SCL) & ~PUPDR_11(I2C_SDA); 
  GPIOA->PUPDR |= PUPDR_01(I2C_SCL) | PUPDR_01(I2C_SDA); 
  GPIOA->OSPEEDR |= OSPEEDR_11(I2C_SCL) | OSPEEDR_11(I2C_SDA); ///////////?????????

  
  GPIOA->AFR[1] &= ~AFRH(I2C_SCL,) & ~AFRH(I2C_SDA,);
  GPIOA->AFR[1] |= AFRH(I2C_SCL,4) | AFRH(I2C_SDA,4);
  
  
  I2C1->TIMINGR = (uint32_t)0x00201D2B;
  I2C1->CR1 |= I2C_CR1_TXIE;
  I2C1->CR1 |= I2C_CR1_PE;
  


  
}

void I2C1_IRQHandler(void) {
  I2C1->CR1 |= I2C_CR1_PE;
}