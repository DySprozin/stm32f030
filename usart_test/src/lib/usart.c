#include "stm32f0xx.h"
#include "def.h"
#include "usart.h"
#include "string.h"



void usart1_init(int usartdiv) {
   
  /* (1-8) - ��������� ������ � ���������� */
   
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN; /* (1) */
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN; /* (2) */
   
  GPIOA->MODER |= MODER_10(TX_PORT) | MODER_10(RX_PORT); /* (3) */
  GPIOA->OTYPER &= ~OTYPER(TX_PORT) & ~OTYPER(RX_PORT); /* (4) */
  GPIOA->OSPEEDR |= OSPEEDR_11(TX_PORT) | OSPEEDR_11(RX_PORT); /* (5) */
  GPIOA->PUPDR &= ~PUPDR_11(TX_PORT) & ~PUPDR_11(RX_PORT); /* (6) */
   
  GPIOA->AFR[1] &= ~(AFRH(TX_PORT,) | AFRH(RX_PORT,)); /* (7) */
  GPIOA->AFR[1] |= AFRH(TX_PORT,1) | AFRH(RX_PORT,1); /* (8) */
   
  /* ��������� ���������� USART */
  /* (9) - ������� ���������� ��� baudrate */
  /* (10-11) - �������� ����� ����� (8 ��� 9 ���) */
  /* (12-15) - ������ usart �� ������ �������� (�������/16) */
   
  /* (16-24) - ������ usart �� ������� �������� (�������/8) */
  /*   |_(19) - 4 ��������� ���� usartdiv */
  /*   |_(20) - �������� ����� */
  /*   |_(21) - 4 ��������� ���� usartdiv */
  /*   |_(22) - ��������� ���������� � ��������� ������ usartdiv */
   
  /* (25-27) - ��������� ����� ����-���� (1, 1.5, 2) */
  /* (28) - ������������ usart */
   
  /* (29) - ������������ ���������� usart */
   
  int brr; /* (9) */
     
  if (WORDLEN == 8) USART1->CR1 &= ~USART_CR1_M; /* (10) */
  else USART1->CR1 |= USART_CR1_M; /* (11) */
   
  if (DIVSPEED == 16) { /* (12) */
    brr = usartdiv; /* (13) */
    USART1->CR1 &= ~USART_CR1_OVER8; /* (14) */
    USART1->BRR = brr; /* (15) */
  }
  else { /* (16) */
    usartdiv = usartdiv*2; /* (17) */
    brr = usartdiv; /* (18) */
    brr = brr & USART_BRR_DIV_FRACTION; /* (19) */
    brr = brr << 1;  /* (20) */
    brr = brr & USART_BRR_DIV_FRACTION; /* (21) */
    brr = brr | (usartdiv & USART_BRR_DIV_MANTISSA); /* (22) */
    USART1->CR1 |= USART_CR1_OVER8; /* (23) */
    USART1->BRR = brr; /* (24) */
     
  }
   
  if (STOP_BIT == 1) USART1->CR2 &= ~USART_CR2_STOP; /* (25) */
  else if (STOP_BIT == 1.5) USART1->CR2 |= USART_CR2_STOP; /* (26) */
  else {USART1->CR2 &= ~USART_CR2_STOP; USART1->CR2 |= USART_CR2_STOP_1;} /* (27) */
   
  USART1->CR1 |= USART_CR1_UE; /* (28) */
   
  NVIC_EnableIRQ(USART1_IRQn); /* (29) */
}



void usart1_tx_init() {
 USART1->CR1 |= USART_CR1_TE;
  USART1->CR1 |= USART_CR1_TXEIE;
}

void usart1_rx_init() {
 USART1->CR1 |= USART_CR1_RE;
 USART1->CR1 |= USART_CR1_RXNEIE;
}

void usart1_tx_str(volatile char *str) {
  int i=0;
  while(str[i]) {
   while ((USART1->ISR & USART_ISR_TC) != USART_ISR_TC);
   USART1->TDR = str[i];
   i++;
  }
}

void usart1_tx(char s) {
  while ((USART1->ISR & USART_ISR_TC) != USART_ISR_TC);
  USART1->TDR = s;
}

