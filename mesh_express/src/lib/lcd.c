#include "stm32f0xx.h"
#include "def.h"
#include "lcd.h"

void ldc_init() {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

}

void lcd_write(int byte, int rs) {
  set e1;
  set byte >> 4;
  sleep;
  set e0;
  set e1;
  set byte & 0x0F;
  sleep;
  set e0;
}