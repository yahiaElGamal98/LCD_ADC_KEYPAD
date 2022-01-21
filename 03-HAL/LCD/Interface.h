/*
 * Interface.h
 *
 * Created: 1/16/2022 5:04:03 PM
 *  Author: No. 01
 */ 


#ifndef INTERFACE_H_
#define INTERFACE_H_

/*MACROS FOR LINE 1 & 2 in the LCD**/
#define LINE_1 0
#define LINE_2 1

/***LCD COMMANDS***/
#define BIT_MODE ((uint8_t)(0b00101000))	//FUNCTION SET, 4 bit, 2-line display
#define ON_CONTROL ((uint8_t)(0b00001110)) //DISPLAY ON, CURSOR ON, BLINKING OFF
#define DISPLAY_CLEAR ((uint8_t)(0b00000001)) //CLEAR DISPLAY
#define ENTRY_MODE ((uint8_t)(0b00000110))  //INCREMENT CURSOR
#define HOME_POSITION_LINE_1 ((uint8_t)(0b10000000))
#define HOME_POSITION_LINE_2 ((uint8_t)(0b11000000))

//initialize LCD
void LCD_init(void);
//send commands to LCD using 4 bit mode
void LCD_sendCmd(uint8_t u8_cmd);	
//special function to send only the highest nibble of command for use in startup ONLY to avoid buggy startup
void LCD_sendStartCmd(uint8_t u8_cmd);	
//function to send string to LCD (calls sendChar)
void LCD_sendStr(sint8_t* u8_str);	
//function that sends a single character to LCD
void LCD_sendChar(uint8_t u8_char);
//function that sends starting position and line
void LCD_goToXY(uint8_t line, uint8_t pos);
//delay function for usage in the LCD
void msdelay(uint8_t time);




#endif /* INTERFACE_H_ */