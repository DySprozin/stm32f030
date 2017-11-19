#include "stm32f0xx.h"
#include "def.h"
#include "usart.h"
#include "adc.h"
 

volatile int tmp, adc_sum, adc_ch, adc_result;

volatile uint32_t seconds;

void AdcGo(void);
void CheckPinChRots(void);
void CheckChRotsTime(void);
void CheckChRotsTimeSlow(void);

struct {
  unsigned show : 1;
} mainf;

volatile static struct {
  int show;
} timer;


void AdcGo(void);

void ShowResult(void);


void main(void) {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOAEN;
  GPIOB->MODER |= MODER_01(DEBUG_B);

  
  SysTick_Config(799); //100 uS

  usart1_init(833);
  usart1_tx_init();
  
  adc_init();
  
  while(1) {
    if (adcf.start) {
      adcf.start = 0;
      timer.show = 10000;
      adc_select();
    }
    if (adcf.go) {
      adcf.go = 0;
      timer_adc.go = 10;
      AdcGo();
    }
    if (mainf.show) {
      mainf.show = 0;
      timer.show = 10000;
      seconds++;
      ShowResult();
    }
  }
}

void SysTick_Handler(void) {
  if (timer_adc.go > 1) timer_adc.go--;
  else if (timer_adc.go == 1) adcf.go = 1;

  if (timer.show > 1) timer.show--;
  else if (timer.show == 1) mainf.show = 1;
}

void ADC1_COMP_IRQHandler() {
  if ((ADC1->ISR & ADC_ISR_ADRDY) == ADC_ISR_ADRDY) {
    ADC1->ISR |= ADC_ISR_ADRDY;
    timer_adc.go = 1000;
    adcf.start = 1;
  }
}

void AdcGo() {
 int adc;
 adc = getadc();
 adc_sum += adc >> 1;
 adc_ch++;
 
 if (adc_ch == 128) {
   adc_result = adc_sum >> 7;
   adc_sum = 0;
   adc_ch = 0;
 }

}


void ShowResult(){
   usart_tx_num(seconds, 5);
   usart1_tx_str ("\t");
   usart_tx_num(adc_result, 4);
   usart1_tx_str ("\r\n");
}