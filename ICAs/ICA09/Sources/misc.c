#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "misc.h"
#include "stdlib.h"

int GetRandom (int iLow, int iHighEx) {
    return rand() % (iHighEx - iLow + 1) + iLow;
}

int CheckVowel (unsigned char data2) {
    if(data2 == 'A' || data2 == 'E' || data2 == 'I' || data2 == 'O' || data2 == 'U' || data2 == 'a' || data2 == 'e' || data2 == 'i' || data2 == 'o' || data2 == 'u') {
        return 1;
    }
    else
        return 0;
}

