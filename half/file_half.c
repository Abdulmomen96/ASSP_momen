#include "file_half.h"

HALF sample_read(FILE *f) {
	float fval;
	short val;
	fread(&val, sizeof(short), 1, f);
	fval = (float) val;
	return floatToHALF(fval);
}
	
void sample_write(FILE *f, HALF hval) {
	float fval;
	fval = HALFToFloat(hval);
	if (fval > 32767.0) {
		fval = 32767.0;
	} else if (fval < -32768.0) {
		fval = -32768.0;
	} else {
		fval = round(fval);
	}
	short val = (short) fval;
	fwrite(&val, sizeof(short), 1, f);
}

void sample_copy(FILE *out, FILE *in, int length) {
	int i;
	for (i = 0; i < length; i ++ ) {
		unsigned char val;
		fread(&val, 1, 1, in);
		fwrite(&val, 1, 1, out);
	}
}

