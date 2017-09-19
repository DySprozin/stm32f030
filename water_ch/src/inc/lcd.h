#define DATA_1           GPIOA->BSRR |= GPIO_BSRR_BS_2
#define DATA_0           GPIOA->BSRR |= GPIO_BSRR_BR_2

#define RS_1           GPIOA->BSRR |= GPIO_BSRR_BS_3
#define RS_0           GPIOA->BSRR |= GPIO_BSRR_BR_3

#define E_1           GPIOA->BSRR |= GPIO_BSRR_BS_4
#define E_0           GPIOA->BSRR |= GPIO_BSRR_BR_4


#define ST_CP_1          GPIOA->BSRR |= GPIO_BSRR_BS_1
#define ST_CP_0          GPIOA->BSRR |= GPIO_BSRR_BR_1

#define SH_CP_1          GPIOA->BSRR |= GPIO_BSRR_BS_5
#define SH_CP_0          GPIOA->BSRR |= GPIO_BSRR_BR_5

#define SH_CP SH_CP_1; SH_CP_0;
#define ST_CP ST_CP_1; ST_CP_0;

void lcd_char(char s, int pos);
void lcd_str(char *str, int pos);
void lcd_num_to_str(unsigned int value, unsigned char nDigit, int pos);
void lcd_init();
void lcd_delay (int ms);
void lcd_cmd (int data, int rs);
