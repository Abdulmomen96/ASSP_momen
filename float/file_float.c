#include "file_float.h"

float sample_read(FILE *f) {
	short val;
	fread(&val, sizeof(short), 1, f);
	return (float) val;
}
	
void sample_write(FILE *f, float dval) {
	float temp;
	if (dval > 32767.0) {
		temp = 32767.0;
	} else if (dval < -32768.0) {
		temp = -32768.0;
	} else {
		temp = round(dval);
	}
	short val = (short) temp;
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

