/*
**  This program is free software; you can redistribute it and/or modify it under
**  the terms of the GNU Lesser General Public License, as published by the Free 
**  Software Foundation; either version 2 of the License, or (at your option) any
**  later version.
**
**   IEEE 758-2008 Half-precision Floating Point Format
**   --------------------------------------------------
**
**   | Field    | Last | First | Note
**   |----------|------|-------|----------
**   | Sign     | 15   | 15    |
**   | Exponent | 14   | 10    | Bias = 15
**   | Fraction | 9    | 0     |
*/
#include <inttypes.h>

typedef uint16_t HALF;

/* ----- prototypes ------ */
float HALFToFloat(HALF);
HALF floatToHALF(float);
static uint32_t halfToFloatI(HALF);
static HALF floatToHalfI(uint32_t);

