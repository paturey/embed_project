/**
  *********************************************************************
  * @file    MainTask.c
  * @author  fire
  * @version V1.0
  * @date    2019-xx-xx
  * @brief   FreeRTOS v9.0.0 + STM32 ����ģ��
  *********************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ��  STM32 F103 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
/*******************************************************************************
 * ������ͷ�ļ�
 ******************************************************************************/

/* STemWINͷ�ļ� */
#include "GUI.h"
#include "DIALOG.h"
#include <stdio.h>
#include "bsp_xpt2046_lcd.h"
#include "FreeRTOS.h"
#include "task.h"
/*******************************************************************************
 * ����
 ******************************************************************************/
/**
  * @brief GUI������
  * @note ��
  * @param ��
  * @retval ��
  */
void MainTask(void)
{
  GUI_Init();
  GUI_SetBkColor(GUI_RED);
  GUI_Clear();
}

	/*
	GUI_Init();
  GUI_SetBkColor(GUI_RED);
  GUI_Clear();
  
  GUI_CURSOR_Show();

  GUI_SetColor(GUI_WHITE);
  GUI_SetFont(GUI_FONT_24B_1);
  
  GUI_DispString("temp\r\nUse FreeRTOS");
  printf("hello world");
	
  while(1)
  {
    GUI_Delay(1000);
  }
	*/

