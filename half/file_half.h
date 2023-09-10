#include <stdio.h>
#include <math.h>
#include "half_float.h"

HALF sample_read(FILE *f);
void sample_write(FILE *f, HALF hval);
void sample_copy(FILE *out, FILE *in, int length);

