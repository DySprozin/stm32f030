#include "stm32f0xx.h"

#define DATA_1           GPIOA->BSRR |= GPIO_BSRR_BS_2
#define DATA_0           GPIOA->BSRR |= GPIO_BSRR_BR_2

#define RS_1           GPIOA->BSRR |= GPIO_BSRR_BS_3
#define RS_0           GPIOA->BSRR |= GPIO_BSRR_BR_3

#define E_1           GPIOA->BSRR |= GPIO_BSRR_BS_4
#define E_0           GPIOA->BSRR |= GPIO_BSRR_BR_4


#define ST_CP_1          GPIOA->BSRR |= GPIO_BSRR_BS_1
#define ST_CP_0          GPIOA->BSRR |= GPIO_BSRR_BR_1

#define SH_CP_1          GPIOA->BSRR |= GPIO_BSRR_BS_0
#define SH_CP_0          GPIOA->BSRR |= GPIO_BSRR_BR_0

#define SH_CP SH_CP_1; SH_CP_0;
#define ST_CP ST_CP_1; ST_CP_0;

void lcd_char(char s, int pos);
void lcd_str(char *str, int pos);
void lcd_init();
void delay (int ms);
volatile int sleep = 1, y = 0, h, m, s;
void lcd_cmd (int data, int rs);

void TIM1_BRK_UP_TRG_COM_IRQHandler(void) {
  
  TIM1->SR &= ~TIM_SR_UIF;
  if (y++ > 1000) {
   y = 0;
   if ((s+1) > 59) {
     s = 0;
     if ((m+1) > 59) {
       m = 0;
       if ((h+1) > 23){
         h = 0;
       }
       else h++;
     }
     else m++;
   }
   else s++;
   
  }
  sleep = 0;
}

void main(void)
{
  
__enable_irq();

NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);

 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

 GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 | GPIO_MODER_MODER3_0 | GPIO_MODER_MODER4_0 | GPIO_MODER_MODER9_1;

 GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH1);
 GPIOA->AFR[1] |= 2 << ((9-8)*4);
 TIM1->ARR = 8000;
 TIM1->CR1 |= TIM_CR1_CEN;
 TIM1->DIER |= TIM_DIER_UIE;
 
 delay(500);
 
 lcd_init();

 h = 13;
 m = 29;
 s = 0;
 
 while(1) {
   
 //delay(500);
 lcd_cmd(0x1, 0);

// for (int i = 1; i <= 8; i++) {
  lcd_char((h/10) + '0', -1);
  lcd_char((h%10) + '0', -1);
  lcd_char(':', -1);
  lcd_char((m/10) + '0', -1);
  lcd_char((m%10) + '0', -1);
  lcd_char(':', -1);
  lcd_char((s/10) + '0', -1);
  lcd_char((s%10) + '0', -1);
  delay(500);
  lcd_cmd(0x1, 0);
  lcd_char((h/10) + '0', -1);
  lcd_char((h%10) + '0', -1);
  lcd_char(' ', -1);
  lcd_char((m/10) + '0', -1);
  lcd_char((m%10) + '0', -1);
  lcd_char(' ', -1);
  lcd_char((s/10) + '0', -1);
  lcd_char((s%10) + '0', -1);
  lcd_char(' ', -1);
  delay(500);
// }

 }
}

void delay (int ms) {
  for (int i = 0; i <= ms; i++) {
    while (sleep);
    sleep = 1;
  }
}

void lcd_cmd (int data, int rs) {
 
 delay(1);
 if (rs == 0) RS_0;
 else RS_1;
 delay(1);
 E_1;
 delay(1);
 int tmp;
 for (int j = 7; j >= 0; j--) {
  tmp = (data >> j) & 1;
  if (tmp == 0) DATA_0;
  else DATA_1;
  SH_CP;
 }
 ST_CP;
 delay(1);
 
 E_0;
}

 void lcd_init() {
  lcd_cmd(0x38, 0);
  lcd_cmd(0x1, 0);
  lcd_cmd(0x6, 0);
  lcd_cmd(0x0C, 0);
 }

void lcd_char(char s, int pos) {
  if (pos != -1) lcd_cmd(0x80 + pos, 0);
  lcd_cmd(s, 1);
}

void lcd_str(char *str, int pos) {
  if (pos != -1) lcd_cmd(0x80 + pos, 0);
  int i = 0;
  while(str[i]) {
    lcd_cmd(str[i++], 1);
  }
}