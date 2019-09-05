#define LCD_ST_CP         1
#define LCD_DATA          2
#define LCD_RS            3
#define LCD_E             4
#define LCD_SH_CP         5

#define BUT               0

#define ADC_PORT      6

void button(void);
void nobut(void);

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

