#include "GUI.h"
#include "FreeRTOS.h"
#include "task.h"

void Touch_Task(void* parameter)
{
	while(1)
	{
		GUI_TOUCH_Exec();//��������ʱɨ��
		vTaskDelay(10);
	}
}
