#ifndef _SERVO_H
#define _SERVO_H

#include "main.h"
#include "tim.h"

void Servo_Init(void);
void Servo_SetAngle( TIM_HandleTypeDef *hitm , uint32_t Channel ,uint8_t angle );//指明tim，通道，和角度

#endif
