#include "gauss.h"

FILE * requestf(void)
{
	puts("Пожалуйста введите название файла с уравнением");
	char name[64];
	fgets(name, 63, stdin);
	name[strlen(name) - 1] = '\0';
	FILE * eq = fopen(name, "r");
	if (eq)
		return eq;
	else {
		puts("Такого файла не существует");
		exit(1);
	}
}
