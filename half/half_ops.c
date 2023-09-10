#include "half_ops.h"

HALF mulh(HALF i1, HALF i2) {
	HALF r;
	float i1f = HALFToFloat(i1);
	float i2f = HALFToFloat(i2);
	float rf = i1f * i2f;
	r = floatToHALF(rf);
	return r;
} 

HALF addh(HALF i1, HALF i2) {
	HALF r;
	float i1f = HALFToFloat(i1);
	float i2f = HALFToFloat(i2);
	float rf = i1f + i2f;
	r = floatToHALF(rf);
	return r;
} 

HALF subh(HALF i1, HALF i2) {
	HALF r;
	float i1f = HALFToFloat(i1);
	float i2f = HALFToFloat(i2);
	float rf = i1f - i2f;
	r = floatToHALF(rf);
	return r;
} 

