#ifndef __SPI__
#define __SPI__
#include "DataType.h"
/* Includes */

//MOSI1  PTE5/MOSI1
//MISO1  PTE4/MISO1
//SPSCK1 PTE6/SPSCK1
//SS1    PTE7/SS1

//MOSI2  PTB1/MOSI2
//MISO2  PTB0/MISO2
//SPSCK2 PTB2/SPSCK2
//SS2    PTB3/SS2

/* definitions */

#define SPI2_SS    PTBD_PTBD3      /* Slave Select */
#define SPI2_SSD   PTBDD_PTBDD3    

#define SPI1_SS    PTED_PTED7      /* Slave Select */
#define SPI1_SSD   PTEDD_PTEDD7   

#define ENABLE    0
#define DISABLE   1

/* Global Variables */

/* Prototypes */
void SPI1_Init8MHz(void);
void SPI1_Send_byte(UINT8 u8Data);
UINT8 SPI1_Receive_byte(void);
void SPI1_High_rate(void);

void SPI2_Init8MHz(void);
void SPI2_Send_byte(UINT8 u8Data);
UINT8 SPI2_Receive_byte(void);

#endif /* __SPI__ */
