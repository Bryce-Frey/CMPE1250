/********************************************************************/
// HC12 Program:  ICA01 - Flashes red LED
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Bryce Frey
// Details:       When turned on, the red LED will turn on and off repeatedly               
// Date:          01/12/24
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/
#define RED_LED 0b10000000
#define INDEX_MAX 10
/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int counter, index; // counter acts as a clock
                             // index determines how long the light stays lit

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
PT1AD1 |= RED_LED;
DDR1AD1 |= RED_LED;
counter = 0;
index = 0;


/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
{
  if(++counter == 0) // loop once unsigned int rolls over
  {
    if(++index >= INDEX_MAX) // toggle light when index reached the max
    {
      index = 0;  //reset cycles
      PT1AD1 ^= RED_LED; // toggle light
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

