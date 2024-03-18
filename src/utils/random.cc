#include <stdlib.h>
#include <stdio.h>

#define RAND_MAX    0x7fffffff
double rnd(double min, double max) {
    double d = (double) rand() / ((double) RAND_MAX +1)
}