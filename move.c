#include "move.h"


int16_t Limit_Speed( int32_t speed )
{
	if ( speed > 1000 )  return 1000 ;
	if ( speed < -1000 )  return  -1000 ;
	return (int16_t) speed ;
}


extern int16_t target_speed[4];

void Mecanum_Move ( int16_t vx , int16_t vy , int16_t omega )
{
	//麦轮公式
	int32_t speed_la = vx - vy - omega ;//左前
	int32_t speed_ra = vx + vy + omega ;//右前
	int32_t speed_lr = vx + vy - omega ;//左后
	int32_t speed_rr = vx - vy + omega ;//右后
	
	
	target_speed [0] = Limit_Speed (speed_la );
  target_speed [1] = Limit_Speed (speed_ra );
	target_speed [2] = Limit_Speed (speed_lr );
	target_speed [3] = Limit_Speed (speed_rr );
}

void Move_Stop(void)
{
	target_speed [0] = 0;
	target_speed [1] = 0;
	target_speed [2] = 0;
	target_speed [3] = 0;
	
	
	Motor_SetSpeed ( MOTOR_LA , 0 );
	Motor_SetSpeed ( MOTOR_RA , 0 );
	Motor_SetSpeed ( MOTOR_LR , 0 );
	Motor_SetSpeed ( MOTOR_RR , 0 );
}
