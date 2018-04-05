#include "gauss.h"
#include <ctype.h>
static bool disposer(FILE * efp);


SLE * processf(FILE * efp)
{
	double dtmp = 0;
	unsigned short size = 0;
	int ctmp = 0;
	bool minus = false;
	while ((ctmp = getc(efp)) != '\n') {
		ungetc(ctmp, efp);
		if (fscanf(efp, "%lf", &dtmp))
			size++;
		else
			disposer(efp);
	}
	SLE * emp = (SLE *) malloc(offsetof(SLE, mx) + (size-1) * size * sizeof(double));
	emp->sz = size; 
	fseek(efp, 0L, SEEK_SET);
	for (int i = 0; i < (size - 1); i++) 
		for (int j = 0; j < size; j++) {
			minus = disposer(efp);	
			fscanf(efp, "%lf", &(emp->mx[i * size + j]));
			if (minus)
				emp->mx[i * size + j] *= -1;
		}
	for (int i = 0; i < (size - 1); i++) {
		for (int j = 0; j < size; j++) {
			printf("%f\t", emp->mx[i * size + j]);
		}
		printf("\n");
	}

	return emp;
}

static bool disposer(FILE * efp)
{
	int temp = 0;
	bool minus = false;
	while (!isdigit(temp = getc(efp)) && temp != EOF) {
		if (temp == '-')
			minus = true;
	}
	if (temp == EOF) {
		printf("Файл не содержит подходящего уравнения!\n");
		exit(1);
	}
	ungetc(temp, efp);
	return minus;
}
