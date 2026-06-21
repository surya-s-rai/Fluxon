#ifndef FLASH_W25Q128_H
#define FLASH_W25Q128_H
void Flash_Init(void);
void Flash_WritePage(uint32_t address, uint8_t *buffer, uint16_t length);
#endif
