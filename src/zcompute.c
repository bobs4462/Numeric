//Метод Зейделя
#include "library.h"

static int size;
static double prcsn = 1;
static bool approx(double * sl, double * psl);

double *zcompute(SLE *emp)
{
	size = emp->sz - 1;
	double tmp = 0;
	int iter = 1;

	printslow(EPSREQ);
	if (scanf("%d%*c", &p))
		for (int i = 0; i < p; i++)
			prcsn /= 10;
			
#ifdef DIAGNOSTICS
	printf("Entering restructure");
#endif
	restructure(emp);
#ifdef DIAGNOSTICS
	printf("Exited restructure");
#endif
	double *sl = (double *) malloc(sizeof(double) * (emp->sz - 1));
	double *psl = (double *) malloc(sizeof(double) * (emp->sz - 1));

	for (int i = 0; i < emp->sz - 1; i++) {
		sl[i] = emp->mx[i * emp->sz + emp->sz - 1];
		psl[i] = sl[i];
	}

	for (int i = 0; i < emp->sz - 1; i++) {
		tmp = emp->mx[i * emp->sz + i];
		for (int j = 0; j < emp->sz; j++) {
			emp->mx[i * emp->sz + j] /= tmp;
		}
	}

#ifdef DIAGNOSTICS
	show_state(emp);
#endif

	do {
		for (int i = 0; i < emp->sz - 1; i++) {
			psl[i] = sl[i];
			tmp = emp->mx[i * emp->sz + emp->sz - 1];
			for (int j = 0; j < emp->sz - 1; j++) {
				if (i != j)
					tmp -= emp->mx[i * emp->sz + j] * sl[j];
			}
			sl[i] = tmp; 
		}
		if (verbose) {
			printf("\nИтерация %d:\n", iter++);
			for (int i = 0; i < size; i++)
				printf("Корень %d : %f -> %f\n", i, psl[i], sl[i]);
		}
	} while (!approx(sl, psl));
	free(psl);
	return sl;
}

static bool approx(double * sl, double * psl)
{
	double norm = 0;
	for (int i = 0; i < size; i++)
		norm += (sl[i] - psl[i]) * (sl[i] - psl[i]);
	if (sqrt(norm) >= prcsn)
		return false;
	return true;
}
