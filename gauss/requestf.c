#include "gauss.h"
#include <string.h>

FILE * requestf(void)
{
	puts(FILEREQ);
	char name[64];
	fgets(name, 63, stdin);
	name[strlen(name) - 1] = '\0';
	FILE * efp = fopen(name, "r");
	if (efp)
		return efp;
	else {
		puts("Такого файла не существует");
		exit(1);
	}
}
