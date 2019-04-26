#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "DataType.h"
#include "SPI.h"
#include "Nokia5110.h"
#include "Fat.h"
#include "SD.h"

int s=0;//Once write condition
int j=0;//Counting variable
unsigned char fileName[]={'P','O','E','M','A','.','T','X','T','\r','\n'};
UINT8 Buffer[512];//Buffer from SD card

void main(void) {
  static volatile UINT8 error;//Generates SD initial condition
  error = SD_Init8MHz();      //*
  EnableInterrupts;
  SOPT1=0x20;                 //Kills watchdog
  SPI2_Init8MHz();
  Nokia5110_Init();
      
  for(;;) {
	  if (s==0){
		  if (error == OK){
			  FAT_Read_Master_Block();
			  if(FAT_FileOpen(fileName,READ)!= FILE_NOT_FOUND){//Reads SD card on the condition that there where an existent file
				  FAT_FileRead(Buffer);
				  gotoXY(0,0);                      
				  for (j=0;j<=sizeof(Buffer)-415;j++){//Sending array cycle (size of file minus 415 just to print a single screen)
					  Send_data(Buffer[j]);           //Sends readed data from SD to LCD
					  LCDWait(20);
				  }
				  s=1;
			  }
		  }
	  }
  } 
}
