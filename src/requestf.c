#include "library.h"
#include <string.h>

FILE *requestf(void)
{
	printslow(FILEREQ);
	char name[64];
	fgets(name, 63, stdin);
	name[strlen(name) - 1] = '\0';
	FILE *efp = fopen(name, "r");
	if (efp)
		return efp;
	else {
		printf(FILENFND);
		exit(1);
	}
}
