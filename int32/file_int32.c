#include "file_int32.h"

int sample_read(FILE *f) {
	short val;
	fread(&val, sizeof(short), 1, f);
	return (int) val;
}
	
void sample_write(FILE *f, int dval) {
	int temp;
	if (dval > 32767) {
		temp = 32767;
	} else if (dval < -32768) {
		temp = -32768;
	} else {
		temp = dval;
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

