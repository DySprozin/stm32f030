#include "stm32f0xx.h"
#include "flash.h"


void flash_enable() {
  while((FLASH->SR & FLASH_SR_BSY));
  
  if (FLASH->CR & FLASH_CR_LOCK) {
   FLASH->KEYR |= FLASH_FKEY1;
   FLASH->KEYR |= FLASH_FKEY2;   
  }  
}

uint32_t flash_read(uint32_t addr) {
  return (*(__IO uint32_t*) addr);
}

void flash_erase(uint32_t addr) {
  FLASH->CR |= FLASH_CR_PER;
  FLASH->AR = addr;
  FLASH->CR |= FLASH_CR_STRT;
  
  while((FLASH->SR & FLASH_SR_BSY));
  if ((FLASH->SR & FLASH_SR_EOP) != 0) {
    FLASH->SR |= FLASH_SR_EOP;
  }
  
  FLASH->CR &= ~FLASH_CR_PER;
}

void flash_write_start() {
  flash_erase(0x8003400);
  FLASH->CR |= FLASH_CR_PG;
}

void flash_write(uint32_t addr, char byte1, char byte2) {

  
  *(__IO uint16_t*) (addr) = (byte1<<8)+byte2;
  
  
  while (!(FLASH->SR & FLASH_SR_EOP))
  FLASH->SR |= FLASH_SR_EOP;
  
  
}

void flash_write_stop() {
 FLASH->CR &= ~FLASH_CR_PG;
}


