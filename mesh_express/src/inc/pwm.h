
#define TIM3_ARR        9       //�� ������� ������� ������ ����� �������
#define TIM3_CCR1       1       //������� ����� PWM-���� � �������� ���������
#define H_BEFORE_CCR1   TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2     //���� �������, ���� �� ��������� �� TIM3_CCR1
#define H_AFTER_CCR1    TIM_CCMR1_OC1M                          //���� �������, ����� ����, ��� ��������� �� TIM3_CCR1


void pwm_tim3_init(void);