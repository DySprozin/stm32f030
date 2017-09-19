#include "stm32f0xx.h"
#include "spi.h"
#include "def.h"


void spi_init(char nss) {
 RCC->APB2ENR |= RCC_APB2ENR_SPI1EN; 
  GPIOA->MODER &= ~MODER_11(SPI_NSS) &~MODER_11(SPI_SCK) &~MODER_11(SPI_MISO) &~MODER_11(SPI_MOSI) ;
 GPIOA->PUPDR &= ~MODER_11(SPI_NSS) &~MODER_11(SPI_SCK) &~MODER_11(SPI_MISO) &~MODER_11(SPI_MOSI) ;
 
 if (nss == 1) GPIOA->MODER |= MODER_10(SPI_NSS) | MODER_10(SPI_SCK) | MODER_10(SPI_MISO) | MODER_10(SPI_MOSI);
 else GPIOA->MODER |= MODER_10(SPI_SCK) | MODER_10(SPI_MISO) | MODER_10(SPI_MOSI);
 

 
}

void spi_config() {
//spi config

 SPI1->CR1 |= SPI_CR1_BR;
 SPI1->CR1 &= ~SPI_CR1_CPOL;
 SPI1->CR1 &= ~SPI_CR1_CPHA;
 SPI1->CR1 |= SPI_CR1_SSM;
 SPI1->CR1 |= SPI_CR1_SSI;
 //SPI1->CR1 |= SPI_CR1_RXONLY;
 SPI1->CR1 |= SPI_CR1_MSTR; /* (1) */

 SPI1->CR2 |= SPI_CR2_DS;
}

void spi_enable() {
 SPI1->CR1 |= SPI_CR1_SPE; 
}
