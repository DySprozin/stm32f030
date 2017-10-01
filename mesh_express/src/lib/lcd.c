#include "stm32f0xx.h"
#include "def.h"
#include "lcd.h"
#include "usart.h"

int lcd_byte[50];
int lcd_rs[50];
int lcd_ch = 0;
int lcd_ch_sum = 0;
int debug = 0;

static int p = 0;


struct lcd_s lcd;

struct timer_lcd_s timer_lcd;

void lcd_init() {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  
  GPIOA->MODER |= MODER_01(LCD_D4_A) | 
                  MODER_01(LCD_D5_A) | 
                  MODER_01(LCD_D6_A) | 
                  MODER_01(LCD_D7_A) | 
                  MODER_01(LCD_RS_A) | 
                  MODER_01(LCD_E_A);

  
  LCD_WRITE(b00101000, LCD_RSCMD);
  LCD_WRITE(b00000001, LCD_RSCMD);
  LCD_WRITE(b00000110, LCD_RSCMD);
  LCD_WRITE(b00001101, LCD_RSCMD);
  LCD_WRITE(b00000001, LCD_RSCMD);
  LCD_WRITE(b00010100, LCD_RSCMD);
  LCD_WRITE(b10000000, LCD_RSCMD);
  LCD_WRITE(b00110001, LCD_RSDATA);
  LCD_WRITE(b00110001, LCD_RSDATA);

  
  timer_lcd.start = 10;

}

void lcd_e() {
  lcd.e = 0;
  timer_lcd.start = 0;
  
  
  
  if (lcd.h_nibble && lcd.l_nibble) {
     lcd.h_nibble = 0;
     lcd.l_nibble = 0;
     if (lcd_ch < lcd_ch_sum) {
       lcd_ch++;
     }
     else {
       lcd_ch = 0;
       lcd_ch_sum = 0;
       timer_lcd.start = 0;
       return;
     }
  }
  
  

  
  if (!lcd.e1) {
      debug++;
    LCD_E1;
    lcd.e1 = 1;
    timer_lcd.start = 10;
    return;
  }
  else if (!lcd.e0) {
    lcd_write(lcd_byte[lcd_ch], lcd_rs[lcd_ch]);
    lcd.e0 = 1;
    timer_lcd.start = 10;
    return;
  }
  else if (lcd.e0 && lcd.e1) {
    lcd.e1 = 0;
    lcd.e0 = 0;
    LCD_E0;
    
    if (lcd_ch_sum == 0) {
      timer_lcd.start = 0;
      return;
    }
    else timer_lcd.start = 10;
  }
}

void lcd_write(int byte, int rs) {
  if (byte == 0x0) {
    LCD_DATA;
    return;
  }

  if (LCD_IFDATA) LCD_DATA;
  if (LCD_IFCMD) LCD_CMD;


  if (!lcd.h_nibble) {
    
    lcd.h_nibble = 1;
    byte = byte >> 4;
    
  }
  else if (!lcd.l_nibble) {
   lcd.l_nibble = 1;

   byte = byte & 0x0F;
   
  }

  //   lcd_ch = 0;
  //   lcd_ch_sum--;
  //       return;
  //
     
     
  if (byte & b00000001) LCD_D4S;
  else LCD_D4R;
  if (byte & b00000010) LCD_D5S;
  else LCD_D5R;
  if (byte & b00000100) LCD_D6S;
  else LCD_D6R;
  if (byte & b00001000) LCD_D7S;
  else LCD_D7R;
   /* 
  usart1_tx('\r');
  usart1_tx('\n');
  usart1_tx('[');
  usart_tx_num(byte,4);
  usart1_tx(':');
  usart_tx_num(rs,4);
  usart1_tx(']');
  usart1_tx('\r');
  usart1_tx('\n');
  */
  /*
  set e1;
  set byte >> 4;
  sleep;
  set e0;
  set e1;
  set byte & 0x0F;
  sleep;
  set e0;*/
}