#include "gauss.h"

int main(int argc, char **argv)
{
	SLE * emp;
	double * solution, det;
	FILE * efp;
	if (argc > 1)
		efp = fopen(argv[1], "r");
	else 
		efp = requestf();
	emp = processf(efp);
	if(!(det = determ(emp))) {
		puts(DETISZ);	
		exit(1);
	}
	else 
		printf(DETIS, det);
	solution = gcompute(emp);
	for (int i = 0; i < emp->sz - 1; i++)
		printf("Корень %d: %f\n", i, solution[i]);
	puts("");

	
	puts(FAREWELL);
	fclose(efp);
	free(solution);
	free(emp);
	return 0;
}
