#include "float_vector.h" 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int _time;
	int size = 3;
	srand(time(NULL));
	FloatVector *vec = create(size);
	print(vec);

	for(int i = 0; i < size; i++) {
		_time = rand()%10+1;
		append(vec, _time);
	}
	
	print(vec);

	destroy(&vec);

	return 0;
}
