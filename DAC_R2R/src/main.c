#include "stm32f0xx.h"
#include "def.h"

void delay (int a);

void dac (char s);



void main(void)
{
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  GPIOA->MODER |= MODER_01(D0) |
                  MODER_01(D1) |
                  MODER_01(D2) |
                  MODER_01(D3) |
                  MODER_01(D4) |
                  MODER_01(D5) |
                  MODER_01(D6) |
                  MODER_01(D7);
  
  GPIOA->OTYPER &= ~OTYPER(D0) &
                   ~OTYPER(D1) &
                   ~OTYPER(D2) &
                   ~OTYPER(D3) &
                   ~OTYPER(D4) &
                   ~OTYPER(D5) &
                   ~OTYPER(D6) &
                   ~OTYPER(D7);
  
  GPIOA->PUPDR &= ~PUPDR_11(D0) &
                  ~PUPDR_11(D1) &
                  ~PUPDR_11(D2) &
                  ~PUPDR_11(D3) &
                  ~PUPDR_11(D4) &
                  ~PUPDR_11(D5) &
                  ~PUPDR_11(D6) &
                  ~PUPDR_11(D7);
    
    
  while(1) {
    /*
    for (int i = 0; i < 256; i++) {
      dac(i);
    }
    for (int i = 255; i >= 0; i--) {
      dac(i);
    }*/
    
    
    /* //tits
dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); 
dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); 
dac(0); dac(0); dac(32); dac(36); dac(40); dac(44); dac(48); dac(52); dac(54); dac(56); dac(56); dac(57); dac(58); dac(59);
 dac(60); dac(61); dac(62); dac(63); dac(63); dac(64); dac(64); dac(65); dac(65); dac(66); dac(67); dac(68); dac(68); dac(68);
 dac(68); dac(69); dac(69); dac(69); dac(70); dac(70); dac(70); dac(74); dac(78); dac(82); dac(83); dac(83); dac(83); dac(83);
 dac(82); dac(82); dac(78); dac(74); dac(70); dac(70); dac(70); dac(70); dac(69); dac(69); dac(69); dac(68); dac(68); dac(68);
 dac(67); dac(67); dac(67); dac(67); dac(66); dac(66); dac(66); dac(65); dac(65); dac(65); dac(65); dac(64); dac(63); dac(62);
 dac(60); dac(59); dac(58); dac(57); dac(57); dac(55); dac(53); dac(51); dac(48); dac(45); dac(43); dac(41); dac(35); dac(41);
 dac(43); dac(45); dac(48); dac(51); dac(53); dac(55); dac(57); dac(57); dac(58); dac(59); dac(60); dac(62); dac(63); dac(64); 
 dac(65); dac(65); dac(65); dac(65); dac(66); dac(66); dac(66); dac(67); dac(67); dac(67); dac(67); dac(68); dac(68); dac(68);
 dac(69); dac(69); dac(69); dac(70); dac(70); dac(70); dac(70); dac(74); dac(78); dac(82); dac(82); dac(83); dac(83); dac(83);
 dac(83); dac(82); dac(78); dac(74); dac(70); dac(70); dac(70); dac(69); dac(69); dac(69); dac(68); dac(68); dac(68); dac(68);
 dac(67); dac(66); dac(65); dac(64); dac(64); dac(63); dac(63); dac(62); dac(61); dac(60); dac(59); dac(58); dac(57); dac(56);
 dac(56); dac(54); dac(52); dac(48); dac(44); dac(40); dac(36); dac(32); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0);
 dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0);
 dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); 
 dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); 
 dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0);
*/
 
 
 //sinus
 dac(64); dac(65); dac(67); dac(68); dac(70); dac(72); dac(73); dac(75); dac(76); dac(78); dac(79); dac(81); dac(82); dac(84);
 dac(85); dac(87); dac(88); dac(90); dac(91); dac(92); dac(94); dac(95); dac(97); dac(98); dac(99); dac(100); dac(102); 
 dac(103); dac(104); dac(105); dac(107); dac(108); dac(109); dac(110); dac(111); dac(112); dac(113); dac(114); dac(115); 
 dac(116); dac(117); dac(118); dac(118); dac(119); dac(120); dac(121); dac(121); dac(122); dac(123); dac(123); dac(124);
 dac(124); dac(125); dac(125); dac(126); dac(126); dac(126); dac(127); dac(127); dac(127); dac(127); dac(127); dac(127);
 dac(127); dac(128); dac(127); dac(127); dac(127); dac(127); dac(127); dac(127); dac(127); dac(126); dac(126); dac(126);
 dac(125); dac(125); dac(124); dac(124); dac(123); dac(123); dac(122); dac(121); dac(121); dac(120); dac(119); dac(118); 
 dac(118); dac(117); dac(116); dac(115); dac(114); dac(113); dac(112); dac(111); dac(110); dac(109); dac(108); dac(107);
 dac(105); dac(104); dac(103); dac(102); dac(100); dac(99); dac(98); dac(97); dac(95); dac(94); dac(92); dac(91); dac(90);
 dac(88); dac(87); dac(85); dac(84); dac(82); dac(81); dac(79); dac(78); dac(76); dac(75); dac(73); dac(72); dac(70); 
 dac(68); dac(67); dac(65); dac(64); dac(62); dac(61); dac(59); dac(58); dac(56); dac(54); dac(53); dac(51); dac(50); 
 dac(48); dac(47); dac(45); dac(44); dac(42); dac(41); dac(39); dac(38); dac(36); dac(35); dac(34); dac(32); dac(31); 
 dac(30); dac(28); dac(27); dac(26); dac(25); dac(23); dac(22); dac(21); dac(20); dac(19); dac(18); dac(17); dac(15); 
 dac(14); dac(13); dac(13); dac(12); dac(11); dac(10); dac(9); dac(8); dac(8); dac(7); dac(6); dac(5); dac(5); dac(4);
 dac(4); dac(3); dac(3); dac(2); dac(2); dac(2); dac(1); dac(1); dac(1); dac(0); dac(0); dac(0); dac(0); dac(0); dac(0);
 dac(0); dac(0); dac(0); dac(0); dac(0); dac(1); dac(1); dac(1); dac(2); dac(2); dac(2); dac(3); dac(3); dac(4); dac(4);
 dac(5); dac(5); dac(6); dac(7); dac(8); dac(8); dac(9); dac(10); dac(11); dac(12); dac(13); dac(13); dac(14); dac(15);
 dac(17); dac(18); dac(19); dac(20); dac(21); dac(22); dac(23); dac(25); dac(26); dac(27); dac(28); dac(30); dac(31); 
 dac(32); dac(34); dac(35); dac(36); dac(38); dac(39); dac(41); dac(42); dac(44); dac(45); dac(47); dac(48); dac(50); 
 dac(51); dac(53); dac(54); dac(56); dac(58); dac(59); dac(61); dac(62);
 
 
 
 
 
    
  }
}


void delay (int a)
{
volatile int i,j;

for (i=0 ; i < a ; i++)
{
j++;
}

return;
}

void dac(char s) {


  
    if (s & 1) GPIOA->BSRR |= BS(D0);
    else GPIOA->BSRR |= BR(D0);
    if (s & 2) GPIOA->BSRR |= BS(D1);
    else GPIOA->BSRR |= BR(D1);
    if (s & 4) GPIOA->BSRR |= BS(D2);
    else GPIOA->BSRR |= BR(D2);
    if (s & 8) GPIOA->BSRR |= BS(D3);
    else GPIOA->BSRR |= BR(D3);
    if (s & 16) GPIOA->BSRR |= BS(D4);
    else GPIOA->BSRR |= BR(D4);
    if (s & 32) GPIOA->BSRR |= BS(D5);
    else GPIOA->BSRR |= BR(D5);
    if (s & 64) GPIOA->BSRR |= BS(D6);
    else GPIOA->BSRR |= BR(D6);
    if (s & 128) GPIOA->BSRR |= BS(D7);
    else GPIOA->BSRR |= BR(D7);

}