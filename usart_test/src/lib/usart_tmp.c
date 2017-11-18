#include "stm32f0xx.h"
#include "def.h"
#include "usart.h"
#include "string.h"

volatile char rx_buf[RX_BUF_SIZE];
volatile char rx_ch;



void USART1_IRQHandler(void) {
  char byte;
  if ((USART1->ISR & USART_ISR_RXNE) == USART_ISR_RXNE) {
   byte = (uint8_t)USART1->RDR;

   if (byte == STOP_SYM) {
     memset((void *)&rx_buf[0], '\0', sizeof(rx_buf));
     rx_ch = 0;
     return;
   }
   
   rx_buf[rx_ch] = byte;
   
   rx_ch++;
  }
  return;
}


void usart1_init(int usartdiv) {
  
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
  
  GPIOA->MODER |= MODER_10(TX_PORT) | MODER_10(RX_PORT);
  GPIOA->OTYPER &= ~OTYPER(TX_PORT) & ~OTYPER(RX_PORT);
  GPIOA->OSPEEDR |= OSPEEDR_11(TX_PORT) | OSPEEDR_11(RX_PORT);
  GPIOA->PUPDR &= ~PUPDR_11(TX_PORT) & ~PUPDR_11(RX_PORT);
  
  //GPIOA->AFR[1] = 1 << ((9-8) * 4) | 1 << ((10-8) * 4);
  GPIOA->AFR[1] |= AFRH(TX_PORT,1) | AFRH(RX_PORT,1);
  int wlen = WORDLEN; 
  int divspeed = DIVSPEED; 
  double sbit = STOP_BIT;
  
  int brr;
  
  if (wlen == 8) USART1->CR1 &= ~USART_CR1_M;
  else USART1->CR1 |= USART_CR1_M;
  
  if (divspeed == 16) {
    brr = usartdiv;
    USART1->CR1 &= ~USART_CR1_OVER8;
    USART1->BRR = brr;
  }
  else {
    usartdiv = usartdiv*2;
    brr = usartdiv;
    brr = brr & USART_BRR_DIV_FRACTION; //4 последних бита usartdiv
    brr = brr << 1; //сдвигаем влево
    brr = brr & USART_BRR_DIV_FRACTION; //4 последних бита usartdiv
    brr = brr | (usartdiv & USART_BRR_DIV_MANTISSA); //результат складываем с остальной частью usartdiv
    USART1->CR1 |= USART_CR1_OVER8;
    USART1->BRR = brr;
    
  }
  
  if (sbit == 1) USART1->CR2 &= ~USART_CR2_STOP;
  else if (sbit == 1.5) USART1->CR2 |= USART_CR2_STOP;
  else {USART1->CR2 &= ~USART_CR2_STOP; USART1->CR2 |= USART_CR2_STOP_1;}
  
  USART1->CR1 |= USART_CR1_UE;
  
  NVIC_EnableIRQ(USART1_IRQn);
}

void usart1_tx_init() {
 USART1->CR1 |= USART_CR1_TE;
}

void usart1_rx_init() {
 USART1->CR1 |= USART_CR1_RE;
 USART1->CR1 |= USART_CR1_RXNEIE;
}

void usart1_tx_str(volatile char *str) {
  int i=0;
  while(str[i]) {
    if (str[i] == STOP_SYM) {
      memset((void *)&rx_buf[0], '\0', sizeof(rx_buf));
      rx_ch = 0;
      break;
    }
   while ((USART1->ISR & USART_ISR_TC) != USART_ISR_TC);
   USART1->TDR = str[i];
   i++;
  }

}

void usart1_tx(char s) {
  while ((USART1->ISR & USART_ISR_TC) != USART_ISR_TC);
  USART1->TDR = s;
}





void usart_tx_num(unsigned int value, unsigned char nDigit) {
 switch(nDigit) {
  case 4: usart1_tx((value/1000)+'0');
  case 3: usart1_tx(((value/100)%10)+'0');
  case 2: usart1_tx(((value/10)%10)+'0');
  case 1: usart1_tx((value%10)+'0');
 }
}