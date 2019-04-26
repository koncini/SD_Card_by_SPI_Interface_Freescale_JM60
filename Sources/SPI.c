/*"File Comment""***************************************************************
 *
 *   Copyright (c) 2015 Universidad Catolica de oriente;
 *   All Rights Reserved
 *
 *******************************************************************************
 *  Project Name : SPIProject
 *  File Name    : SPI_Drv.c
 *  Content      : 
 *  CPU          : MC9S08JM60
 *  Compiler     : CodeWarrior for HCS08 10.6
 *  OS           :                                
 *  UPDATED HISTORY:
 *  REV   YYYY.MM.DD  AUTHOR        DESCRIPTION OF CHANGE
 *  ---   ----------  ------        --------------------- 
 *  0.1   2015.01.05  Felipe        Created
 *
 *""File Comment End""*********************************************************/

#include "SPI.h"

void SPI1_Init8MHz(void)
{ 
  //SOPT2 = SOPT2_SPI1PS_MASK;  // Drive PTE as SPI port
  SPI1_SS = 1;
  SPI1_SSD= 1;
  SPI1_SS = 1;

SPI1C2 = 0b00000000;  
//         ||||||||___(0)____SPC0  	:  SPI Pin Control 0: 1 Single Wire , 0 uses separate pin 
//         |||||||____(0)____SPISWAI:  SPI Stop in Wait Mode: 1 SPI clocks stop in Wait, 0 SPI clocks continue to operate in wait mode
//         ||||||_____(-)____NA   	:  Unimplemented or Reserved
//         |||||______(0)____BIDIROE:  Bidirectional Mode Output Enable: 1 Output,0 Input (When SPC0 = 0, BIDIROE has no meaning or effect)
//         ||||_______(0)____MODFEN :  Master Mode-Fault Function Enable: 1 Enable,0 Disable (master SS pin acts as the mode fault input or the slave select output)
//         |||________(-)____NA   	:  Unimplemented or Reserved:
//         ||_________(0)____SPIMODE:  SPI 8- or 16-bit Mode: 1 16-bit, 0 8-bit
//         |__________(0)____SPMIE	:  SPI Match Interrupt Enable: 1 Enable, 0 Disable ( Interrupt when SPMF = 1,)

SPI1BR = 0b00100010; //  Khz, 0x13= 250KHz --fbus/((SPPR+1)*2^(SPR+1))=8000000/((2)*(2^4))=  	=250Khz
//         ||||||_____(010)__SPR    :  SPI Baud Rate Prescale Divisor: view Table 15-6.
//         |||||______(-)____NA   	:  Unimplemented or Reserved
//         ||_________(010)__SPPR	:  SPI Baud Rate Divisor: View Table 15-7.
//         |__________(0)____NA   	:  Unimplemented or Reserved
  
SPI1M =  0x0000;

SPI1C1= 0b01010000; //SPI1C1_SPE_MASK | SPI1C1_MSTR_MASK;
//        ||||||||___(0)____LSBFE 	:  LSB First (Shifter Direction): 1 start with least significant bit, 0 start with most significant bit
//        |||||||____(0)____SSOE 	:  Slave Select Output Enable: View Table 15-2.
//        ||||||_____(0)____CPHA  	:  Clock Phase: 1 First edge on SPSCK occurs at the start of the first cycle ,0 First edge on SPSCK occurs at the middle of the first cycle
//        |||||______(0)____CPOL   	:  Clock Polarity: 1 Active-low SPI clock,0 Active-high SPI clock
//        ||||_______(1)____MSTR    :  Master/Slave Mode Select: 1 Master,0 Slave
//        |||________(0)____SPTIE   :  SPI Transmit Interrupt Enable:  1 Enable, 0 Disable ( Interrupt when SPTEF is 1)
//        ||_________(1)____SPE     :  SPI System Enable: 1 Enable, 0 Disable
//        |__________(0)____SPIE	:  SPI Interrupt Enable: 1 Enable, 0 Disable( Interrupt when SPRF or MODF is 1)

}

void SPI1_Send_byte(UINT8 u8Data)
{
	(void)SPI1S;
	SPI1DL=u8Data;
	while(!SPI1S_SPTEF);
}

UINT8 SPI1_Receive_byte(void){
	(void)SPI1DL;
	SPI1DL=0xFF;
	while(!SPI1S_SPRF);	
	return(SPI1DL);
}

