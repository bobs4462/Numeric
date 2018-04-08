#include "library.h"

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 1);
	SLE *emp;
	double * solution;
	FILE * efp;
	if (argc > 1)
		efp = fopen(argv[1], "r");
	else 
		printf("BYE");
	emp = processf(efp);
	restructure(emp);
	solution = zcompute(emp, 0.00001);
	for (int i = 0; i < emp->sz - 1; i++)
		printf("Корень %d: %f\n", i + 1, solution[i]);
	
	fclose(efp);
	free(solution);
	free(emp);
	return 0;
}
