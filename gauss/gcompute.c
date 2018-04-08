#include "gauss.h"

double *gcompute(SLE *emp)
{
	int k = 0;
	double tmp = 0;
	double *solution = (double *) malloc(sizeof(double) * (emp->sz - 1));
	for (k = 0; k < emp->sz - 1; k++) {
		mx_check(emp, k);
		tmp = emp->mx[k * emp->sz + k];	
		for (int j = k; j < emp->sz; j++) {
			emp->mx[k * emp->sz + j] /= tmp;
		}
		for (int i = k + 1; i < emp->sz - 1; i++) {
			tmp = emp->mx[i * emp->sz + k];	
			for (int j = k; j < emp->sz; j++) 
				emp->mx[i * emp->sz + j] -= (tmp * emp->mx[k * emp->sz + j]);
		}
	}
	k--;
	for (; k > 0; k--) {
		for (int i = k - 1; i > -1; i--) {
			tmp = emp->mx[i * emp->sz + k];
			for (int j = (emp->sz-1); j > i; j--)
				emp->mx[i * emp->sz + j] -= (tmp * emp->mx[k * emp->sz + j]);
		}
	}

	for (int i = 0; i < emp->sz - 1; i++)
		solution[i] = emp->mx[i * emp->sz  + emp->sz - 1];
	return solution;
}


				


