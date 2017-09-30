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

extern int lcd_byte;

extern struct lcd_s {
  unsigned e_down : 1;
  unsigned l_nibble : 1;
  unsigned h_nibble : 1;  
} lcd;

extern struct timer_lcd_s {
  int e;
} timer_lcd;

void lcd_init(void);

void lcd_write(int rs);