/*
 * Nokia5110.c
 *
 *  Created on: Sep 13, 2016
 *      Author: rinco
 */

#include "SPI.h"
#include "Nokia5110.h"

//CHARACTERS DISPLAYABLES MATRIX
static const byte ASCII[][5] = {
  // First 32 characters (0x00-0x19) are ignored. These are
  // non-displayable, control characters.
   0x00, 0x00, 0x00, 0x00, 0x00, // 0x20
   0x00, 0x00, 0x5f, 0x00, 0x00, // 0x21 !
   0x00, 0x07, 0x00, 0x07, 0x00, // 0x22 "
   0x14, 0x7f, 0x14, 0x7f, 0x14, // 0x23 #
   0x24, 0x2a, 0x7f, 0x2a, 0x12, // 0x24 $
   0x23, 0x13, 0x08, 0x64, 0x62, // 0x25 %
   0x36, 0x49, 0x55, 0x22, 0x50, // 0x26 &
   0x00, 0x05, 0x03, 0x00, 0x00, // 0x27 '
   0x00, 0x1c, 0x22, 0x41, 0x00, // 0x28 (
   0x00, 0x41, 0x22, 0x1c, 0x00, // 0x29 )
   0x14, 0x08, 0x3e, 0x08, 0x14, // 0x2a *
   0x08, 0x08, 0x3e, 0x08, 0x08, // 0x2b +
   0x00, 0x50, 0x30, 0x00, 0x00, // 0x2c ,
   0x08, 0x08, 0x08, 0x08, 0x08, // 0x2d -
   0x00, 0x60, 0x60, 0x00, 0x00, // 0x2e .
   0x20, 0x10, 0x08, 0x04, 0x02, // 0x2f /
   0x3e, 0x51, 0x49, 0x45, 0x3e, // 0x30 0
   0x00, 0x42, 0x7f, 0x40, 0x00, // 0x31 1
   0x42, 0x61, 0x51, 0x49, 0x46, // 0x32 2
   0x21, 0x41, 0x45, 0x4b, 0x31, // 0x33 3
   0x18, 0x14, 0x12, 0x7f, 0x10, // 0x34 4
   0x27, 0x45, 0x45, 0x45, 0x39, // 0x35 5
   0x3c, 0x4a, 0x49, 0x49, 0x30, // 0x36 6
   0x01, 0x71, 0x09, 0x05, 0x03, // 0x37 7
   0x36, 0x49, 0x49, 0x49, 0x36, // 0x38 8
   0x06, 0x49, 0x49, 0x29, 0x1e, // 0x39 9
   0x00, 0x36, 0x36, 0x00, 0x00, // 0x3a :
   0x00, 0x56, 0x36, 0x00, 0x00, // 0x3b ;
   0x08, 0x14, 0x22, 0x41, 0x00, // 0x3c <
   0x14, 0x14, 0x14, 0x14, 0x14, // 0x3d =
   0x00, 0x41, 0x22, 0x14, 0x08, // 0x3e >
   0x02, 0x01, 0x51, 0x09, 0x06, // 0x3f ?
   0x32, 0x49, 0x79, 0x41, 0x3e, // 0x40 @
   0x7e, 0x11, 0x11, 0x11, 0x7e, // 0x41 A
   0x7f, 0x49, 0x49, 0x49, 0x36, // 0x42 B
   0x3e, 0x41, 0x41, 0x41, 0x22, // 0x43 C
   0x7f, 0x41, 0x41, 0x22, 0x1c, // 0x44 D
   0x7f, 0x49, 0x49, 0x49, 0x41, // 0x45 E
   0x7f, 0x09, 0x09, 0x09, 0x01, // 0x46 F
   0x3e, 0x41, 0x49, 0x49, 0x7a, // 0x47 G
   0x7f, 0x08, 0x08, 0x08, 0x7f, // 0x48 H
   0x00, 0x41, 0x7f, 0x41, 0x00, // 0x49 I
   0x20, 0x40, 0x41, 0x3f, 0x01, // 0x4a J
   0x7f, 0x08, 0x14, 0x22, 0x41, // 0x4b K
   0x7f, 0x40, 0x40, 0x40, 0x40, // 0x4c L
   0x7f, 0x02, 0x0c, 0x02, 0x7f, // 0x4d M
   0x7f, 0x04, 0x08, 0x10, 0x7f, // 0x4e N
   0x3e, 0x41, 0x41, 0x41, 0x3e, // 0x4f O
   0x7f, 0x09, 0x09, 0x09, 0x06, // 0x50 P
   0x3e, 0x41, 0x51, 0x21, 0x5e, // 0x51 Q
   0x7f, 0x09, 0x19, 0x29, 0x46, // 0x52 R
   0x46, 0x49, 0x49, 0x49, 0x31, // 0x53 S
   0x01, 0x01, 0x7f, 0x01, 0x01, // 0x54 T
   0x3f, 0x40, 0x40, 0x40, 0x3f, // 0x55 U
   0x1f, 0x20, 0x40, 0x20, 0x1f, // 0x56 V
   0x3f, 0x40, 0x38, 0x40, 0x3f, // 0x57 W
   0x63, 0x14, 0x08, 0x14, 0x63, // 0x58 X
   0x07, 0x08, 0x70, 0x08, 0x07, // 0x59 Y
   0x61, 0x51, 0x49, 0x45, 0x43, // 0x5a Z
   0x00, 0x7f, 0x41, 0x41, 0x00, // 0x5b [
   0x02, 0x04, 0x08, 0x10, 0x20, // 0x5c \ (keep this to escape the backslash)
   0x00, 0x41, 0x41, 0x7f, 0x00, // 0x5d ]
   0x04, 0x02, 0x01, 0x02, 0x04, // 0x5e ^
   0x40, 0x40, 0x40, 0x40, 0x40, // 0x5f _
   0x00, 0x01, 0x02, 0x04, 0x00, // 0x60 `
   0x20, 0x54, 0x54, 0x54, 0x78, // 0x61 a
   0x7f, 0x48, 0x44, 0x44, 0x38, // 0x62 b
   0x38, 0x44, 0x44, 0x44, 0x20, // 0x63 c
   0x38, 0x44, 0x44, 0x48, 0x7f, // 0x64 d
   0x38, 0x54, 0x54, 0x54, 0x18, // 0x65 e
   0x08, 0x7e, 0x09, 0x01, 0x02, // 0x66 f
   0x0c, 0x52, 0x52, 0x52, 0x3e, // 0x67 g
   0x7f, 0x08, 0x04, 0x04, 0x78, // 0x68 h
   0x00, 0x44, 0x7d, 0x40, 0x00, // 0x69 i
   0x20, 0x40, 0x44, 0x3d, 0x00, // 0x6a j
   0x7f, 0x10, 0x28, 0x44, 0x00, // 0x6b k
   0x00, 0x41, 0x7f, 0x40, 0x00, // 0x6c l
   0x7c, 0x04, 0x18, 0x04, 0x78, // 0x6d m
   0x7c, 0x08, 0x04, 0x04, 0x78, // 0x6e n
   0x38, 0x44, 0x44, 0x44, 0x38, // 0x6f o
   0x7c, 0x14, 0x14, 0x14, 0x08, // 0x70 p
   0x08, 0x14, 0x14, 0x18, 0x7c, // 0x71 q
   0x7c, 0x08, 0x04, 0x04, 0x08, // 0x72 r
   0x48, 0x54, 0x54, 0x54, 0x20, // 0x73 s
   0x04, 0x3f, 0x44, 0x40, 0x20, // 0x74 t
   0x3c, 0x40, 0x40, 0x20, 0x7c, // 0x75 u
   0x1c, 0x20, 0x40, 0x20, 0x1c, // 0x76 v
   0x3c, 0x40, 0x30, 0x40, 0x3c, // 0x77 w
   0x44, 0x28, 0x10, 0x28, 0x44, // 0x78 x
   0x0c, 0x50, 0x50, 0x50, 0x3c, // 0x79 y
   0x44, 0x64, 0x54, 0x4c, 0x44, // 0x7a z
   0x00, 0x08, 0x36, 0x41, 0x00, // 0x7b {
   0x00, 0x00, 0x7f, 0x00, 0x00, // 0x7c |
   0x00, 0x41, 0x36, 0x08, 0x00, // 0x7d }
   0x10, 0x08, 0x08, 0x10, 0x08, // 0x7e ~
   0x78, 0x46, 0x41, 0x46, 0x78  // 0x7f DEL*/
};

