#include "stm32f0xx.h"
#include "lcd.h"

void lcd_delay (int a) {
 int i,j;
 for (i=0 ; i < a ; i++) {
  j++;
 }
}



void lcd_cmd (int data, int rs) {
 
 lcd_delay(1000);
 if (rs == 0) RS_0;
 else RS_1;
 lcd_delay(1000);
 E_1;
 lcd_delay(1000);
 int tmp;
 for (int j = 7; j >= 0; j--) {
  tmp = (data >> j) & 1;
  if (tmp == 0) DATA_0;
  else DATA_1;
  SH_CP;
 }
 ST_CP;
 lcd_delay(1000);
 
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

void lcd_num_to_str(unsigned int value, unsigned char nDigit, int pos) {
 if (pos != -1) lcd_cmd(0x80 + pos, 0);
 switch(nDigit) {
  case 5: lcd_cmd((value/10000)+'0', 1);
  case 4: lcd_cmd(((value/1000)%10)+'0', 1);
  case 3: lcd_cmd(((value/100)%10)+'0', 1);
  case 2: lcd_cmd(((value/10)%10)+'0', 1);
  case 1: lcd_cmd((value%10)+'0', 1);
 }
}

