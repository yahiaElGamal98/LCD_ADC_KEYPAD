/*
 * implementation.c
 *
 * Created: 1/16/2022 5:05:26 PM
 *  Author: No. 01
 */ 

#include "../../01-LIB/STD_types.h"
#include "../../01-LIB/Registers.h"
#include "../../02-MCAL/DIO_git/DIO.h"
#include "Config.h"
#include "Interface.h"

/**LCD PINS CONFIGURATIONS USING DIO**/
ST_DIO_config_t ST_LCD_RS_config = {LCD_PORT,LCD_RS_PIN,OUTPUT};
ST_DIO_config_t ST_LCD_RW_config = {LCD_PORT,LCD_RW_PIN,OUTPUT};
ST_DIO_config_t ST_LCD_E_config = {LCD_PORT,LCD_ENABLE_PIN,OUTPUT};
ST_DIO_config_t ST_LCD_D4_config = {LCD_PORT,LCD_D4_PIN,OUTPUT};
ST_DIO_config_t ST_LCD_D5_config = {LCD_PORT,LCD_D5_PIN,OUTPUT};
ST_DIO_config_t ST_LCD_D6_config = {LCD_PORT,LCD_D6_PIN,OUTPUT};
ST_DIO_config_t ST_LCD_D7_config = {LCD_PORT,LCD_D7_PIN,OUTPUT};

//rough delay in milliseconds (validated by LEDs) 
void msdelay(unsigned int time)
{
	volatile unsigned int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0; j<450; j++)
		{
			
		}
	}
}

//LCD initialization
void LCD_init(void)
{
	/*Configuring pins as output*/
	DIO_init(&ST_LCD_RW_config); 
	DIO_init(&ST_LCD_RS_config);
	DIO_init(&ST_LCD_E_config);
	DIO_init(&ST_LCD_D4_config);
	DIO_init(&ST_LCD_D5_config);
	DIO_init(&ST_LCD_D6_config);
	DIO_init(&ST_LCD_D7_config);
	/*Awaiting LCD to settle*/
	msdelay(50);
	//LCD initializes and awaits an 8 bit instruction, this is to tell it that it will be operating 4 bits
	LCD_sendStartCmd(BIT_MODE);
	msdelay(5);
	//Initialize starting modes
	LCD_sendCmd(BIT_MODE);
	msdelay(5);
	LCD_sendCmd(ON_CONTROL);
	msdelay(1);
	LCD_sendCmd(DISPLAY_CLEAR);
	msdelay(1);
	LCD_sendCmd(ENTRY_MODE);
	msdelay(3);
	
}
void LCD_sendStartCmd(uint8_t u8_cmd)
{
	//send only the high 4 bits and stop so as to tell the LCD we will be working in 4 bit mode
	DIO_port(LCD_PORT,(u8_cmd & 0xF0));
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,HIGH);
	DIO_write(LCD_PORT,LCD_RW_PIN,LOW);
	DIO_write(LCD_PORT,LCD_RS_PIN,LOW);
	msdelay(1);
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,LOW);
	msdelay(1);
}
void LCD_sendCmd(uint8_t u8_cmd)
{
	//send high nibble
	DIO_port(LCD_PORT,(u8_cmd & 0xF0));
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,HIGH);
	DIO_write(LCD_PORT,LCD_RW_PIN,LOW);
	DIO_write(LCD_PORT,LCD_RS_PIN,LOW);
	msdelay(1);
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,LOW);
	msdelay(1);
	//send low nibble
	DIO_port(LCD_PORT,(u8_cmd <<4));
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,HIGH);
	DIO_write(LCD_PORT,LCD_RW_PIN,LOW);
	DIO_write(LCD_PORT,LCD_RS_PIN,LOW);
	msdelay(1);
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,LOW);
	msdelay(1);

}
void LCD_goToXY(uint8_t line, uint8_t pos)
{
	if(LINE_1==line)
	{
		LCD_sendCmd(HOME_POSITION_LINE_1+pos);
	}
	else if(LINE_2==line)
	{
		LCD_sendCmd(HOME_POSITION_LINE_2+pos);
	}
	
}
void LCD_sendChar(uint8_t u8_char)
{
	DIO_port(LCD_PORT,(u8_char & 0xF0));
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,HIGH);
	DIO_write(LCD_PORT,LCD_RW_PIN,LOW);
	DIO_write(LCD_PORT,LCD_RS_PIN,HIGH);
	msdelay(1);
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,LOW);
	msdelay(1);
	
	DIO_port(LCD_PORT,(u8_char <<4));
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,HIGH);
	DIO_write(LCD_PORT,LCD_RW_PIN,LOW);
	DIO_write(LCD_PORT,LCD_RS_PIN,HIGH);
	msdelay(1);
	DIO_write(LCD_PORT,LCD_ENABLE_PIN,LOW);
	msdelay(1);
}
void LCD_sendStr(sint8_t au8_str[])
{
	uint8_t u8_index=0;
	while(au8_str[u8_index]!='\0')
	{
		LCD_sendChar(au8_str[u8_index]);
		u8_index++;
	}
}
