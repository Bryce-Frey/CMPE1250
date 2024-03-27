/********************************************************************/
// HC12 Program:  ica08 - SCI_Basics
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Bryce Frey
// Details:       A more detailed explanation of the program is entered here               
// Date:          2024-03-13
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "sci.h"
#include "sw_led.h"
#include "rti.h"
#include "clock.h"
#include "misc.h"

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned char data;
unsigned char data2;
/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  
/********************************************************************/
  // one-time initializations
/********************************************************************/
SWL_Init();
Clock_Set20MHZ();
RTI_Init();
sci0_Init(130, 0b00001100); 



/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    SWL_TOG(SWL_RED);
    RTI_Delay_ms(50);

    data = GetRandom((int)'A', (int)'Z');
    sci0_txByte(data);
  
    if(sci0_read(&data2) == 1) {
      if(data2 == 'A' || data2 == 'E' || data2 == 'I' || data2 == 'O' || data2 == 'U' || data2 == 'a' || data2 == 'e' || data2 == 'i' || data2 == 'o' || data2 == 'u') {
        SWL_OFF(SWL_YELLOW);
        SWL_ON(SWL_GREEN);
      }
      else {
        SWL_OFF(SWL_GREEN);
        SWL_ON(SWL_YELLOW);
      }
    } 
  }                   
}

/********************************************************************/
// Functions 
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

