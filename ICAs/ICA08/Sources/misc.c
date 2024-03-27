#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "misc.h"
#include "stdlib.h"

int GetRandom (int iLow, int iHighEx) {
    return rand() % (iHighEx - iLow + 1) + iLow;
}

