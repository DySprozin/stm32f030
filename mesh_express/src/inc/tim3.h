
#define TIM3_ARR        2000       //�� ������� ������� ������ ����� �������
#define TIM3_CCR1       1999       //������� ����� PWM-���� � �������� ���������
#define TIM3_PSC        0          //�������� �������


#define H_BEFORE_CCR1   TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2     //���� �������, ���� �� ��������� �� TIM3_CCR1
#define H_AFTER_CCR1    TIM_CCMR1_OC1M                          //���� �������, ����� ����, ��� ��������� �� TIM3_CCR1

void pwm_tim31();

