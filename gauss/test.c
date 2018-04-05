#include "gauss.h"
#include <stddef.h>
static SLE * shrink(SLE * emp, int n);
static int sign(int i) ;

double determ(SLE * emp)
{
	double result = 0;
	SLE * tmparr[emp->sz - 1];
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

static SLE * shrink(SLE * emp, int n)
{
	SLE * nemp = (SLE *) malloc(offsetof(SLE, mx) + (emp->sz - 1) * (emp->sz - 2) * sizeof(double));
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

int main(void)
{
	SLE * tnemp = (SLE *) malloc(offsetof(SLE, mx) + 12 * sizeof(double));
	tnemp->sz = 4;
	tnemp->mx[0] = 1;
	tnemp->mx[1] = 2;
	tnemp->mx[2] = 3;
	tnemp->mx[3] = 44;
	tnemp->mx[4] = 4.4;
	tnemp->mx[5] = 5;
	tnemp->mx[6] = 5.6;
	tnemp->mx[7] = 18;
	tnemp->mx[8] = 9;
	tnemp->mx[9] = 10;
	tnemp->mx[10] = 10;
	tnemp->mx[11] = 12;
	
	printf("%f", determ(tnemp));
}


