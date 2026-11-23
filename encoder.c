#include "encoder.h"
 
void Encoder_Init(void)
{
	HAL_TIM_Encoder_Start ( &htim2 , TIM_CHANNEL_ALL );
	HAL_TIM_Encoder_Start ( &htim3 , TIM_CHANNEL_ALL );
	HAL_TIM_Encoder_Start ( &htim4 , TIM_CHANNEL_ALL );
	HAL_TIM_Encoder_Start ( &htim5 , TIM_CHANNEL_ALL );
}

//«Â¡„≤¢∂¡»°±‡¬Î∆˜
int16_t Encoder_GetPulse( uint8_t motor_id )
 {
	 int16_t count = 0 ;
	 switch (motor_id)
	 {
		 case 1:count = __HAL_TIM_GET_COUNTER (&htim2);__HAL_TIM_SET_COUNTER( &htim2 , 0 ); break ;
		 case 2:count = __HAL_TIM_GET_COUNTER (&htim3);__HAL_TIM_SET_COUNTER( &htim3 , 0 ); break ;
     case 3:count = __HAL_TIM_GET_COUNTER (&htim4);__HAL_TIM_SET_COUNTER( &htim4 , 0 ); break ;
		 case 4:count = __HAL_TIM_GET_COUNTER (&htim5);__HAL_TIM_SET_COUNTER( &htim5 , 0 ); break ;
	 }
	 return count;
 }
 