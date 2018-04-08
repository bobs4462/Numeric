#include <string.h>
#include <stdio.h>
#define OPTIONS "gziq"

char menu(void)
{
	char choice[2];
	do {
	printf("\nПожалуйста выберите способ решения СЛАУ!\n");
	printf("g - Метод Гаусса\t\tz - Метод Зейделя\n");
	printf("i - Метод Итерации\t\tq - Выход из программы\n");
	scanf("%s%*c", choice);
	} while (!strstr(OPTIONS, choice));
	return choice[0];
}


