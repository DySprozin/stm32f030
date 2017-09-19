
#define SPI_NSS       4
#define SPI_SCK       5
#define SPI_MISO      6
#define SPI_MOSI      7

void spi_enable();
void spi_init(char nss);
void spi_config();