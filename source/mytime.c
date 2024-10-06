#include "mytime.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
typedef struct app_mytime App_MyTime;
double delta (clock_t start, clock_t end) {
        double timeInSecond;
	clock_t even = end - start;
	timeInSecond = (even/((double)(CLOCKS_PER_SEC)));

 	return timeInSecond;	
}
