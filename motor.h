#ifndef _MOTOR_H
#define _MOTOR_H

#include "main.h"

typedef enum {
	MOTOR_LA = 0 ,
	MOTOR_RA ,
	MOTOR_LR ,
	MOTOR_RR,
}Motor_ID ;

void Motor_Init(void);
void Motor_SetSpeed( Motor_ID motor , int16_t speed );

#endif







	
	