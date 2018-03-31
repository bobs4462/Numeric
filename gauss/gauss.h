#ifndef HELPER_H
#define HELPER_H

#define GREETING "Здравствуйте, вас приветствует программа Numeric\nПроверяю файл на входе...\n"
#define FILEREQ  "Кажется вы не указали файл для обработки, пожалуйста укажите его\n-> "
#define FILEFND  "Найден файл на входе, обрабатываю...\n"
#define DETISZ   "Определитель вашего уровнения равен нулю...\n"
#define FAREWELL "Всего вам хорошего, заходите ещё!"

#include <stdlib.h>
#include <stdbool.h>
//static const struct timespec trq = {0, 30000000L};
//static struct timespec trm;
typedef struct {
	unsigned short sz;
	double mx[];
} SLE;

void talktu(char * messege);
SLE * processf(FILE *efp);
FILE * requestf(void);
double * gcompute(SLE * emp);
double determ(SLE * emp);


#endif
