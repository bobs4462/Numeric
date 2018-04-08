#include "library.h"

static int size;
static double prcsn;
bool approx(double * sl, double * psl);

double *zcompute(SLE *emp, double eps)
{
	double *sl = (double *) malloc(sizeof(double) * (emp->sz - 1));
	double *psl = (double *) malloc(sizeof(double) * (emp->sz - 1));
	double tmp = 0;
	size = emp->sz - 1;
	prcsn = eps;
	int c = 0;

	for (int i = 0; i < emp->sz - 1; i++) {
		sl[i] = emp->mx[i * emp->sz + emp->sz - 1];
		psl[i] = sl[i];
	}
		for (int i = 0; i < size; i++)
			printf("%f -> %f", psl[i], sl[i]);
	
		printf("\n");
	for (int i = 0; i < size ; i++) {
		for (int j = 0; j < size + 1; j++) {
			printf("%f\t", emp->mx[i * (size+1) + j]);
		}
		printf("\n");
	}


	for (int i = 0; i < emp->sz - 1; i++) {
		tmp = emp->mx[i * emp->sz + i];
		printf("%f\n", tmp);
		for (int j = 0; j < emp->sz; j++) {
			emp->mx[i * emp->sz + j] /= tmp;
		}
	}
		printf("\n");
	for (int i = 0; i < size ; i++) {
		for (int j = 0; j < size + 1; j++) {
			printf("%f\t", emp->mx[i * (size+1) + j]);
		}
		printf("\n");
	}

	c = 10;
	do {
		for (int i = 0; i < size; i++)
			printf("%f -> %f\n", psl[i], sl[i]);
		for (int i = 0; i < emp->sz - 1; i++) {
			psl[i] = sl[i];
			tmp = emp->mx[i * emp->sz + emp->sz - 1];
			for (int j = 0; j < emp->sz - 1; j++) {
				if (i != j)
					tmp -= emp->mx[i * emp->sz + j] * sl[j];
			}
			sl[i] = tmp; 
		}
	} while (!approx(sl, psl));
	free(psl);
	return sl;
}

bool approx(double * sl, double * psl)
{
	double norm = 0;
	for (int i = 0; i < size; i++)
		norm += (sl[i] - psl[i]) * (sl[i] - psl[i]);
	if (sqrt(norm) >= prcsn)
		return false;
	return true;
}






