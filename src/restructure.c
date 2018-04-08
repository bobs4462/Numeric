#include "library.h"

void restructure(SLE *emp)
{
	int sz = emp->sz;
	double tmp = 0;
	bool chng = false;
	
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - 1; j++) {
			if (i != j) 
				tmp += fabs(emp->mx[i * sz + j]);
		}
		if (fabs(emp->mx[i * sz + i]) >= tmp) {
			tmp = 0;
#ifdef DIAGNOSTICS
					printf("Пропускаю строку %d\n", i + 1);
#endif
			continue;
		}
		else {
			for (int k = i + 1; k < sz - 1; k++) {
			 	if (fabs(emp->mx[k * sz + i]) >= tmp) {
					for (int m = 0; m < sz; m++) {
						tmp = emp->mx[i * sz + m];
						emp->mx[i * sz + m] = emp->mx[k * sz + m];
						emp->mx[k * sz + m] = tmp;
					}
#ifdef DIAGNOSTICS
					show_state(emp);
#endif
					chng = true;
					break;
				}
			}
			if (!chng) {
				for (int k = i + 1; k < sz - 1; k++) {
					tmp = 0;
					for (int j = 0; j < sz - 1; j++) {
						if (k != j)
							tmp += fabs(emp->mx[i * sz + j]);
					}
					if (fabs(emp->mx[i * sz + k]) >= tmp) {
						for (int m = 0; m < sz - 1; m++) {
							tmp = emp->mx[m * sz + i];
							emp->mx[m * sz + i] = emp->mx[m * sz + k];
							emp->mx[m * sz + k] = tmp;
						}
#ifdef DIAGNOSTICS
						show_state(emp);
#endif
						chng = true;
						break;
					}
				}
			}
			if (!chng) {
				printf(INAPPL);
				exit(1);
			}
			else {
				tmp = 0;
				chng = false;
			}
		}
	}
}
			