void SPI2_Init8MHz(void)
{ 
  //SOPT2 = SOPT2_SPI1PS_MASK;  // Drive PTE as SPI port
//SPI1_SS = 1;
  SPI2_SSD= 1;
  SPI2_SS = 0;

SPI2C2 = 0b00000000;  
//         ||||||||___(0)____SPC0  	:  SPI Pin Control 0: 1 Single Wire , 0 uses separate pin 
//         |||||||____(0)____SPISWAI:  SPI Stop in Wait Mode: 1 SPI clocks stop in Wait, 0 SPI clocks continue to operate in wait mode
//         ||||||_____(-)____NA   	:  Unimplemented or Reserved
//         |||||______(0)____BIDIROE:  Bidirectional Mode Output Enable: 1 Output,0 Input (When SPC0 = 0, BIDIROE has no meaning or effect)
//         ||||_______(0)____MODFEN :  Master Mode-Fault Function Enable: 1 Enable,0 Disable (master SS pin acts as the mode fault input or the slave select output)
//         |||________(-)____NA   	:  Unimplemented or Reserved:
//         ||_________(0)____SPIMODE:  SPI 8- or 16-bit Mode: 1 16-bit, 0 8-bit
//         |__________(0)____SPMIE	:  SPI Match Interrupt Enable: 1 Enable, 0 Disable ( Interrupt when SPMF = 1,)

SPI2BR = 0b00100010; //  Khz, 0x13= 250KHz --fbus/((SPPR+1)*2^(SPR+1))=8000000/((2)*(2^4))=  	=250Khz
//         ||||||_____(010)__SPR    :  SPI Baud Rate Prescale Divisor: view Table 15-6.
//         |||||______(-)____NA   	:  Unimplemented or Reserved
//         ||_________(010)__SPPR	:  SPI Baud Rate Divisor: View Table 15-7.
//         |__________(0)____NA   	:  Unimplemented or Reserved
  
SPI2M =  0x0000;

SPI2C1= 0b01010000; //SPI2C1_SPE_MASK | SPI2C1_MSTR_MASK;
//        ||||||||___(0)____LSBFE 	:  LSB First (Shifter Direction): 1 start with least significant bit, 0 start with most significant bit
//        |||||||____(0)____SSOE 	:  Slave Select Output Enable: View Table 15-2.
//        ||||||_____(0)____CPHA  	:  Clock Phase: 1 First edge on SPSCK occurs at the start of the first cycle ,0 First edge on SPSCK occurs at the middle of the first cycle
//        |||||______(0)____CPOL   	:  Clock Polarity: 1 Active-low SPI clock,0 Active-high SPI clock
//        ||||_______(1)____MSTR    :  Master/Slave Mode Select: 1 Master,0 Slave
//        |||________(0)____SPTIE   :  SPI Transmit Interrupt Enable:  1 Enable, 0 Disable ( Interrupt when SPTEF is 1)
//        ||_________(1)____SPE     :  SPI System Enable: 1 Enable, 0 Disable
//        |__________(0)____SPIE	:  SPI Interrupt Enable: 1 Enable, 0 Disable( Interrupt when SPRF or MODF is 1)
	 
}

void SPI2_Send_byte(UINT8 u8Data)
{
	(void)SPI2S;
	SPI2DL=u8Data;
	while(!SPI2S_SPTEF);
}

UINT8 SPI2_Receive_byte(void)
{
	(void)SPI2DL;
	SPI2DL=0xFF;
	while(!SPI2S_SPRF);	
	return(SPI2DL);
}

void SPI1_High_rate(void)
{
  SPI1C1 = 0x00;
  SPI1BR = 0x11; //      		
  SPI1C1 = SPI1C1_SPE_MASK | SPI1C1_MSTR_MASK;

}
/*Tabla 11.2              
 ___________________________________________________________________________ 
|  MODFEN  |   SSOE    |   Master Mode                 |     Slave Mode     |
|----------|-----------|-------------------------------|--------------------|
|    0     |     0     | General-purpose I/O (not SPI) | Slave select input |
|    0     |     1     | General-purpose I/O (not SPI) | Slave select input |
|    1     |     0     | SS input for mode fault       | Slave select input |
|    1     |     1     | Automatic SS output           | Slave select input |
|__________|___________|_______________________________|____________________|

Tabla 15-6							Tabla 15-7
 _______________________________   _________________________ 
| SPPR[2:0] | Prescaler Divisor | | SPR[2:0] | Rate Divisor |
|-----------|-------------------| |----------|--------------|
|    000    |         1         | |    000   |      2       |
|    001    |         2         | |    001   |      4       |
|    010    |         3         | |    010   |      8       |
|    011    |         4         | |    011   |      16      |
|    100    |         5         | |    100   |      32      |
|    101    |         6         | |    101   |      64      |
|    110    |         7         | |    110   |      128     |
|    111    |         8         | |    111   |      256     |
|___________|___________________| |__________|______________|


*/
