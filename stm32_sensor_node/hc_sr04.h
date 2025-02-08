#ifndef HC_SR04_H
#define HC_SR04_H

#include "stm32f4xx.h"

void HC_SR04_Init(void);
float HC_SR04_ReadDistance(void);

#endif // HC_SR04_H
