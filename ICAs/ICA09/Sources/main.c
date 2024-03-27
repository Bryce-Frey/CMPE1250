/********************************************************************/
// HC12 Program:  ICA09 - SCI_Strings
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Bryce Frey
// Details:       A more detailed explanation of the program is entered here               
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "clock.h"
#include "misc.h"
#include "rti.h"
#include "sci.h"
#include "sw_led.h"

//Other system includes or your includes go here
#include <stdlib.h>
#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/

unsigned char data2;
int total = 3;

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
sci0_InitEnum(BAUD_19200_BUS20MHZ);

/********************************************************************/
  // main program loop
/********************************************************************/
  sci0_txString("\x1b[35m"); // magenta
  sci0_txString("\x1b[2J"); // clear console
  sci0_txString("Bryce Frey"); // output

  for (;;)
  {
    int loop = 0;
    char test[22] = "";
    int sum = 0;
    char sumString[] = "";
    char result[] = " ";
    char totalString[] = "";

    
    RTI_Delay_ms(250);

    for(loop = 0; loop < 20; loop++) {
      while(CheckVowel(test[loop]) == 0) 
      {
        if(SWL_Pushed(SWL_CTR))
          test[loop] = GetRandom((int)'A', (int)'Z');
        else 
          test[loop] = GetRandom((int)'a', (int)'z');
      }
      sum += test[loop];
    }
    SWL_ON(SWL_RED);

    sci0_txString("\x1b[3;0H"); // go to start


    sci0_txString("\x1b[2K"); // erase line
    sci0_txString("\x1b[32m");
    sci0_txString(test); // output
    

    sprintf(sumString, "%u", sum); // concat
    strcat(result, sumString); // concat
    strcat(result, " "); // concat

    sci0_txString("\x1b[33m");
    sci0_txString(result); // output

    sci0_txString("\x1b[5;0H"); // go to start

    sprintf(totalString, "%u", total); // concat
    sci0_txString("\x1b[2K"); // clear line
    sci0_txString("\x1b[37m"); // white
    sci0_txString(totalString); // output

    total+=10;
    SWL_OFF(SWL_RED);
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
