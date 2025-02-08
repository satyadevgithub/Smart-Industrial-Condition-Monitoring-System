#ifndef SHT31_H
#define SHT31_H

#include "stm32f4xx.h"

void SHT31_Init(void);
float SHT31_ReadTemperature(void);
float SHT31_ReadHumidity(void);

#endif // SHT31_H
