#include <hidef.h>  
#include "derivative.h"
#include "sw_led.h"

void SWL_Init(void){
    SWL_LEDColour SWL_ALL;
    DDR1AD1 = 0b11100000;
    ATD1DIEN1 = 0b00011111;
}
int SWL_Pushed(SWL_SwitchPos pos){
    int value = 0;
    if((PT1AD1 & pos) == pos){
        value = 1;
    }
    return value;
}
void SWL_ON (SWL_LEDColour led){
    PT1AD1 |= led;
}
void SWL_OFF(SWL_LEDColour led) {
    PT1AD1 &= ~led;
}
void SWL_TOG (SWL_LEDColour led){

    PT1AD1 ^= led;
}
void Trap(long interval){
    long count = 0;
    do{
        count++;
    }while(count<interval);
}
