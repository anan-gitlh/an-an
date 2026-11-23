#ifndef _MOVE_H
#define _MOVE_H

#include "main.h"
#include "motor.h"


void Mecanum_Move( int16_t vx ,int16_t vy ,int16_t omega );//vx前后 ，vy 左右 ， omega 旋转控制。

void Move_Stop(void);//刹车

#endif

