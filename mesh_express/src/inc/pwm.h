
#define TIM3_ARR        9       //�� ������� ������� ������ ����� �������
#define TIM3_CCR1       1       //������� ����� PWM-���� � �������� ���������
#define TIM3_PSC        799      //�������� �������


#define H_BEFORE_CCR1   TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2     //���� �������, ���� �� ��������� �� TIM3_CCR1
#define H_AFTER_CCR1    TIM_CCMR1_OC1M                          //���� �������, ����� ����, ��� ��������� �� TIM3_CCR1


#define TIM31      6

void pwm_tim31_init();