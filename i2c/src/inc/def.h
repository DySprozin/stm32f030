
#define DEBUG_B                 1

#define ADC_PORT_A              1
#define PIN_CHROT_A             4

#define TIM31                   6





#define TX_PORT                 9
#define RX_PORT                 10


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

/***************** binary define *****************/
#define b00000000           0x00
#define b00000001           0x01
#define b00000010           0x02
#define b00000011           0x03
#define b00000100           0x04
#define b00000101           0x05
#define b00000110           0x06
#define b00000111           0x07
#define b00001000           0x08
#define b00001001           0x09
#define b00001010           0x0A
#define b00001011           0x0B
#define b00001100           0x0C
#define b00001101           0x0D
#define b00001110           0x0E
#define b00001111           0x0F

#define b00010000           0x10
#define b00010001           0x11
#define b00010010           0x12
#define b00010011           0x13
#define b00010100           0x14
#define b00010101           0x15
#define b00010110           0x16
#define b00010111           0x17
#define b00011000           0x18
#define b00011001           0x19
#define b00011010           0x1A
#define b00011011           0x1B
#define b00011100           0x1C
#define b00011101           0x1D
#define b00011110           0x1E
#define b00011111           0x1F

#define b00100000           0x20
#define b00100001           0x21
#define b00100010           0x22
#define b00100011           0x23
#define b00100100           0x24
#define b00100101           0x25
#define b00100110           0x26
#define b00100111           0x27
#define b00101000           0x28
#define b00101001           0x29
#define b00101010           0x2A
#define b00101011           0x2B
#define b00101100           0x2C
#define b00101101           0x2D
#define b00101110           0x2E
#define b00101111           0x2F

#define b00110000           0x30
#define b00110001           0x31
#define b00110010           0x32
#define b00110011           0x33
#define b00110100           0x34
#define b00110101           0x35
#define b00110110           0x36
#define b00110111           0x37
#define b00111000           0x38
#define b00111001           0x39
#define b00111010           0x3A
#define b00111011           0x3B
#define b00111100           0x3C
#define b00111101           0x3D
#define b00111110           0x3E
#define b00111111           0x3F

#define b01000000           0x40
#define b01000001           0x41
#define b01000010           0x42
#define b01000011           0x43
#define b01000100           0x44
#define b01000101           0x45
#define b01000110           0x46
#define b01000111           0x47
#define b01001000           0x48
#define b01001001           0x49
#define b01001010           0x4A
#define b01001011           0x4B
#define b01001100           0x4C
#define b01001101           0x4D
#define b01001110           0x4E
#define b01001111           0x4F

#define b01010000           0x50
#define b01010001           0x51
#define b01010010           0x52
#define b01010011           0x53
#define b01010100           0x54
#define b01010101           0x55
#define b01010110           0x56
#define b01010111           0x57
#define b01011000           0x58
#define b01011001           0x59
#define b01011010           0x5A
#define b01011011           0x5B
#define b01011100           0x5C
#define b01011101           0x5D
#define b01011110           0x5E
#define b01011111           0x5F

#define b01100000           0x60
#define b01100001           0x61
#define b01100010           0x62
#define b01100011           0x63
#define b01100100           0x64
#define b01100101           0x65
#define b01100110           0x66
#define b01100111           0x67
#define b01101000           0x68
#define b01101001           0x69
#define b01101010           0x6A
#define b01101011           0x6B
#define b01101100           0x6C
#define b01101101           0x6D
#define b01101110           0x6E
#define b01101111           0x6F

#define b01110000           0x70
#define b01110001           0x71
#define b01110010           0x72
#define b01110011           0x73
#define b01110100           0x74
#define b01110101           0x75
#define b01110110           0x76
#define b01110111           0x77
#define b01111000           0x78
#define b01111001           0x79
#define b01111010           0x7A
#define b01111011           0x7B
#define b01111100           0x7C
#define b01111101           0x7D
#define b01111110           0x7E
#define b01111111           0x7F

