#include "gauss.h"

void mx_check(SLE * emp, int rc)
{
	double tmp = 0;
	if (emp->mx[rc * emp->sz + rc] == 0) {
		for (int i = rc + 1; i < emp->sz - 1; i++)
			if (emp->mx[i * emp->sz + rc] != 0) {
				for (int j = rc; j < emp->sz; j++) {
					tmp = emp->mx[rc * emp->sz + rc];
					emp->mx[rc * emp->sz + rc] = emp->mx[i * emp->sz + rc];
				 	emp->mx[i * emp->sz + rc] = tmp;
				}
				return;
			}
			else 
				continue;
	}
				
}