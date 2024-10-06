#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//*********PRIVATE INTERFACE*******
struct float_vector {
	int capacity;
	int size;
	float *data;
};

bool _isfull(const FloatVector *vec) {
	return (vec->size >= vec->capacity);
}

//**********PUBLIC INTERFACE********

FloatVector *create(int capacity) {
	FloatVector *vec = (FloatVector*)calloc(1, sizeof(FloatVector));
	vec->size = 0;
	vec->capacity = capacity;
	vec->data = (float*)calloc(capacity,sizeof(float));
	return vec;
}
void destroy(FloatVector **vec) {
	free((*vec)->data);
	free(*vec);
	*vec = NULL;

}
void append(FloatVector *vec, float val) {
	if(_isfull(vec)) {//vec->size == vec->capacity
		fprintf(stderr, "ERRO IN 'APPEND()'");
		fprintf(stderr, "is FULL");
		exit(EXIT_FAILURE);
	}
	vec->data[vec->size++] = val;
}
void print(const FloatVector *vec) {
	printf("Capacity: %d\n", vec->capacity);
	printf("Size: %d\n", vec->size);
	printf("-----------------------------\n");
	for(int i = 0; i < vec->size; i++) {
		printf("vec[%d]= %.2f\n", i, vec->data[i]);
	}
	puts("--------------------------------\n");
}
int capacity (const FloatVector *vec) {
	return vec->capacity;
}
int size (const FloatVector *vec) {
	return vec->size;
}
float at(const FloatVector *vec, int index) {
	if(index < 0 || index >= vec->size) {
		fprintf(stderr, "ERROR IN 'at()'\n");
	   	fprintf(stderr, "INDEX[%d] out of bound [0, %d]\n", index, vec->capacity);	
		exit(EXIT_FAILURE);
	}
	return vec->data[vec->size];	
}

void set(const FloatVector *vec, int index, float val) {
	if (index < 0 || index >= vec->size) {
		printf("ERROR in set(), out of bound\n");
		return;
	}
	vec->data[index] = val;
}

float get(const FloatVector *vec, int index) {
	return vec->data[index];
}
