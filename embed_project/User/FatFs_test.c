#include "stm32f10x.h"
#include "bsp_usart.h"
#include "ff.h"
#include "string.h"

FATFS fs;													/* FatFs�ļ�ϵͳ���� */
FIL fnew;													/* �ļ����� */
FRESULT res_flash;                /* �ļ�������� */
UINT fnum;            					  /* �ļ��ɹ���д���� */


void FatFs_test(void)
{
  USART_Config();	
  printf("******** ����һ��SPI FLASH �ļ�ϵͳʵ�� *******\r\n");
  printf("\r\n ʹ��ָ���ߵװ�ʱ ���Ͻ�����λ�� ��Ҫ��PC0������ñ ��ֹӰ��PC0��SPIFLASHƬѡ�� \r\n");
  
	//���ⲿSPI Flash�����ļ�ϵͳ���ļ�ϵͳ����ʱ���SPI�豸��ʼ��
	res_flash = f_mount(&fs,"1:",1);
	
		if(res_flash!=FR_OK)
		{
			printf("�����ⲿFlash�����ļ�ϵͳʧ�ܡ�(%d)\r\n",res_flash);
			printf("��������ԭ��SPI Flash��ʼ�����ɹ���\r\n");
			while(1);
		}
		else
		{
			printf("���ļ�ϵͳ���سɹ������Խ��в���\r\n");
			while(1);
		}
}
