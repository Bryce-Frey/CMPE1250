/********************************************************************/
// HC12 Program:  
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Bryce Frey
// Details:                      
// Date:          02/16/24
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "code.h"

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
int numOn = 0;
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

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    //Off For
    SWL_TOG(SWL_RED);
    Trap(1250L);

    // On FOr
    SWL_TOG(SWL_RED);
    Trap(3750L);
    

    numOn = 0; // start at 0

    //add one to numOn for rach button pressed
    if(SWL_Pushed(SWL_LEFT) == 1){
      numOn+=1;
    }
    if(SWL_Pushed(SWL_CTR) == 1){
      numOn+=1;
    }
    if(SWL_Pushed(SWL_RIGHT) == 1){
      numOn+=1;
    }
    if(SWL_Pushed(SWL_UP) == 1){
      numOn+=1;
    }
    if(SWL_Pushed(SWL_DOWN) == 1){
      numOn+=1;
    }

    //if EXACTLY 2 buttons are pressed, change led states
    if (numOn == 2){
      SWL_ON(SWL_GREEN);
      SWL_OFF(SWL_YELLOW);
    }
    else{ // otherwise keep as default
      SWL_ON(SWL_YELLOW);
      SWL_OFF(SWL_GREEN);
    }

  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

