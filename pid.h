#ifndef __PID_H
#define __PID_H

#include "main.h"

// 定义PID结构体
typedef struct {
    float Kp;         // 比例系数
    float Ki;         // 积分系数
    float Kd;         // 微分系数
    
    float target;     // 目标速度
    float actual;     // 实际速度
    float error;      // 当前误差
    float last_error; // 上次误差
    
    float pwm_out;    // 计算出的PWM输出
} PID_TypeDef;

// 函数声明
void PID_Init( PID_TypeDef *pid, float p , float i , float d );
int16_t PID_Calc( PID_TypeDef *pid , float target , float actual );

#endif
	
	