

static struct {
  unsigned e0 : 1;
  unsigned e1 : 1;
  unsigned dt : 1;
  unsigned cmd : 1;  
} lcd;

static struct {
  int 
} timer_lcd;

void lcd_init(void);

void lcd_write(int byte);