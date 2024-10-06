#include "float_vector.h"
#include "mytime.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int _time;
	int size = 3;
	//timer diff; // diferencial de tempo do programa'
	clock_t start;
	clock_t end;
	double result;
	start = clock();
	srand(time(NULL));
	FloatVector *vec = create(size);
	print(vec);
	//diff.start = clock();
	for(int i = 0; i < size; i++) {
		_time = rand()%10+1;
		append(vec, _time);
	}
	
	print(vec);

	destroy(&vec);
	//diff.end = clock();
        end = clock();
	result = delta(start, end);
	printf("time de execucao: %f \n", result);
	return 0;
}
