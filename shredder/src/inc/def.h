#define ADC_PORT 0


#define SW_PORT 1 //PB

#define TEMPF(ARG1, ARG2, ARG3)         ARG1##ARG2##ARG3
 
#define MODER_11(MOD_PORT)       TEMPF(GPIO_MODER_MODER, MOD_PORT,)
#define MODER_01(MOD_PORT)       TEMPF(GPIO_MODER_MODER, MOD_PORT,_0)
#define MODER_10(MOD_PORT)       TEMPF(GPIO_MODER_MODER, MOD_PORT,_1)

#define OSPEEDR_11(MOD_PORT)       TEMPF(GPIO_OSPEEDER_OSPEEDR, MOD_PORT,)
#define OSPEEDR_01(MOD_PORT)       TEMPF(GPIO_OSPEEDER_OSPEEDR, MOD_PORT,_0)
#define OSPEEDR_10(MOD_PORT)       TEMPF(GPIO_OSPEEDER_OSPEEDR, MOD_PORT,_1)


#define OTYPER(OTYPER_PORT)      TEMPF(GPIO_OTYPER_OT, _ , OTYPER_PORT)
#define IDR(IDR_PORT)            TEMPF(GPIO_IDR, _ , IDR_PORT)
#define BS(BS_PORT)            TEMPF(GPIO_BSRR_BS, _ , BS_PORT)
#define BR(BR_PORT)            TEMPF(GPIO_BSRR_BR, _ , BR_PORT)

#define PUPDR_11(PUPDR_PORT)     TEMPF(GPIO_PUPDR_PUPDR, PUPDR_PORT,)
#define PUPDR_01(PUPDR_PORT)     TEMPF(GPIO_PUPDR_PUPDR, PUPDR_PORT,_0)
#define PUPDR_10(PUPDR_PORT)     TEMPF(GPIO_PUPDR_PUPDR, PUPDR_PORT,_1)



