#include "test.h"
#include "FreeRTOS.h"
#include "task.h"


void test(void) {
		taskENTER_CRITICAL();
    char cStr [ 30 ];
    u8 ucArray_ID [ 4 ];                                                                                     
    char  ucStatusReturn;    //返回状态                                       
		spi_MFRC_init();
		RC522_Rese();
    RC522_Config_Type('A');
    while (1) { 
		/* 寻卡（方式：范围内全部），第一次寻卡失败后再进行一次，寻卡成功时卡片序列传入数组ucArray_ID中 */
		    if ( ( ucStatusReturn = PcdRequest( PICC_REQALL, ucArray_ID )) != MI_OK ) {
				    ucStatusReturn = PcdRequest ( PICC_REQALL, ucArray_ID );
				}
				printf("%c", ucStatusReturn);
				if (ucStatusReturn == MI_OK) {
			    /* 防冲突操作，被选中的卡片序列传入数组ucArray_ID中 */
			    if ( PcdAnticoll ( ucArray_ID ) == MI_OK ) {
				      sprintf ( cStr, "The Card ID is: %02X%02X%02X%02X", ucArray_ID [ 0 ], ucArray_ID [ 1 ], ucArray_ID [ 2 ], ucArray_ID [ 3 ] );				
			        printf ("%s\r\n",cStr ); 
			    }
		    }

   }
   taskEXIT_CRITICAL();
}
