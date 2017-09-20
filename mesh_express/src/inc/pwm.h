
#define TIM3_ARR        9       //до скольки считает таймер перед сбросом
#define TIM3_CCR1       1       //сколько тиков PWM-порт в активном состоянии
#define H_BEFORE_CCR1   TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2     //порт активен, пока не досчитает до TIM3_CCR1
#define H_AFTER_CCR1    TIM_CCMR1_OC1M                          //порт активен, после того, как досчитает до TIM3_CCR1


void pwm_tim3_init(void);