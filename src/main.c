#include "library.h"

bool verbose = false;
int p = 6;

int main(int argc, char **argv)
{
	SLE *emp;
	double * solution, det;
	FILE * efp;
	char choice = 0;

	setvbuf(stdout, NULL, _IONBF, 1);

	printslow(GREETING);

	if (argc >= 2) {
		if (!strcmp("-v", argv[1])) {
			verbose = true;
			efp = requestf();
		}
		else if (argc == 3) {
			if (!strcmp("-v", argv[2])) {
				verbose = true;
				printslow(FILEFND);
				efp = fopen(argv[1], "r");
				if (!efp) {
					printslow(FILENFND);
					exit(1);
				}
			}
			else
				printf(INVOPT, argv[2]);
		}
		else {
			printslow(FILEFND);
			efp = fopen(argv[1], "r");
			if (!efp) {
				printslow(FILENFND);
				exit(1);
			}
		}
	}
	else 
		efp = requestf();

	emp = processf(efp);

	if(!(det = determ(emp))) {
		printslow(DETISZ);	
		exit(1);
	}
	else 
		printf(DETIS, det);

	choice = menu();

	switch (choice) {
		case 'g':
			solution = gcompute(emp);
			break;
		case 'z':
			solution = zcompute(emp);
			break;
		case 'i':
			solution = icompute(emp);
			break;
		default:
			goto EXIT;
	}

	printf("\nОтвет:");
	for (int i = 0; i < emp->sz - 1; i++)
		printf("\nКорень %d: %.*f\n", i + 1, p, solution[i]);
	
	free(solution);
EXIT: printslow(FAREWELL);
	fclose(efp);
	free(emp);
	return 0;
}
