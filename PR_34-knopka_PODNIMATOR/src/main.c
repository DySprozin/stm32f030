#include "stm32f0xx.h"
#include "lcd.h"
#include "def.h"

void main() {
   RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
 RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
   GPIOA->MODER |= MODER_01(LCD_SH_CP) | MODER_01(LCD_ST_CP) | MODER_01(LCD_DATA) | MODER_01(LCD_RS) | MODER_01(LCD_E);
   GPIOA->MODER &= ~MODER_11(BUT1);
   GPIOA->MODER &= ~MODER_11(BUT2);
   GPIOA->MODER &= ~MODER_11(BUT3);
   

  GPIOA->PUPDR &= ~PUPDR_11(BUT1);
  GPIOA->PUPDR &= ~PUPDR_11(BUT2);
  GPIOA->PUPDR &= ~PUPDR_11(BUT3);

  GPIOA->PUPDR |= PUPDR_01(BUT1);
  GPIOA->PUPDR |= PUPDR_01(BUT2);
  GPIOA->PUPDR |= PUPDR_01(BUT3);

         lcd_init();

   
   lcd_delay(500);


   
   nobut();
   
   while(1) {
       lcd_delay(50000);
    lcd_char(0x0,0); //Ä
    lcd_str("ABA",-1);
    lcd_char(0x1,-1); //É
    lcd_str(", B",-1);
    lcd_char(0x2,-1); //Û
    lcd_char(0x3,-1); //Ø
    lcd_str("E HOC)",-1);
    lcd_char(0x4,41); //Ï
    lcd_str("PECC ",-1);
    lcd_char(0x5,-1); //Ý
    lcd_str("H",-1);
    lcd_char(0x6,-1); //È
    lcd_str("KE",-1);
    lcd_char(0x1,-1); //É
    lcd_str(" ;)",-1);

     
     if (!(GPIOA->IDR & IDR(BUT1))) {
       lcd_delay(500);
       if (!(GPIOA->IDR & IDR(BUT1))) {
         button1();
       }
     }
     
     if (!(GPIOA->IDR & IDR(BUT2))) {
       lcd_delay(500);
       if (!(GPIOA->IDR & IDR(BUT2))) {
         button2();
       }
     }
     
     if (!(GPIOA->IDR & IDR(BUT3))) {
       lcd_delay(500);
       if (!(GPIOA->IDR & IDR(BUT3))) {
         button3();
       }
     }
     
   }
}

void button1(void) {
  lcd_init();
  lcd_cmd(b01000000, 0); //0x00 Ë
  lcd_cmd(b00000111, 1);
  lcd_cmd(b00001001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01001000, 0); //0x01 Ä
  lcd_cmd(b00001100, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);         
  lcd_cmd(b00011111, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01010000, 0); //0x02 Ö
  lcd_cmd(b00010010, 1);
  lcd_cmd(b00010010, 1);
  lcd_cmd(b00010010, 1);
  lcd_cmd(b00010010, 1);
  lcd_cmd(b00010010, 1);         
  lcd_cmd(b00010010, 1);         
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00000001, 1);
  
  lcd_cmd(b01011000, 0); //0x03 Ë
  lcd_cmd(b00000111, 1);
  lcd_cmd(b00001001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01100000, 0); //0õ04 ×
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_delay(5000);
  lcd_str("KTO MO", 0);
  lcd_char(0x0, -1); //Ë
  lcd_str("O", -1);
  lcd_char(0x1, -1); //Ä
  lcd_str("E", -1);
  lcd_char(0x2, -1); //Ö
  lcd_str("?", -1);
  lcd_delay(1000000);
  
  lcd_char(0x3, 41); //Ë
  lcd_str("EPO", -1);
  lcd_char(0x4, -1); //×
  lcd_str("KA MO", -1);
  lcd_char(0x0, -1); //Ë
  lcd_str("O", -1);
  lcd_char(0x1, -1); //Ä
  lcd_str("E", -1);
  lcd_char(0x2, -1); //Ö
  lcd_str("!", -1);

  lcd_delay(2000000);

     
  lcd_init();
  lcd_cmd(b01000000, 0); //0õ00 Ó
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00001110, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01001000, 0); //0x01 Ë
  lcd_cmd(b00000111, 1);
  lcd_cmd(b00001001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01010000, 0); //0x02 Û
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00011001, 1);
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00011001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01011000, 0); //0x03 Á
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00011110, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00011110, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01100000, 0); //0õ04 È
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01101000, 0); //0x05 ß
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01110000, 0); //0x06 Ï
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
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
  
  lcd_char(0x0, 0); //Ó
  lcd_char(0x1, -1); //Ë
  lcd_char(0x2, -1); //Û
  lcd_char(0x3, -1); //Á
  lcd_str("H", -1);
  lcd_char(0x4, -1); //È
  lcd_str("Cb", -1);
  lcd_str(", ", -1);
  lcd_char(0x0, 0); //Ó
  lcd_str(" TE", -1);
  lcd_char(0x3, -1); //Á
  lcd_char(0x5, -1); //ß
  lcd_str("BCE ", 41);
  lcd_char(0x6, -1); //Ï
  lcd_str("O", 41);
  lcd_char(0x1, -1); //Ë
  lcd_char(0x0, 0); //Ó
  lcd_char(0x7, 0); //×
  lcd_char(0x4, -1); //È
  lcd_str("TC", -1);
  lcd_char(0x5, -1); //ß
  lcd_str("!", -1);

  lcd_delay(4000000);
 
  nobut();
     

  
}

