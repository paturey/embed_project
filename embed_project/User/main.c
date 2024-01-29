#include "stm32f10x.h"   
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <stdio.h>
#include "MainTask.h"
#include "motor_sg90.h"
#include "bsp_usart.h"
#include "bsp_ili9341_lcd.h"
#include "bsp_xpt2046_lcd.h"
#include "bsp_spi_flash.h"
#include "bsp_fsmc_sram.h"
#include "PWM.h"
#include "Touch_Task.h"
#include "WIDGET_ButtonSimple.h"
#include "bsp_led.h"
#include "FatFs_test.h"
#include "bsp_key.h"
#include "test.h"

static void AppTaskCreate(void);
TaskHandle_t AppTaskCreate_Handle = NULL;
TaskHandle_t Touch_Task_Handle = NULL;
TaskHandle_t DemoRedraw = NULL;
TaskHandle_t FatFs_test_Handle = NULL;
TaskHandle_t test_Handle = NULL;

char _key[20] = "1234567890"; 


typedef void (*TaskFunction_t)( void * );
static void BSP_Init(void)
{
  
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE);
  
	
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );
	
	
	USART_Config();
  
  
	XPT2046_Init();
  
  
  ILI9341_Init();
	PWM_Init();
	//GUI_Init();
	LED_GPIO_Config();
	key1_init();
}

int main(void)
{
	BaseType_t xReturn = pdPASS;

	BSP_Init();
	
	xReturn = xTaskCreate((TaskFunction_t )AppTaskCreate,  
                        (const char*    )"AppTaskCreate",
                        (uint16_t       )512,  
                        (void*          )NULL,
                        (UBaseType_t    )1, 
                        (TaskHandle_t*  )&AppTaskCreate_Handle);												
	if(pdPASS == xReturn)
    	vTaskStartScheduler(); 
	else
    	return -1;  
  
	while(1);    
}


static void AppTaskCreate(void)
{
    BaseType_t xReturn = pdPASS;
  
	  taskENTER_CRITICAL();
    /*
	  xReturn = xTaskCreate((TaskFunction_t)Touch_Task,
											 (const char*      )"Touch_Task",
											 (uint16_t         )256,     
											 (void*            )NULL,    
											 (UBaseType_t      )3,       
											 (TaskHandle_t*     )&Touch_Task_Handle);
	
	  xReturn = xTaskCreate((TaskFunction_t)CreateFramewin_task,
											 (const char*      )"DemoRedraw",
											 (uint16_t         )2048,     
											 (void*            )NULL,    
											 (UBaseType_t      )2,       
											 (TaskHandle_t*     )&DemoRedraw);	
    */
    xReturn = xTaskCreate((TaskFunction_t)test,
											    (const char*      )"test",
											    (uint16_t         )1024,     
											    (void*            )NULL,    
											    (UBaseType_t      )2,       
											    (TaskHandle_t*     )&test_Handle);
	  vTaskDelete(AppTaskCreate_Handle);
	  taskEXIT_CRITICAL();
}

void EXTI0_IRQHandler(void)
{
	if (EXTI_GetITStatus(KEY1_INT_EXTI_LINE) != RESET) {
        LED1_TOGGLE;
        EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);
    }
}