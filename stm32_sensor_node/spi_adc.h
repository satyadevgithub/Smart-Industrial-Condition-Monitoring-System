#ifndef SPI_ADC_H
#define SPI_ADC_H

#include "stm32f4xx.h"

void SPI_ADC_Init(void);
uint16_t SPI_ADC_Read(void);

#endif // SPI_ADC_H