void button2(void) {
  lcd_init();
  
  lcd_cmd(b01000000, 0); //0õ00 Ó
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00001110, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01001000, 0); //0x01 É
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01010000, 0); //0x02 ß
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01011000, 0); //0x03 Ï
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01100000, 0); //0õ04 ×
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01101000, 0); //0x05 Ë
  lcd_cmd(b00000111, 1);
  lcd_cmd(b00001001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_delay(5000);
  lcd_str("BCE XEPH", 0);
  lcd_char(0x2, -1); //ß
  lcd_str(",", -1);
  lcd_str("KPOME", 41);
  lcd_char(0x3, -1); //Ï
  lcd_char(0x4, -1); //×
  lcd_str("E", -1);
  lcd_char(0x5, -1); //Ë
  lcd_str("...", -1);

  lcd_delay(2000000);

     
  lcd_init();
 
  lcd_cmd(b01000000, 0); //0x00 Ä
  lcd_cmd(b00001100, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);         
  lcd_cmd(b00011111, 1);         
  lcd_cmd(b00010001, 1);
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
  
  lcd_cmd(b01010000, 0); //0x02 Ï
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01011000, 0); //0x03 ×
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01100000, 0); //0õ04 Ë
  lcd_cmd(b00000111, 1);
  lcd_cmd(b00001001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01101000, 0); //0x05 Û
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00011001, 1);
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00011001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01110000, 0); //0x06 ß
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01111000, 0); //0õ07 Ó
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00001110, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_char(0x0, 0); //Ä
  lcd_str("A ", -1);
  lcd_char(0x1, -1); //È
  lcd_str(" ", -1);
  lcd_char(0x2, -1); //Ï
  lcd_char(0x3, -1); //×
  lcd_str("E", -1);
  lcd_char(0x4, -1); //Ë
  lcd_char(0x5, -1); //Û
  lcd_str(" XEPH", -1);
  lcd_char(0x6, -1); //ß
  
  lcd_str("A T", 41);
  lcd_char(0x5, -1); //Û
  lcd_str(" C", -1);
  lcd_char(0x7, -1); //Ó
  lcd_char(0x2, -1); //Ï
  lcd_str("EP! ;)", -1);

  lcd_delay(4000000);
 
  nobut();
     

  
}

void button3(void) {
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
  
  lcd_cmd(b01001000, 0); //0x01 Ó
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00001110, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01010000, 0); //0x02 È
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01011000, 0); //0x03 Ï
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);

  lcd_cmd(b01100000, 0); //0x04 ×
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00000001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_delay(5000);
  lcd_str("HE ", 0);
  lcd_char(0x0, -1); //Ã
  lcd_str("Ð", -1);
  lcd_char(0x1, -1); //Ó
  lcd_str("CT", -1);
  lcd_char(0x2, -1); //È
  lcd_str("!", -1);
  lcd_char(0x3, 41); //Ï
  lcd_str("OMH", -1);
  lcd_char(0x2, -1); //È
  lcd_str(", ", -1);
  lcd_char(0x4, -1); //×
  lcd_str("TO...", -1);

  lcd_delay(2000000);

     
  lcd_init();

  lcd_cmd(b01000000, 0); //0x00 È
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);

  lcd_str("HACTPOEH", 0);  
  lcd_char(0x0, -1); //È
  lcd_str("E - ", -1);
  lcd_str("OHO KAK XEP...", 41);

  lcd_delay(2000000);
 
  
  lcd_init();
  
  lcd_cmd(b01000000, 0); //0x00 È
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01001000, 0); //0x01 É
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01010000, 0); //0x02 Ï
  lcd_cmd(b00011111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01011000, 0); //0õ03 Ä
  lcd_cmd(b00001100, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);         
  lcd_cmd(b00011111, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01100000, 0); //0õ04 Û
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00011001, 1);
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00011001, 1);
  lcd_cmd(b00000000, 1);

  lcd_cmd(b01101000, 0); //0x05 Ü
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00010000, 1);
  lcd_cmd(b00011110, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00011110, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01110000, 0); //0x06 ß
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00001111, 1);
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_char(0x0, 0); //È
  lcd_str("MEET CBO", -1);
  lcd_char(0x1, -1); //É
  lcd_str("CTBO ", -1);
  lcd_char(0x2, 41); //Ï
  lcd_str("O", -1);
  lcd_char(0x3, -1); //Ä
  lcd_char(0x4, -1); //Û
  lcd_str("MAT", -1);
  lcd_char(0x5, -1); //Ü
  lcd_str(" C", -1);
  lcd_char(0x6, -1); //ß
  lcd_str(" :P", -1);

  lcd_delay(4000000);
  
  nobut();
     

  
}


void nobut() {
    lcd_init();

  lcd_cmd(b01000000, 0); //0x00 Ä
  lcd_cmd(b00001100, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);
  lcd_cmd(b00001010, 1);         
  lcd_cmd(b00011111, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
    
  lcd_cmd(b01001000, 0); //0x01 É
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01010000, 0); //0x02 Û
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00011001, 1);
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00011001, 1);
  lcd_cmd(b00000000, 1);
  
  
  lcd_cmd(b01011000, 0); //0õ03 Ø
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00010101, 1);         
  lcd_cmd(b00011111, 1);
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
  
  lcd_cmd(b01101000, 0); //0x05 Ý
  lcd_cmd(b00001110, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000001, 1);
  lcd_cmd(b00000111, 1);
  lcd_cmd(b00000001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00001110, 1);
  lcd_cmd(b00000000, 1);
  
  lcd_cmd(b01110000, 0); //0x06 È
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00010011, 1);
  lcd_cmd(b00010101, 1);
  lcd_cmd(b00011001, 1);         
  lcd_cmd(b00010001, 1);         
  lcd_cmd(b00010001, 1);
  lcd_cmd(b00000000, 1);

}