#ifndef CAN_COMM_H
#define CAN_COMM_H

#include "stm32f4xx.h"

void CAN_Init(void);
void CAN_SendData(uint8_t* data, uint8_t length);

#endif // CAN_COMM_H
