#include "mpu6050.h"
#include "i2c.h"

#define MPU6050_ADDR 0x68

void MPU6050_Init(void) {
    uint8_t check, data;
    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR << 1, 0x75, 1, &check, 1, 1000);
    if (check == 0x68) {
        data = 0x00;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR << 1, 0x6B, 1, &data, 1, 1000);
    }
}

void MPU6050_Read(float* accel, float* gyro) {
    uint8_t data[14];
    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR << 1, 0x3B, 1, data, 14, 1000);
    accel[0] = ((int16_t)(data[0] << 8 | data[1])) / 16384.0;
    accel[1] = ((int16_t)(data[2] << 8 | data[3])) / 16384.0;
    accel[2] = ((int16_t)(data[4] << 8 | data[5])) / 16384.0;
}
