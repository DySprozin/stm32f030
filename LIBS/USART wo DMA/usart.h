
#define WORDLEN         8
#define DIVSPEED        16
#define STOP_BIT        1
#define RX_BUF_SIZE     100
#define STOP_SYM        '*'

extern volatile char rx_buf[RX_BUF_SIZE];

void usart_tx_str(volatile char *str);
void usart_tx(char s);
void usart_tx_num(unsigned int value, unsigned char nDigit);
char usart_rx();

/*
initialisation usart1. The arg "usartdiv" is arg for calculate baudrate register (BRR)
usartdiv=frequency/baudrate
*/
void usart_init(int usartdiv);

void usart_tx_init();
void usart_rx_init();

