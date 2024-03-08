/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        This B. You
// Details:       A more detailed explanation of the program is entered here               
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "sw_led.h"
#include "clock.h"
#include "rti.h"

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
RTI_Init();

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    SWL_TOG(SWL_RED);
    if (SWL_Pushed(SWL_RIGHT) == 1) {
      SWL_ON(SWL_GREEN);
      SWL_OFF(SWL_RED);
      while(SWL_Pushed(SWL_RIGHT) == 1){}
      SWL_OFF(SWL_GREEN);
    }
    else if(SWL_Pushed(SWL_LEFT) == 1) {
      SWL_ON(SWL_RED);
      RTI_Delay_ms(1);
      SWL_OFF(SWL_RED);
      RTI_Delay_ms(9);
    }
    else if(SWL_Pushed(SWL_UP) == 1 && SWL_Pushed(SWL_DOWN) == 1) {
      RTI_Delay_ms(10);
    }
    else if(SWL_Pushed(SWL_UP) == 1) {
      RTI_Delay_ms(8);
    }
    else if(SWL_Pushed(SWL_DOWN) == 1) {
      RTI_Delay_ms(12);
    }
    else {
      RTI_Delay_ms(10);
    }
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
