
void adc_init(void);

void adc_select(void);

int getadc(void);


extern struct adcf_s {
  unsigned start : 1;
  unsigned go : 1;
  unsigned diff : 1;
} adcf;

extern struct timer_adc_s { 
  int go;
  int diff;
} timer_adc;


