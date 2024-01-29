#include "stm32f10x.h"
#include "bsp_usart.h"
#include "ff.h"
#include "string.h"

FATFS fs;													/* FatFs文件系统对象 */
FIL fnew;													/* 文件对象 */
FRESULT res_flash;                /* 文件操作结果 */
UINT fnum;            					  /* 文件成功读写数量 */


void FatFs_test(void)
{
  USART_Config();	
  printf("******** 这是一个SPI FLASH 文件系统实验 *******\r\n");
  printf("\r\n 使用指南者底板时 左上角排针位置 不要将PC0盖有跳帽 防止影响PC0做SPIFLASH片选脚 \r\n");
  
	//在外部SPI Flash挂载文件系统，文件系统挂载时会对SPI设备初始化
	res_flash = f_mount(&fs,"1:",1);
	
		if(res_flash!=FR_OK)
		{
			printf("！！外部Flash挂载文件系统失败。(%d)\r\n",res_flash);
			printf("！！可能原因：SPI Flash初始化不成功。\r\n");
			while(1);
		}
		else
		{
			printf("》文件系统挂载成功，可以进行测试\r\n");
			while(1);
		}
}
