#include <hidef.h>
#include "derivative.h"
#include "rti.h"
extern volatile unsigned long rtiMasterCount;
void RTI_Init(void)
{
    RTICTL = 0b10010111;
}

void RTI_Delay_ms(unsigned int ms)
{
    rtiMasterCount =ms;

    while (ms !=0) // repeat delay for the given ms
    {
        if (CRGFLG_RTIF) // RTI period over?
        {
            CRGFLG = CRGFLG_RTIF_MASK; // clear flag 
            ms--; 
        }
        
    }

}