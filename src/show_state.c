#include "library.h"

void show_state(SLE *emp) 
{
	printf("\n");
	for (int i = 0; i < (emp->sz - 1); i++) {
		for (int j = 0; j < emp->sz; j++) {
			printf("%f\t", emp->mx[i * emp->sz + j]);
		}
		printf("\n");
	}
}

