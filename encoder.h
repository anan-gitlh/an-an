#ifndef _ENCODER_H
#define _ENCODER_H

#include "main.h"
#include "tim.h"

void Encoder_Init(void);
int16_t Encoder_GetPulse( uint8_t motor_id);

#endif