const UINT8 LCDWIDTH = 84;
const UINT8 LCDHEIGHT = 48;
unsigned char rowdata; //PARA APUNTAR A LA FILA DE LA MATRIZ
char datadec; //VARIABLES PARA
char datadec1; //REALIZAR CONVERSION 
char datadec2; //HEX TO DEC

int i;
UINT8 cursor_x, cursor_y; //MONITOREO DE CURSORES
//UINT8 cursor_x, cursor_y;

//LCD INITIALIZATION
void Nokia5110_Init(void){
	LCD_CED = 1;	//PINS AS OUTPUTS
	LCD_DCD = 1;
	LCD_DCIND = 1;
	LCD_LIGHTD = 1;
	LCD_CLKD = 1;
	
	Nokia_reset();  //RESET
	
	Send_command(0x21);  	//ENTER EXTENDED INSTRUCTION
	Send_command(0xB2);		//SET VOP(contrast)
	Send_command(0x04);		//SET TEMP
	Send_command(0x14);		//SET BIAS
	Send_command(0x20);		//ENTER BASIC INSTRUCTIONS
	Send_command(0x0C);		//DISPLAY CONTROL MODE: NORMAL MODE	
}

void Nokia_reset(){
	LCD_RSTD = 1;	// PIN OUT
	LCD_RST = 0;	//RESET LOW
	LCDWait(40);
	LCD_RST = 1;	//RESET HIGH
}

