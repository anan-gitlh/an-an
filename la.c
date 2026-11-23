#include "la.h"
#include "usart.h"
#include "move.h"
#include "servo.h"
#include <stdio.h>
#include <string.h>


uint8_t rx_data;  //单字节
char rx_buffer[64];   //箱子
uint8_t rx_index = 0;   //目录
extern uint32_t last_cmd_time;

//控制舵机
void Control_Servo(uint8_t id , uint8_t angle ) 
  {
		switch (id)
		{ 
			case 1 :Servo_SetAngle ( &htim9 , TIM_CHANNEL_1 , angle ); break ;//底板
      case 2 :Servo_SetAngle ( &htim9 , TIM_CHANNEL_2 , angle ); break ;//肩膀
      case 3 :Servo_SetAngle ( &htim12 , TIM_CHANNEL_1 , angle ); break ;//手抽
      case 4 :Servo_SetAngle ( &htim12 , TIM_CHANNEL_2 , angle ); break ;//夹爪
      case 5 :Servo_SetAngle ( &htim10 , TIM_CHANNEL_1 , angle ); break ;//前
      case 6 :Servo_SetAngle ( &htim11 , TIM_CHANNEL_1 , angle ); break ;//前
		}
		
	}
	
		// 解析函数
void Parse_Command(char *cmd) {
    int vx, vy, omega, id , angle ;

    // (Mecanum底盘控制) 格式如：M,500,0,0
    if (cmd[0] == 'M') {
        if (sscanf(cmd, "M,%d,%d,%d", &vx, &vy, &omega) == 3) {
            Mecanum_Move(vx, vy, omega);
        }
    }
    //  (Servo舵机控制) 格式如：S,1,90
    else if (cmd[0] == 'S') {
        if (sscanf(cmd, "S,%d,%d", &id , &angle) == 2) {
            Control_Servo(id, angle);
        }
    }
    // STOP
    else if (strncmp(cmd, "STOP", 4) == 0) {
        Move_Stop();
    }
}

// 蓝牙串口接收
void LA_Init(void) {
    HAL_UART_Receive_IT(&huart1, &rx_data, 1);
}

// 串口接收中断回调函数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if ( huart->Instance == USART1 ) {
        // 如果没收到回车/换行，就把字符存起来
        if ( rx_data != '\n' && rx_data != '\r' ) {
            rx_buffer[rx_index++] = rx_data;
            if ( rx_index >= 64 ) rx_index = 0; // 防溢出
        } 
				else 
				{
            // 处理多条指令
            if ( rx_index > 0 ) {
                rx_buffer[rx_index] = '\0'; // 加上字符串结束符
               char *cmd_token = strtok ( rx_buffer , ";" );
							 while ( cmd_token  != NULL )
							 {
							   Parse_Command ( cmd_token );
								 cmd_token = strtok ( NULL , ";" );
							 }
							 
							 
							 last_cmd_time = HAL_GetTick(); 
							 
                
            }
						
						rx_index =  0 ;
        }
        // 重新开启接收中断（极其重要，HAL库收完一次必须重新开启）
        HAL_UART_Receive_IT(&huart1, &rx_data, 1);
			}
}

		
			
			
			
			
			
			
			
			
			
			
			
			
				

