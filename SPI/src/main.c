/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Заюзан пин отладки PA14 !

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

#include "stm32f0xx.h"
#include "def.h"
#include "lcd.h"
#include "spi.h"


void delay (int a);

void main(void) {
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

 GPIOA->MODER &= ~MODER_11(LCD_E) &~MODER_11(SPI_NSS) &~MODER_11(SPI_SCK) &~MODER_11(SPI_MISO) &~MODER_11(SPI_MOSI) ;
 GPIOA->PUPDR &= ~PUPDR_11(LCD_E) &~MODER_11(SPI_NSS) &~MODER_11(SPI_SCK) &~MODER_11(SPI_MISO) &~MODER_11(SPI_MOSI) ;

 //lcd init
 GPIOA->MODER |= MODER_01(SPI_NSS) | MODER_01(LCD_SH_CP) | MODER_01(LCD_ST_CP) | MODER_01(LCD_DATA) | MODER_01(LCD_RS) | MODER_01(LCD_E);

 RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
 
 //spi_init
 GPIOA->MODER |= MODER_10(SPI_SCK) | MODER_10(SPI_MISO) | MODER_10(SPI_MOSI);

 //speed GPIO SPI
// GPIOA->OSPEEDR |= OSPEEDR_11(SPI_NSS) | OSPEEDR_11(SPI_SCK) | OSPEEDR_11(SPI_MISO) | OSPEEDR_11(SPI_MOSI);
 
//spi config

 SPI1->CR1 |= SPI_CR1_BR;
 SPI1->CR1 &= ~SPI_CR1_CPOL;
 SPI1->CR1 &= ~SPI_CR1_CPHA;
 SPI1->CR1 |= SPI_CR1_SSM;
 SPI1->CR1 |= SPI_CR1_SSI;
 //SPI1->CR1 |= SPI_CR1_RXONLY;
 SPI1->CR1 |= SPI_CR1_MSTR; /* (1) */

 SPI1->CR2 |= SPI_CR2_DS;

 
 SPI1->CR1 |= SPI_CR1_SPE;
 
 


 
 lcd_init();


  //while(!(SPI1->SR & SPI_SR_RXNE)); //Ожидаем окончания приема данных модулем SPI1 (RXNE =1 - приемный буфер содержит данные)
  lcd_num_to_str(SPI1->DR,4,0);//Считываем данные из приемного буфера SPI1. При этой операции происходит очистка буфера и сброс флага RXNE 

  
  lcd_str("SPI start...",60);
unsigned int buf;
int result;
char *zn;
unsigned int bufar[2];
while(1) {

  GPIOA->BSRR |= BS(SPI_NSS);
  for(int j=0;j<100000;j++);
  lcd_str("4lab.su. GPNR!",60);
  GPIOA->BSRR |= BR(SPI_NSS);
  for (int i=0; i<2; i++) {
   SPI1->DR = 0xFFFF; //Пишем в буфер передатчика SPI1. После этого стартует обмен данными
   while(!(SPI1->SR & SPI_SR_RXNE));
   buf = SPI1->DR;
   bufar[i] = buf;
   for(int j=0;j<10000;j++);
  }
 // for (int j = 0; j < 2; j++) {
 //  delay(3000000);
 //  lcd_num_to_str(bufar[j],5,0);
 //  lcd_str(" <-- ",-1);
 //  lcd_num_to_str(j,1,-1);
//
 // }
  
  
  //добавить отриц. темп. работы! 
  /*
  if (bufar[0]>>4 > 4000) {
    lcd_str("-",0);
    bufar[0] = (4096 - (bufar[0]>>4)) >> 2;
    bufar[0] <<= 4;
  }
  else lcd_str("+",0);
  */
  
  if ((bufar[0]>>4) > 4000) 
    result = ((bufar[0]>>4) - 4096 + (bufar[1]>>8));
  else if ((bufar[0]>>4) < 4000)
    result = (bufar[0]>>4) + (bufar[1]>>8);
  if (result >= 0) zn = " ";
  else {
    result = -result;
    zn = "-";
  }
  lcd_str(zn,0);
  lcd_num_to_str(result,4,1);
  //lcd_num_to_str(bufar[1]>>8,5,0); //internal temp
  lcd_str(" GRAD.",-1);

 }
}

void delay (int a) {
 int i,j;
 for (i=0 ; i < a ; i++) {
  j++;
 }
}

