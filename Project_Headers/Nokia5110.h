/*
 * Nokia5110.h
 *
 *  Created on: Sep 13, 2016
 *      Author: rinco
 */

#include "DataType.h"

#ifndef NOKIA5110_H_
#define NOKIA5110_H_


#define LCD_RST PTBD_PTBD5
#define LCD_RSTD PTBDD_PTBDD5

#define LCD_CE PTBD_PTBD3
#define LCD_CED PTBDD_PTBDD3

#define LCD_DC PTBD_PTBD7
#define LCD_DCD PTBDD_PTBDD7

#define LCD_DCIN PTBD_PTBD1
#define LCD_DCIND PTBDD_PTBDD1

#define LCD_CLK PTBD_PTBD2
#define LCD_CLKD PTBDD_PTBDD2

#define LCD_LIGHT PTBD_PTBD6
#define LCD_LIGHTD PTBDD_PTBDD6

#define LCD_COMMAND 0
#define LCD_DATA    1

//MOSI2  PTB1/MOSI2
//MISO2  PTB0/MISO2
//SPSCK2 PTB2/SPSCK2
//SS2    PTB3/SS2

/* definitions */
// General commands
#define PCD8544_POWERDOWN			0x04
#define PCD8544_ENTRYMODE			0x02
#define PCD8544_EXTENDEDINSTRUCTION	0x01
#define PCD8544_DISPLAYBLANK		0x00
#define PCD8544_DISPLAYNORMAL		0x04
#define PCD8544_DISPLAYALLON		0x01
#define PCD8544_DISPLAYINVERTED		0x05
// Normal instruction set
#define PCD8544_FUNCTIONSET			0x20
#define PCD8544_DISPLAYCONTROL		0x08
#define PCD8544_SETYADDR			0x40
#define PCD8544_SETXADDR			0x80
// Extended instruction set
#define PCD8544_SETTEMP				0x04
#define PCD8544_SETBIAS				0x10
#define PCD8544_SETVOP				0x80
// Display presets
#define LCD_BIAS					0x03	// Range: 0-7 (0x00-0x07)
#define LCD_TEMP					0x02	// Range: 0-3 (0x00-0x03)
#define LCD_CONTRAST				0x46	// Range: 0-127 (0x00-0x7F)

//extern UINT8 cursor_x, cursor_y;

void Nokia5110_Init(void);
void Send_command(byte command);
void Send_data(char data);
void Nokia_reset(void);
void setContrast(int contrast);
void LCDWait(UINT8 w);
void Backlight(void);
void gotoXY(char x, char y);
void TooBacklight();
void updateDisplay(void);



#endif /* NOKIA5110_H_ */


