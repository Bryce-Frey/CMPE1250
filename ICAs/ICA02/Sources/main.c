/********************************************************************/
// HC12 Program:  ICA2
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Bryce Frey
// Details:       Toggles between the Red and Green LEDS           
// Date:          17/01/24
// Revision History : 17/01 - Creation and start of code cleanup
//                    19/01 - Finished Version



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

/********************************************************************/
// Local Prototypes
/********************************************************************/
void RED (unsigned int bOn); // declare RED
void GREEN (unsigned int bOn); // declare GREEN

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int uiMainLoopCount = 0; // sets uiMainLoopCount to 0


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
PT1AD1 &= 0x1F; // 00011111
DDR1AD1 = 0xE0; // 11100000

/********************************************************************/
  // main program loop
/********************************************************************/
 
  for (;;) // loop forever
  {
    ++uiMainLoopCount; // add one to uiMainLoopCount
    RED(uiMainLoopCount); // if loop count is less than 1000, true
    GREEN(uiMainLoopCount); // if loop count is less greater than or equal to 1000, true
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/
void RED (unsigned int bOn)
{
    if (bOn < 0x8000) // bOn < 0001 0000 0000 0000
        PT1AD1 |= (byte)(1 << 7); // PT1AD1 |= 0b10000000
    else
    {
        PT1AD1 &= 0x7F; // PT1AD1 &= 0111 1111
    }

}

void GREEN(unsigned int bOn)
{
    if (bOn >= 0x8000) // bOn >= 0001 0000 0000 0000
    {
        PT1AD1 |= 0x20; // PT1AD1 |= 0010 0000
    }
    else
    {
        PT1AD1 &= 0b11011111; 
    }
                    
}
/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
