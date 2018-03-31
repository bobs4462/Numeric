#include "gauss.h"

int main(int argc, char **argv)
{
	SLE * emp;
	double * solution, determinant;
	FILE * efp;
	if (argc > 1)
		eq = fopen(argv[1], "r");
	else 
		eq = requestf();
	emp = processf(eq);
	if((determinant = determ(emp)) != 0)
		talktu(DETISZ
		
	solution = gauss_it(array);
	puts("");
	for (int i = 0; i < 3; i++)
		printf("Корень %d: %f\n", i, solution[i]);
	puts("");

	
	farewell();
	fclose(eq);
	free(solution);
	free(array);
	return 0;
}
