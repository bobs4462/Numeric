#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>

//static const struct timespec trq = {0, 30000000L};
//static struct timespec trm;
typedef struct {
	unsigned short sz;
	double mx[];
} SLE;

double *zcompute(SLE *emp, double eps);
SLE *processf(FILE *efp);
void restructure(SLE *emp);
void diagnose(SLE *emp);
#endif
