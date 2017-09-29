
void adc_init(void);

void adc_select(void);

int getadc(void);

static struct {
  unsigned start : 1;
  unsigned go : 1;
  unsigned diff : 1;
} adcf;

static struct {
  int start;
  int diff;
} timer_adc;