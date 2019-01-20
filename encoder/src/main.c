#include "stm32f0xx.h"
#include "def.h"
#include "usart.h"
#include "encoder.h"
 
void main(void) {
   

 
 usart1_init(833);
 usart1_tx_init();
 usart1_rx_init();
  
 int tmp;
 int enc_curr = 0;
 
 encoder_init();
 
 while (1) {
    enc_curr = encoder();
    if (enc_curr != tmp && (enc_curr % 4) == 0) {

      if (enc_curr > 3000) {
        enc_curr = 0;
        encoder_set(0);
      }
      
      if (enc_curr > 2000) {
        enc_curr = 2000;
        encoder_set(2000);
      }
      
        usart1_tx_str("cnt: "); 
        usart_tx_num(enc_curr, 4); /* (7) */
        usart1_tx_str("\r\n"); 
        tmp = enc_curr;
    }
 }
}