#include "pid.h"

// PID初始化
void PID_Init(PID_TypeDef *pid, float p, float i, float d) {
    pid->Kp = p;
    pid->Ki = i;
    pid->Kd = d;
    pid->target = 0;
    pid->actual = 0;
    pid->error = 0;
    pid->last_error = 0;
    pid->pwm_out = 0;
}

// 增量式PID计算
int16_t PID_Calc(PID_TypeDef *pid, float target, float actual) {
    pid->target = target;
    pid->actual = actual;
    
    // 当前误差 = 目标 - 实际
    pid->error = pid->target - pid->actual;
    
    // 增量式公式：Out = Kp*(e - e_last) + Ki*e + Kd*(e - 2*e_last + e_last_last)
    // 为简化代码，这里使用位置式思路，但用累加PWM输出（本质是增量）
    // 如果实际值小于目标，error为正，PWM增加
    
    // 这里用最经典的**位置式PID**，并通过积分限幅防止超调
    static float integral = 0;
    integral += pid->error;
    
    // 积分限幅（防止积分饱和）
    if(integral > 5000) integral = 5000;
    if(integral < -5000) integral = -5000;

    pid->pwm_out = (pid->Kp * pid->error) + (pid->Ki * integral) + (pid->Kd * (pid->error - pid->last_error));
    pid->last_error = pid->error;
    
    // 限制输出最大PWM（与你电机PWM一致，通常是1000或定时器ARR）
    if(pid->pwm_out > 1000) pid->pwm_out = 1000;
    if(pid->pwm_out < -1000) pid->pwm_out = -1000;

    return (int16_t)pid->pwm_out;
}
















