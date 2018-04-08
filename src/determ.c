#include "library.h"

static int sign(int i);
static SLE *shrink(SLE *emp, int n);

double determ(SLE *emp)
{
	double result = 0;
	SLE *tmparr[emp->sz - 1];
	if (emp->sz == 3)
		return emp->mx[0] * emp->mx[4] - emp->mx[1] * emp->mx[3];
	else {
		for (int i = 0; i < emp->sz - 1; i++) {
			tmparr[i] = shrink(emp, i);
		}
		for (int i = 0; i < emp->sz - 1; i++) {
			result += determ(tmparr[i]) * emp->mx[i] * sign(i);
		}
	}
	for (int i = 0; i < emp->sz - 1; i++) {
		free(tmparr[i]);
	}
	return result;
}

static int sign(int i) 
{
	int one = 1;
	while(i-->0) 
		one *= -1;
	return one;
}

static SLE *shrink(SLE *emp, int n)
{
	SLE *nemp = (SLE *) malloc(offsetof(SLE, mx) + (emp->sz - 1) * (emp->sz - 2) * sizeof(double));
	nemp->sz = emp->sz - 1;
	for (int i = 1; i < emp->sz - 1; i++)
		for (int j = 0; j < emp->sz - 1; j++) {
			if (j > n)
				nemp->mx[(i-1) * nemp->sz + j - 1] = emp->mx[i * emp->sz + j];
			else if (j == n)
				continue;
			else
				nemp->mx[(i-1) * nemp->sz + j] = emp->mx[i * emp->sz + j];
		}
	return nemp;
}



