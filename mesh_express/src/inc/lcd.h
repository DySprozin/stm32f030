#define LCD_D5_A                5
#define LCD_D6_A                7
#define LCD_D7_A                13
#define LCD_D4_A                0
#define LCD_RS_A                2
#define LCD_E_A                 3



#define LCD_IFDATA    rs == 1
#define LCD_IFCMD     rs == 0

#define LCD_RSDATA    1
#define LCD_RSCMD     0


#define LCD_DATA      GPIOA->BSRR |= BS(LCD_RS_A)
#define LCD_CMD       GPIOA->BSRR |= BR(LCD_RS_A)
#define LCD_E1        GPIOA->BSRR |= BS(LCD_E_A)
#define LCD_E0        GPIOA->BSRR |= BR(LCD_E_A)

#define LCD_D4S        GPIOA->BSRR |= BS(LCD_D4_A)
#define LCD_D5S        GPIOA->BSRR |= BS(LCD_D5_A)
#define LCD_D6S        GPIOA->BSRR |= BS(LCD_D6_A)
#define LCD_D7S        GPIOA->BSRR |= BS(LCD_D7_A)

#define LCD_D4R        GPIOA->BSRR |= BR(LCD_D4_A)
#define LCD_D5R        GPIOA->BSRR |= BR(LCD_D5_A)
#define LCD_D6R        GPIOA->BSRR |= BR(LCD_D6_A)
#define LCD_D7R        GPIOA->BSRR |= BR(LCD_D7_A)



#define LCD_WRITE(LCD_WRITE_BYTE,LCD_WRITE_RS)  lcd_byte[lcd_ch_sum] = LCD_WRITE_BYTE; lcd_rs[lcd_ch_sum] = LCD_WRITE_RS; lcd_ch_sum++

extern int lcd_byte[50];
extern int lcd_rs[50];
extern int lcd_ch;
extern int lcd_ch_sum;
extern int debug;

extern struct lcd_s {
  unsigned write : 1;
  unsigned l_nibble : 1;
  unsigned h_nibble : 1;  
  unsigned e : 1;
  unsigned e0 : 1;
  unsigned e1 : 1;
} lcd;

extern struct timer_lcd_s {
  int start;
} timer_lcd;

void lcd_init(void);

void lcd_write(int byte, int rs);

void lcd_e(void);