///////////////////////////////////

#define b10000000           0x80
#define b10000001           0x81
#define b10000010           0x82
#define b10000011           0x83
#define b10000100           0x84
#define b10000101           0x85
#define b10000110           0x86
#define b10000111           0x87
#define b10001000           0x88
#define b10001001           0x89
#define b10001010           0x8A
#define b10001011           0x8B
#define b10001100           0x8C
#define b10001101           0x8D
#define b10001110           0x8E
#define b10001111           0x8F

#define b10010000           0x90
#define b10010001           0x91
#define b10010010           0x92
#define b10010011           0x93
#define b10010100           0x94
#define b10010101           0x95
#define b10010110           0x96
#define b10010111           0x97
#define b10011000           0x98
#define b10011001           0x99
#define b10011010           0x9A
#define b10011011           0x9B
#define b10011100           0x9C
#define b10011101           0x9D
#define b10011110           0x9E
#define b10011111           0x9F

#define b10100000           0xA0
#define b10100001           0xA1
#define b10100010           0xA2
#define b10100011           0xA3
#define b10100100           0xA4
#define b10100101           0xA5
#define b10100110           0xA6
#define b10100111           0xA7
#define b10101000           0xA8
#define b10101001           0xA9
#define b10101010           0xAA
#define b10101011           0xAB
#define b10101100           0xAC
#define b10101101           0xAD
#define b10101110           0xAE
#define b10101111           0xAF

#define b10110000           0xB0
#define b10110001           0xB1
#define b10110010           0xB2
#define b10110011           0xB3
#define b10110100           0xB4
#define b10110101           0xB5
#define b10110110           0xB6
#define b10110111           0xB7
#define b10111000           0xB8
#define b10111001           0xB9
#define b10111010           0xBA
#define b10111011           0xBB
#define b10111100           0xBC
#define b10111101           0xBD
#define b10111110           0xBE
#define b10111111           0xBF

#define b11000000           0xC0
#define b11000001           0xC1
#define b11000010           0xC2
#define b11000011           0xC3
#define b11000100           0xC4
#define b11000101           0xC5
#define b11000110           0xC6
#define b11000111           0xC7
#define b11001000           0xC8
#define b11001001           0xC9
#define b11001010           0xCA
#define b11001011           0xCB
#define b11001100           0xCC
#define b11001101           0xCD
#define b11001110           0xCE
#define b11001111           0xCF

#define b11010000           0xD0
#define b11010001           0xD1
#define b11010010           0xD2
#define b11010011           0xD3
#define b11010100           0xD4
#define b11010101           0xD5
#define b11010110           0xD6
#define b11010111           0xD7
#define b11011000           0xD8
#define b11011001           0xD9
#define b11011010           0xDA
#define b11011011           0xDB
#define b11011100           0xDC
#define b11011101           0xDD
#define b11011110           0xDE
#define b11011111           0xDF

#define b11100000           0xE0
#define b11100001           0xE1
#define b11100010           0xE2
#define b11100011           0xE3
#define b11100100           0xE4
#define b11100101           0xE5
#define b11100110           0xE6
#define b11100111           0xE7
#define b11101000           0xE8
#define b11101001           0xE9
#define b11101010           0xEA
#define b11101011           0xEB
#define b11101100           0xEC
#define b11101101           0xED
#define b11101110           0xEE
#define b11101111           0xEF

#define b11110000           0xF0
#define b11110001           0xF1
#define b11110010           0xF2
#define b11110011           0xF3
#define b11110100           0xF4
#define b11110101           0xF5
#define b11110110           0xF6
#define b11110111           0xF7
#define b11111000           0xF8
#define b11111001           0xF9
#define b11111010           0xFA
#define b11111011           0xFB
#define b11111100           0xFC
#define b11111101           0xFD
#define b11111110           0xFE
#define b11111111           0xFF



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