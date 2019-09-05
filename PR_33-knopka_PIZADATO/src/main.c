#include "stm32f0xx.h"
#include "lcd.h"
#include "def.h"

void main() {
   RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
   GPIOA->MODER |= MODER_01(LCD_SH_CP) | MODER_01(LCD_ST_CP) | MODER_01(LCD_DATA) | MODER_01(LCD_RS) | MODER_01(LCD_E);
   GPIOA->MODER &= ~MODER_11(BUT);
   
 GPIOA->MODER &= ~MODER_11(ADC_PORT);
 GPIOA->PUPDR &= ~PUPDR_11(ADC_PORT);

  GPIOA->PUPDR &= ~PUPDR_11(BUT);
  GPIOA->PUPDR |= PUPDR_01(BUT);

         lcd_init();

   
   lcd_delay(500);


   
   nobut();
   
   while(1) {
       lcd_delay(50000);
    lcd_str("B HE",0);
    lcd_char(0x0,-1); //Ï
    lcd_str("OH",-1);
    lcd_char(0x1,-1); //ß
    lcd_str("THO",-1);
    lcd_char(0x2,-1); //É
    lcd_str("C",41);
    lcd_char(0x3,-1); //È
    lcd_str("T",-1);
    lcd_char(0x4,-1); //Ó
    lcd_str("A",-1);
    lcd_char(0x5,-1); //Ö
    lcd_char(0x3,-1); //È
    lcd_char(0x3,-1); //È
    lcd_str(" - ",-1);
    lcd_char(0x6,-1); //Æ
    lcd_str("M",-1);
    lcd_char(0x3,-1); //È
    lcd_str(":)",-1);



    

     
     if (!(GPIOA->IDR & IDR(BUT))) {
       lcd_delay(500);
       if (!(GPIOA->IDR & IDR(BUT))) {
         button();
       }
     }
     
  //lcd_num_to_str(adc_result, 4, 41);
   }
}

void button(void) {
  lcd_init();
  lcd_cmd(b01000000, 0); //0x00 Ã
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00010000, 1);         
  lcd_cmd(b00010000, 1);         
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01001000, 0); //0x01 È
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01010000, 0); //0x02 Ë
  lcd_cmd(b00000111, 1);
  lcd_cmd(b00001001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01100000, 0); //0x04 Ï
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  
  lcd_cmd(b01011000, 0); //0õ03 Ó
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00001110, 1);
  lcd_cmd(b00000000, 1);
  
  
  lcd_cmd(b01101000, 0); //0x05 Á
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00011110, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00011110, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01110000, 0); //0x06 Ä
  lcd_cmd(b00001100, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);         
  lcd_cmd(b00011111, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01111000, 0); //0õ07 ×
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);
  lcd_cmd(b00000000, 1);
  
  
     lcd_delay(5000);
     lcd_char(0x4, 0);
     lcd_char(0x1, -1);
     lcd_char('3', -1);
     lcd_char(0x06, -1);
  lcd_str("ATO ", -1);
  
     lcd_char(0x5, -1);
     lcd_char(0x3, -1);
     lcd_char(0x6, -1);

  lcd_str("ET", -1);
  for (int i=5; i>0;i--) {
     lcd_str("C", 41);
     lcd_char(0x6, -1);
     lcd_str("E", -1);
     lcd_char(0x2, -1);
     lcd_str("AHO ", -1);
     lcd_char(0x7, -1);
     lcd_str("EPE3: ", -1);
     lcd_num_to_str(i,1,-1);
     i==5?lcd_delay(2000000):lcd_delay(1000000);
  }
//     lcd_delay(1000000);
//     lcd_char(0x7, 41);
//     lcd_str("EPE3: ", -1);
//     lcd_str("4", -1);
//     lcd_delay(1000000);
//     lcd_char(0x7, 41);
//     lcd_str("EPE3: ", -1);
//     lcd_str("3", -1);
//     lcd_delay(1000000);
//     lcd_char(0x7, 41);
//     lcd_str("EPE3: ", -1);
//     lcd_str("2", -1);
//     lcd_delay(1000000);
//     lcd_char(0x7, 41);
//     lcd_str("EPE3: ", -1);
//     lcd_str("1", -1);
//     lcd_delay(1000000);
//     lcd_char(0x7, 41);
//     lcd_str("EPE3: ", -1);
         lcd_init();

  lcd_cmd(b01010000, 0); //0x02 Ü
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00011110, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00011110, 1);
  lcd_cmd(b00000000, 1);
     
     lcd_str("=)   ", 0);
     lcd_char(0x3, -1);
     lcd_str("PA!!!  =)", -1);
     lcd_str("TE", 41);
     lcd_char(0x4, -1);
     lcd_str("EP", -1);
     lcd_char(0x2, -1);
     lcd_str(" ", -1);     
     lcd_char(0x4, -1);
     lcd_char(0x1, -1);
     lcd_char('3', -1);
     lcd_char(0x06, -1);
  lcd_str("ATO!", -1);

     
     
     lcd_delay(4000000);

     lcd_delay(5000);
 
     nobut();
     

  
}

void nobut() {
    lcd_init();

  lcd_cmd(b01000000, 0); //0x00 Ï
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01001000, 0); //0x01 ß
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01010000, 0); //0x02 É
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01011000, 0); //0x03 È
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01100000, 0); //0õ04 Ó
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00001110, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01101000, 0); //0x05 Ö
  lcd_cmd(b00010010, 1);
  lcd_cmd(b00010010, 1);
  lcd_cmd(b00010010, 1);
  lcd_cmd(b00010010, 1);
  lcd_cmd(b00010010, 1);         
  lcd_cmd(b00010010, 1);         
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00000001, 1);
  
  lcd_cmd(b01110000, 0); //0x06 Æ
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00001110, 1);
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00000000, 1);
}