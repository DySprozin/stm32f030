#include "stm32f0xx.h"
#include "def.h"
#include "lcd.h"

int lcd_byte;


struct lcd_s lcd;

struct timer_lcd_s timer_lcd;

void ldc_init() {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  
  GPIOA->MODER |= MODER_01(LCD_D4_A) | 
                  MODER_01(LCD_D5_A) | 
                  MODER_01(LCD_D6_A) | 
                  MODER_01(LCD_D7_A) | 
                  MODER_01(LCD_RS_A) | 
                  MODER_01(LCD_E_A);
  
  lcd_byte = 0x38; //00111000 
  lcd_write(LCD_RSCMD);

}

void lcd_write(int rs) {
  if (LCD_IFDATA) LCD_DATA;
  if (LCD_IFCMD) LCD_CMD;
  
  LCD_E0;
  
  if (!lcd.l_nibble) {
    LCD_E1;
    timer_lcd.e = 1;
  }
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