//CYCLES WAIT
void LCDWait(UINT8 w){
    UINT8 x;
    UINT8 y;  
    for ( y = 0; y < w; y++ ){
        for ( x = 0; x < 0xFF; x++ ){};
    }
}

//ENABLE BACKLIGHT
void Backlight(){
	LCD_LIGHTD = 1;
	LCD_LIGHT = 0;
}


void Send_command(byte command){ 
	LCD_DC = 0; //COMMAND
	
	LCD_CE = 0;
	SPI2_SSD = 0;
	SPI2_SS = 0; //SELECT SLAVE DOWN TO ENABLE COMMUNICATION
	LCDWait(20);
	SPI2_Send_byte(command); //SEND DATA BY SPI
	LCDWait(20);
	LCD_CE = 1; //SELECT SLAVE UP
	SPI2_SS = 1;
}

void Send_data(char data){
	LCD_DC = 1;	//DATA
	
	rowdata = data - 0x20; //TOMA EL VALOR ASCII DEL CARACTER Y LE RESTA EL OFFSET DE LA MATRIX DE CHAR.
	
	datadec1 = rowdata & 0xF0; //CONVIERTE
	datadec1 = datadec1 >> 4;  //EL NUMERO 
	datadec1 = datadec1 * 16; //HEXADECIMAL
	datadec2 = rowdata & 0x0F; // A DECIMAL
	
	datadec = datadec1 + datadec2;

	for (i=0;i<5;i++){  //CICLO PARA ENVIAR CHARACTER COMPLETO
		data = ASCII[datadec][i]; //APUNTA A LA FILA OBTENIDA
		LCD_CE = 0;
		SPI2_SSD = 1;
		SPI2_SS = 0;//SELECT SLAVE DOWN
		LCDWait(20);
		SPI2_Send_byte(data);//SEND DATA BY SPI
		LCDWait(20);
		SPI2_SS = 1;//SELECT SLAVE UP
		LCD_CE = 1;
		cursor_x++; //SE INCREMENTE CURSOR PARA LLEVAR LA CUENTA
		
		if (cursor_x>83){
			cursor_y++;
			
		}
	}
}

void gotoXY(char x, char y)//SET X AND Y CURSOR ADDRESS
{
  Send_command(0x80 | x);  // Column.
  LCDWait(30);
  Send_command(0x40 | y);  // Row.
  
  cursor_x = x;
  cursor_y = y;
  
}

/*void updateDisplay()
{
  gotoXY(0,0);
  for (int i=0; i < (LCD_WIDTH * LCD_HEIGHT / 8); i++)
  {
    Send_data(displayMap[i]);
  }
}*/

void TooBacklight(void){//TOOGLE BACKLIGHT
	LCD_LIGHTD = 1;
	LCD_LIGHT = !LCD_LIGHT;	
}
