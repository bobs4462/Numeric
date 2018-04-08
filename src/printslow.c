#include <time.h>
#include "library.h"


void printslow(char * string)
{
    const struct timespec trq = {0, 15000000L};
	struct timespec trm;
	for (int i = 0; i < strlen(string); i++) {
		printf("%c", string[i]);
		nanosleep(&trq, &trm);
	}
}
