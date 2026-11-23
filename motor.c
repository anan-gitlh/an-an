#include "motor.h"
#include "tim.h"

void Motor_Init(void) {
	HAL_TIM_PWM_Start( &htim1 , TIM_CHANNEL_1 );
	HAL_TIM_PWM_Start( &htim1 , TIM_CHANNEL_2 );
	HAL_TIM_PWM_Start( &htim1 , TIM_CHANNEL_3 );
	HAL_TIM_PWM_Start( &htim1 , TIM_CHANNEL_4 );
	HAL_TIM_PWM_Start( &htim8 , TIM_CHANNEL_1 );
	HAL_TIM_PWM_Start( &htim8 , TIM_CHANNEL_2 );
	HAL_TIM_PWM_Start( &htim8 , TIM_CHANNEL_3 );
	HAL_TIM_PWM_Start( &htim8 , TIM_CHANNEL_4 );
	
}

void Motor_SetSpeed( Motor_ID motor ,int16_t speed )
{    if( speed > 1000) speed = 1000;
	   if( speed < -1000) speed = -1000;


     switch ( motor ){
			 case MOTOR_LA :
			 if ( speed >= 0 ) {
				 __HAL_TIM_SET_COMPARE( &htim1 , TIM_CHANNEL_1 , speed );//正转
				 __HAL_TIM_SET_COMPARE( &htim1 , TIM_CHANNEL_2 , 0 );
			 }
				 else {
           __HAL_TIM_SET_COMPARE( &htim1 , TIM_CHANNEL_1 , 0 );
					 __HAL_TIM_SET_COMPARE( &htim1 , TIM_CHANNEL_2 , -speed );//反转
				 }
				 break ;
			 case MOTOR_RA :
				 if ( speed >= 0 ){
          __HAL_TIM_SET_COMPARE( &htim1 , TIM_CHANNEL_3 , speed );//正转
          __HAL_TIM_SET_COMPARE( &htim1 , TIM_CHANNEL_4 , 0 );
				 }
				  else { 
						__HAL_TIM_SET_COMPARE( &htim1 , TIM_CHANNEL_3 , 0);
						__HAL_TIM_SET_COMPARE( &htim1 , TIM_CHANNEL_4 , -speed );//反转
					}
					break ;	
				case MOTOR_LR :
			 if ( speed >= 0 ) {
				 __HAL_TIM_SET_COMPARE( &htim8 , TIM_CHANNEL_1 , speed );//正转
				 __HAL_TIM_SET_COMPARE( &htim8 , TIM_CHANNEL_2 , 0 );
			 }
				 else {
           __HAL_TIM_SET_COMPARE( &htim8, TIM_CHANNEL_1 , 0 );
					 __HAL_TIM_SET_COMPARE( &htim8 , TIM_CHANNEL_2 , -speed );//反转
				 }
				 break ;	 
				case MOTOR_RR :
				 if ( speed >= 0 ){
          __HAL_TIM_SET_COMPARE( &htim8 , TIM_CHANNEL_3 , speed );//正转
          __HAL_TIM_SET_COMPARE( &htim8 , TIM_CHANNEL_4 , 0 );
				 }
				  else { 
						__HAL_TIM_SET_COMPARE( &htim8 , TIM_CHANNEL_3 , 0);
						__HAL_TIM_SET_COMPARE( &htim8 , TIM_CHANNEL_4 , -speed );//反转
					}
					break ;	

				}

			}	

				 
			 
	



	

