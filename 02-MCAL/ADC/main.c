/*
 * ADC.c
 *
 * Created: 1/18/2022 4:12:38 PM
 * Author : No. 01
 */ 
#include <stdlib.h>

#include "01-LIB/STD_types.h"
#include "01-LIB/Registers.h"
#include "02-MCAL/ADC/ADC_Config.h"
#include "02-MCAL/ADC/ADC_interface.h"
#include "03-HAL/LCD/Interface.h"


int main()
{
	char String[5];
	uint16_t value;

	ADC_init();
	LCD_init();			/* Initialization of LCD */
	LCD_sendStr("TEMP value");	/* Write string on 1st line of LCD */
	
	while(1)
	{
		
		LCD_goToXY(LINE_2,12);	/* LCD16x2 cursor position */
		ADC_read(0,&value);	/* Read ADC channel 0 */
		value=value*4.88;
		value=value/10;
		itoa(value,String,10);	/* Integer to string conversion */
		LCD_sendStr(String);
		LCD_sendStr("  ");
		msdelay(200);
	}
	return 0;

}

