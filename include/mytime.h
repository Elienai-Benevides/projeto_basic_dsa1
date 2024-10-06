#ifndef APP_MYTIME_H
#define APP_MYTIME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct clock_t timer;
typedef struct app_mytime {
	clock_t start;
	clock_t end;
	double resultado;

}App_Mytime;
//typedef struct clock_t timer
double delta(clock_t start, clock_t end);





#endif
