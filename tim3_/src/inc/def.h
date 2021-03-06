
#define TX_PORT      9
#define RX_PORT      10
#define TIM31          6
#define TIM32          7




#define TEMPF(ARG1, ARG2, ARG3)         ARG1##ARG2##ARG3
 
#define MODER_11(MOD_PORT)       TEMPF(GPIO_MODER_MODER, MOD_PORT,)
#define MODER_01(MOD_PORT)       TEMPF(GPIO_MODER_MODER, MOD_PORT,_0)
#define MODER_10(MOD_PORT)       TEMPF(GPIO_MODER_MODER, MOD_PORT,_1)

#define OTYPER(OTYPER_PORT)      TEMPF(GPIO_OTYPER_OT, _ , OTYPER_PORT)
#define IDR(IDR_PORT)            TEMPF(GPIO_IDR, _ , IDR_PORT)
#define BS(BS_PORT)            TEMPF(GPIO_BSRR_BS, _ , BS_PORT)
#define BR(BR_PORT)            TEMPF(GPIO_BSRR_BR, _ , BR_PORT)

#define PUPDR_11(PUPDR_PORT)     TEMPF(GPIO_PUPDR_PUPDR, PUPDR_PORT,)
#define PUPDR_01(PUPDR_PORT)     TEMPF(GPIO_PUPDR_PUPDR, PUPDR_PORT,_0)
#define PUPDR_10(PUPDR_PORT)     TEMPF(GPIO_PUPDR_PUPDR, PUPDR_PORT,_1)

#define OSPEEDR_11(SPEED_PORT)       TEMPF(GPIO_OSPEEDER_OSPEEDR, SPEED_PORT,)
#define OSPEEDR_01(SPEED_PORT)       TEMPF(GPIO_OSPEEDER_OSPEEDR, SPEED_PORT,_0)
#define OSPEEDR_10(SPEED_PORT)       TEMPF(GPIO_OSPEEDER_OSPEEDR, SPEED_PORT,_1)

#define AFRL(AFRL_PORT,AFR_AF)       TEMPF(AFRL,AFRL_PORT,AFR_AF)
#define AFRH(AFRH_PORT,AFR_AF)       TEMPF(AFRH,AFRH_PORT,AFR_AF)


/****************** Bit definition for GPIO_AFRL register  ********************/
#define AFRL0             ((uint32_t)0x0000000F)
#define AFRL00            ((uint32_t)0x00000000)
#define AFRL01            ((uint32_t)0x00000001)
#define AFRL02            ((uint32_t)0x00000002)
#define AFRL03            ((uint32_t)0x00000003)
#define AFRL04            ((uint32_t)0x00000004)
#define AFRL05            ((uint32_t)0x00000005)
#define AFRL06            ((uint32_t)0x00000006)
#define AFRL07            ((uint32_t)0x00000007)

#define AFRL1             ((uint32_t)0x000000F0)
#define AFRL10            ((uint32_t)0x00000000)
#define AFRL11            ((uint32_t)0x00000010)
#define AFRL12            ((uint32_t)0x00000020)
#define AFRL13            ((uint32_t)0x00000030)
#define AFRL14            ((uint32_t)0x00000040)
#define AFRL15            ((uint32_t)0x00000050)
#define AFRL16            ((uint32_t)0x00000060)
#define AFRL17            ((uint32_t)0x00000070)

#define AFRL2             ((uint32_t)0x00000F00)
#define AFRL20            ((uint32_t)0x00000000)
#define AFRL21            ((uint32_t)0x00000100)
#define AFRL22            ((uint32_t)0x00000200)
#define AFRL23            ((uint32_t)0x00000300)
#define AFRL24            ((uint32_t)0x00000400)
#define AFRL25            ((uint32_t)0x00000500)
#define AFRL26            ((uint32_t)0x00000600)
#define AFRL27            ((uint32_t)0x00000700)

#define AFRL3             ((uint32_t)0x0000F000)
#define AFRL30            ((uint32_t)0x00000000)
#define AFRL31            ((uint32_t)0x00001000)
#define AFRL32            ((uint32_t)0x00002000)
#define AFRL33            ((uint32_t)0x00003000)
#define AFRL34            ((uint32_t)0x00004000)
#define AFRL35            ((uint32_t)0x00005000)
#define AFRL36            ((uint32_t)0x00006000)
#define AFRL37            ((uint32_t)0x00007000)

#define AFRL4             ((uint32_t)0x000F0000)
#define AFRL40            ((uint32_t)0x00000000)
#define AFRL41            ((uint32_t)0x00010000)
#define AFRL42            ((uint32_t)0x00020000)
#define AFRL43            ((uint32_t)0x00030000)
#define AFRL44            ((uint32_t)0x00040000)
#define AFRL45            ((uint32_t)0x00050000)
#define AFRL46            ((uint32_t)0x00060000)
#define AFRL47            ((uint32_t)0x00070000)

#define AFRL5             ((uint32_t)0x00F00000)
#define AFRL50            ((uint32_t)0x00000000)
#define AFRL51            ((uint32_t)0x00100000)
#define AFRL52            ((uint32_t)0x00200000)
#define AFRL53            ((uint32_t)0x00300000)
#define AFRL54            ((uint32_t)0x00400000)
#define AFRL55            ((uint32_t)0x00500000)
#define AFRL56            ((uint32_t)0x00600000)
#define AFRL57            ((uint32_t)0x00700000)

