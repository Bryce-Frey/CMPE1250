#include "derivative.h"
#include <hidef.h>
#include "clock.h"

unsigned long PLLCLK = DEF_BUS_CLOCK;

void PLL_To20MHz (void)
{
    SYNR = 4;
    REFDV = 3;

    CLKSEL_PSTP = 1;

    PLLCTL = 0b11111111;

    while(!CRGFLG_LOCK)
    {

    }

    CLKSEL_PLLSEL = 1;
    PLLCLK = 40000000;
}

void Clock_Set8MHZ(void){
    SYNR = 1;
    REFDV = 3;

    CLKSEL_PSTP = 1;

    PLLCTL = 0b11111111;

    while(!CRGFLG_LOCK)
    {

    }

    CLKSEL_PLLSEL = 1;
    PLLCLK = 16000000;
}

void Clock_Set20MHZ(void){
    PLL_To20MHz();
}

void Clock_Set24MHZ(void){
    SYNR = 5;
    REFDV = 3;

    CLKSEL_PSTP = 1;

    PLLCTL = 0b11111111;

    while(!CRGFLG_LOCK)
    {

    }

    CLKSEL_PLLSEL = 1;
    PLLCLK = 48000000;
}

void Clock_EnableOutput(ClockOutDiv Div)
{
    ECLKCTL &= ~ECLKCTL_NECLK_MASK;
    ECLKCTL |= Div;
}

unsigned long Clock_GetBusSpeed(void)
{
    if (CLKSEL_PLLSEL == 1){
        return PLLCLK / 2;
    }
    else{
        return DEF_BUS_CLOCK;
    }
}