#include "PWM.h"
#include "stm32f10x.h"  
#include "FreeRTOS.h"
#include "task.h"

uint16_t pwm = 50;
void motor_sg90(void)
{
	while(1)
	{
		for(pwm = 50; pwm <= 250; pwm++ )
		{
			PWM_SetCompare1(pwm);
			vTaskDelay(5);
		}
		
		for(pwm = 250; pwm >= 50; pwm-- )
		{
			PWM_SetCompare1(pwm);
			vTaskDelay(5);
		}
	}
	
}
