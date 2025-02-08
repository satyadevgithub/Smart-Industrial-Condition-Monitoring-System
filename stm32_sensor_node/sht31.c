#include "sht31.h"
#include "i2c.h"

#define SHT31_ADDR 0x44

void SHT31_Init(void) {
    uint8_t cmd[2] = {0x2C, 0x06};
    HAL_I2C_Master_Transmit(&hi2c1, SHT31_ADDR << 1, cmd, 2, 1000);
}

float SHT31_ReadTemperature(void) {
    uint8_t data[6];
    HAL_I2C_Master_Receive(&hi2c1, SHT31_ADDR << 1, data, 6, 1000);
    return ((data[0] << 8 | data[1]) * 175.0 / 65535.0) - 45.0;
}