#define AFRL6             ((uint32_t)0x0F000000)
#define AFRL60            ((uint32_t)0x00000000)
#define AFRL61            ((uint32_t)0x01000000)
#define AFRL62            ((uint32_t)0x02000000)
#define AFRL63            ((uint32_t)0x03000000)
#define AFRL64            ((uint32_t)0x04000000)
#define AFRL65            ((uint32_t)0x05000000)
#define AFRL66            ((uint32_t)0x06000000)
#define AFRL67            ((uint32_t)0x07000000)

#define AFRL7             ((uint32_t)0xF0000000)
#define AFRL70            ((uint32_t)0x00000000)
#define AFRL71            ((uint32_t)0x10000000)
#define AFRL72            ((uint32_t)0x20000000)
#define AFRL73            ((uint32_t)0x30000000)
#define AFRL74            ((uint32_t)0x40000000)
#define AFRL75            ((uint32_t)0x50000000)
#define AFRL76            ((uint32_t)0x60000000)
#define AFRL77            ((uint32_t)0x70000000)

/****************** Bit definition for GPIO_AFRH register  ********************/
#define AFRH8             ((uint32_t)0x0000000F)
#define AFRH80            ((uint32_t)0x00000000)
#define AFRH81            ((uint32_t)0x00000001)
#define AFRH82            ((uint32_t)0x00000002)
#define AFRH83            ((uint32_t)0x00000003)
#define AFRH84            ((uint32_t)0x00000004)
#define AFRH85            ((uint32_t)0x00000005)
#define AFRH86            ((uint32_t)0x00000006)
#define AFRH87            ((uint32_t)0x00000007)

#define AFRH9             ((uint32_t)0x000000F0)
#define AFRH90            ((uint32_t)0x00000000)
#define AFRH91            ((uint32_t)0x00000010)
#define AFRH92            ((uint32_t)0x00000020)
#define AFRH93            ((uint32_t)0x00000030)
#define AFRH94            ((uint32_t)0x00000040)
#define AFRH95            ((uint32_t)0x00000050)
#define AFRH96            ((uint32_t)0x00000060)
#define AFRH97            ((uint32_t)0x00000070)

#define AFRH10             ((uint32_t)0x00000F00)
#define AFRH100            ((uint32_t)0x00000000)
#define AFRH101            ((uint32_t)0x00000100)
#define AFRH102            ((uint32_t)0x00000200)
#define AFRH103            ((uint32_t)0x00000300)
#define AFRH104            ((uint32_t)0x00000400)
#define AFRH105            ((uint32_t)0x00000500)
#define AFRH106            ((uint32_t)0x00000600)
#define AFRH107            ((uint32_t)0x00000700)

#define AFRH11             ((uint32_t)0x0000F000)
#define AFRH110            ((uint32_t)0x00000000)
#define AFRH111            ((uint32_t)0x00001000)
#define AFRH112            ((uint32_t)0x00002000)
#define AFRH113            ((uint32_t)0x00003000)
#define AFRH114            ((uint32_t)0x00004000)
#define AFRH115            ((uint32_t)0x00005000)
#define AFRH116            ((uint32_t)0x00006000)
#define AFRH117            ((uint32_t)0x00007000)

#define AFRH12             ((uint32_t)0x000F0000)
#define AFRH120            ((uint32_t)0x00000000)
#define AFRH121            ((uint32_t)0x00010000)
#define AFRH122            ((uint32_t)0x00020000)
#define AFRH123            ((uint32_t)0x00030000)
#define AFRH124            ((uint32_t)0x00040000)
#define AFRH125            ((uint32_t)0x00050000)
#define AFRH126            ((uint32_t)0x00060000)
#define AFRH127            ((uint32_t)0x00070000)

#define AFRH13             ((uint32_t)0x00F00000)
#define AFRH130            ((uint32_t)0x00000000)
#define AFRH131            ((uint32_t)0x00100000)
#define AFRH132            ((uint32_t)0x00200000)
#define AFRH133            ((uint32_t)0x00300000)
#define AFRH134            ((uint32_t)0x00400000)
#define AFRH135            ((uint32_t)0x00500000)
#define AFRH136            ((uint32_t)0x00600000)
#define AFRH137            ((uint32_t)0x00700000)

#define AFRH14             ((uint32_t)0x0F000000)
#define AFRH140            ((uint32_t)0x00000000)
#define AFRH141            ((uint32_t)0x01000000)
#define AFRH142            ((uint32_t)0x02000000)
#define AFRH143            ((uint32_t)0x03000000)
#define AFRH144            ((uint32_t)0x04000000)
#define AFRH145            ((uint32_t)0x05000000)
#define AFRH146            ((uint32_t)0x06000000)
#define AFRH147            ((uint32_t)0x07000000)

#define AFRH15             ((uint32_t)0xF0000000)
#define AFRH150            ((uint32_t)0x00000000)
#define AFRH151            ((uint32_t)0x10000000)
#define AFRH152            ((uint32_t)0x20000000)
#define AFRH153            ((uint32_t)0x30000000)
#define AFRH154            ((uint32_t)0x40000000)
#define AFRH155            ((uint32_t)0x50000000)
#define AFRH156            ((uint32_t)0x60000000)
#define AFRH157            ((uint32_t)0x70000000)