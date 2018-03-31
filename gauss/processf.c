#include "gauss.h"

static bool disposer(FILE * eq, char * temparr);
static void readvar(FILE * eq, EQSYS * ep);
static void matrix_check(EQSYS * ep);

EQSYS * processf(FILE * eq)
{
	bool minus;
	char * temp;
	EQSYS * ep = (EQSYS *) malloc(sizeof(EQSYS));	
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) {
			minus = disposer(eq, temp);
			fscanf(eq, "%lf", &(ep->matrix[i][j]));
			readvar(eq, ep);
			if (minus)
				ep->matrix[i][j] *= -1;
			if (j == 2) {
				minus = disposer(eq, temp);
				fscanf(eq, "%lf", &(ep->freememb[i]));
				if (minus)
					ep->freememb[i] *= -1;
			}

		}
	
	matrix_check(ep);
	return ep;
}

static bool disposer(FILE * eq, char * temparr)
{
	bool minus = false;
	int temp =0;
	while(!isdigit(temp = getc(eq)))
		if (temp == '-')
			minus = true;
	ungetc(temp, eq);
	return minus;

	
}

static void readvar(FILE * eq, EQSYS * ep)
{
	static int calls = 0;
	int temp = getc(eq);
		
	if (calls <= 2)
		ep->desig[calls] = temp;
	else if (calls > 2) 
		if (temp != ep->desig[calls % 3]) {
			puts("ERFORMAT");
			exit(1);
		}
	if (!(((temp = getc(eq)) == ' ') || temp == '-' || temp == '+')) {
		puts("ERFORMAT");
		exit(1);
	}
	else
		ungetc(temp, eq);
}

static void matrix_check(EQSYS * ep)
{
	double a;
	if (!ep->matrix[0][0] && ep->matrix[1][0])
		for (int j = 0; j < 3; j++) {
			a = ep->matrix[0][j];
			ep->matrix[0][j] = ep->matrix[1][j];
			ep->matrix[1][j] = a;
		}
}


			
		

