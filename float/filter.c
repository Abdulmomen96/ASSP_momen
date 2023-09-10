#include "file_float.h"

#define B0 1.0
#define B1 -1.9829321938553581
#define B2 1.0
#define A0 1.0
#define A1 -1.970038140264835
#define A2 0.98699496268154929

float filter(float x0, float x1, float x2, float y1, float y2) {
	return B0*x0 + B1*x1 - A1*y1 + B2*x2 - A2*y2;
}

int main (int argc, char *argv[])  {
	int i;

	// delay line
	float x0 = 0.0, x1 = 0.0, x2 = 0.0, y0 = 0.0, y1 = 0.0, y2 = 0.0;

	if (argc != 5) {
		printf("Please provide four arguments: input_file output_file number_of_samples header_length\n");
		return 0;
	}

	FILE *in = fopen(argv[1], "rb");
	FILE *out = fopen(argv[2], "wb");

	if (in == NULL || out == NULL) {
		printf("Could not open one of the files\n");
		return 0;
	}

	sample_copy(out, in, atoi(argv[4]));

	for (i = 0; i < atoi(argv[3]); i ++) {
		x2 = x1;
		x1 = x0;
		x0 = sample_read(in);

		y2 = y1;
		y1 = y0;
		y0 = filter(x0, x1, x2, y1, y2);

		sample_write(out, y0);
	}

	fclose(in);
	fclose(out);
}
