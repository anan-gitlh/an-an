#include "servo.h"

void Servo_Init(void) {
	HAL_TIM_PWM_Start( &htim9 , TIM_CHANNEL_1 );
	HAL_TIM_PWM_Start( &htim9 , TIM_CHANNEL_2 );
	HAL_TIM_PWM_Start( &htim10 , TIM_CHANNEL_1 );
	HAL_TIM_PWM_Start( &htim11 , TIM_CHANNEL_1 );
	HAL_TIM_PWM_Start( &htim12 , TIM_CHANNEL_1 );
	HAL_TIM_PWM_Start( &htim12 , TIM_CHANNEL_2 );
	//给舵机安排角度
	Servo_SetAngle( &htim9 , TIM_CHANNEL_1 , 90 );
    Servo_SetAngle( &htim9 , TIM_CHANNEL_2 , 90 );
    Servo_SetAngle( &htim10 , TIM_CHANNEL_1 , 90 );
    Servo_SetAngle( &htim11 , TIM_CHANNEL_1 , 90 );
    Servo_SetAngle( &htim12 , TIM_CHANNEL_1 , 90 );
    Servo_SetAngle( &htim12 , TIM_CHANNEL_2 , 90 );
}

void Servo_SetAngle(TIM_HandleTypeDef *htim , uint32_t Channel , uint8_t angle)//舵机旋转的角度
   { 
		 if ( angle > 180 ) angle = 180 ;
		 uint16_t pulse = 500 + (angle * 2000)/180 ;
		 __HAL_TIM_SET_COMPARE ( htim , Channel , pulse );
		 
	 }
	 