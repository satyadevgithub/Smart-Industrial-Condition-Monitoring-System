#include "spi_adc.h"
#include "spi.h"

void SPI_ADC_Init(void) {
    // Initialize SPI communication
}

uint16_t SPI_ADC_Read(void) {
    uint8_t data[2] = {0};
    HAL_SPI_Receive(&hspi1, data, 2, 1000);
    return (data[0] << 8) | data[1];
}
