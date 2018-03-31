#include "gauss.h"

double * gcompute(EQSYS * ep)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%f\t", ep->matrix[i][j]);
		printf("%f\n\n\n", ep->freememb[i]);
	}
	int k;
	double a = 0;
	double * solution = (double *) malloc(sizeof(double) * 3);
	for (k = 0; k < 3; k++) {
		a = ep->matrix[k][k];	
		for (int j = k; j < 3; j++) {
			ep->matrix[k][j] /= a;
		}
		ep->freememb[k] /= a;
		for (int i = k + 1; i < 3; i++) {
			a = ep->matrix[i][k];	
			for (int j = k; j < 3; j++) 
				ep->matrix[i][j] -= (a * ep->matrix[k][j]);
			ep->freememb[i] -= (a * ep->freememb[k]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%f\t", ep->matrix[i][j]);
		printf("%f\n\n\n", ep->freememb[i]);
	}
	k--;	
	for (; k > 0; k--) {
		for (int i = k - 1; i > -1; i--) {
			a = ep->matrix[i][k];
			for (int j = k; j > i; j--)
				ep->matrix[i][j] -= (a * ep->matrix[k][j]);
			ep->freememb[i] -= (a * ep->freememb[k]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%f\t", ep->matrix[i][j]);
		printf("%f\n", ep->freememb[i]);
	}


	for (int i = 0; i < 3; i++)
		solution[i] = ep->freememb[i];
	return solution;
}


				


