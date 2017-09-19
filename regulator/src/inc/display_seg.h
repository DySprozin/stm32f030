#define SEG_E   1
#define SEG_D   2
#define SEG_C   3
#define SEG_G   4
#define SEG_B   5
#define SEG_F   6
#define SEG_A   7
#define SEG1    0 //PF
#define SEG2    1 //PF
#define SEG3    13 //PA

#define	NUM1    GPIOA->BSRR |= BS(SEG_B) | BS(SEG_C)
#define	NUM2	GPIOA->BSRR |= BS(SEG_A) |  BS(SEG_B) |  BS(SEG_G) |  BS(SEG_E) |  BS(SEG_D)
#define	NUM3	GPIOA->BSRR |= BS(SEG_A) |  BS(SEG_B) |  BS(SEG_G) |  BS(SEG_C) |  BS(SEG_D)
#define	NUM4	GPIOA->BSRR |= BS(SEG_F) |  BS(SEG_G) |  BS(SEG_B) |  BS(SEG_C)       
#define	NUM5	GPIOA->BSRR |= BS(SEG_A) |  BS(SEG_F) |  BS(SEG_G) |  BS(SEG_C) |  BS(SEG_D)
#define	NUM6	GPIOA->BSRR |= BS(SEG_A) |  BS(SEG_F) |  BS(SEG_G) |  BS(SEG_E) |  BS(SEG_C) |  BS(SEG_D)
#define	NUM7	GPIOA->BSRR |= BS(SEG_A) |  BS(SEG_B) |  BS(SEG_C)
#define	NUM8	GPIOA->BSRR |= BS(SEG_A) |  BS(SEG_B) |  BS(SEG_C) |  BS(SEG_D) |  BS(SEG_E) |  BS(SEG_F) |  BS(SEG_G)
#define	NUM9	GPIOA->BSRR |= BS(SEG_A) |  BS(SEG_B) |  BS(SEG_C) |  BS(SEG_D) |  BS(SEG_F) |  BS(SEG_G)
#define	NUM0	GPIOA->BSRR |= BS(SEG_A) |  BS(SEG_B) |  BS(SEG_C) |  BS(SEG_D) |  BS(SEG_E) |  BS(SEG_F)
#define	SEG_ERR	GPIOA->BSRR |= BS(SEG_A) |  BS(SEG_F) |  BS(SEG_G) |  BS(SEG_E) |  BS(SEG_D)

#define SEG1_S GPIOF->BSRR |= BR(SEG1)
#define SEG2_S GPIOF->BSRR |= BR(SEG2)
#define SEG3_S GPIOA->BSRR |= BR(SEG3)
#define SEG_R  GPIOF->BSRR |= BS(SEG1); GPIOF->BSRR |= BS(SEG2); GPIOA->BSRR |= BS(SEG3)

#define	RESET_ALL	GPIOA->BSRR |= BR(SEG_A) |  BR(SEG_B) |  BR(SEG_C) |  BR(SEG_D) |  BR(SEG_E) |  BR(SEG_F) |  BR(SEG_G)



void seg_show(int d);
void seg_num(int d);