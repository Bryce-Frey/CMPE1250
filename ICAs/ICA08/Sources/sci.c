#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "sci.h"

// initialize SCI0 at 9600 BAUD
unsigned long sci0_Init(unsigned long ulBaudRate, int iRDRF_Interrupt) {
    SCI0BD = ulBaudRate; // 9600 BAUD
    SCI0CR2 = iRDRF_Interrupt; // enable transmitter and reciever
}

// non-blocking read of a byte, returns 1 if data present, otherwise 0
int sci0_read (unsigned char * pData) {
    if (SCI0SR1_RDRF) { // if ready to recieve a bit
      *pData = SCI0DRL;
      return 1;
    }
    else
      return 0;
}

// send a byte to SCI0 (blocking)
void sci0_txByte (unsigned char data) {
    while(!SCI0SR1_TDRE); // blocking
    SCI0DRL = data; // assign value to register
}
