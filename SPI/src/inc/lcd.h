#include "def.h"

#define LCD_ST_CP         1
#define LCD_DATA          2
#define LCD_RS            3
#define LCD_E             14
#define LCD_SH_CP         0


#define DATA_1           GPIOA->BSRR |= BS(LCD_DATA)
#define DATA_0           GPIOA->BSRR |= BR(LCD_DATA)

#define RS_1           GPIOA->BSRR |= BS(LCD_RS)
#define RS_0           GPIOA->BSRR |= BR(LCD_RS)

#define E_1           GPIOA->BSRR |= BS(LCD_E)
#define E_0           GPIOA->BSRR |= BR(LCD_E)


#define ST_CP_1          GPIOA->BSRR |= BS(LCD_ST_CP)
#define ST_CP_0          GPIOA->BSRR |= BR(LCD_ST_CP)

#define SH_CP_1          GPIOA->BSRR |= BS(LCD_SH_CP)
#define SH_CP_0          GPIOA->BSRR |= BR(LCD_SH_CP)

#define SH_CP SH_CP_1; SH_CP_0;
#define ST_CP ST_CP_1; ST_CP_0;

void lcd_char(char s, int pos);
void lcd_str(char *str, int pos);
void lcd_num_to_str(unsigned int value, unsigned char nDigit, int pos);
void lcd_init();
void lcd_delay (int ms);
void lcd_cmd (int data, int rs);
