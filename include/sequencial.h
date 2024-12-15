#ifndef SEQUENCIAL_H_
#define SEQUENCIAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
//typedef struct sequencial seq;
//typedef struct Data Data;
typedef struct Data {
	char* name;
	unsigned int rg;
}Data;
typedef struct sequencial{
	Data *data;
	int id;
}seq;

double timer_count_seq(clock_t start, clock_t end); 
Data *get_begin_seq(seq *L);
seq* create_sequencial();
Data* create_data();
void insert_data(seq *L, const char* name, unsigned int rg);
void destroy_data(Data **data);
void destroy_seq(seq ***L, int tam);
void display_sequencial(seq *L);
size_t get_size_vet(seq *L);
Data *get_data(seq *L);
char* get_name_seq(Data *data);
unsigned int get_rg_seq(Data *data);
Data* set_next_seq(Data **data, int i);
void read_file_sequencial(seq **L, const char* file_name);
void resize(seq *L, int tam);
void insert_index_seq(seq *L, int index, const char* name, unsigned int rg);
void insert_start_seq(seq *L, const char* name, unsigned int rg);
void insert_end_seq(seq *L, const char* name, unsigned int rg);
void remove_seq(seq *L, int index);
void find_list_seq(seq *L);
#endif
