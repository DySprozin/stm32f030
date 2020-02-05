void flash_enable();
void flash_write(uint32_t addr, char byte1, char byte2);
uint32_t flash_read(uint32_t addr);
void flash_write_start();
void flash_write_stop();
void flash_erase(uint32_t addr);
void flash_write_int32(uint32_t addr, int32_t data);