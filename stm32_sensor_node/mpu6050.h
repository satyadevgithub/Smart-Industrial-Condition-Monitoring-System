#ifndef MPU6050_H
#define MPU6050_H

#include "stm32f4xx.h"

void MPU6050_Init(void);
void MPU6050_Read(float* accel, float* gyro);

#endif // MPU6050_H
