#ifndef SEQUENCIAL_H_
#define SEQUENCIAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sequencial seq;
typedef struct Data Data;
seq* create_sequencial();
Data* create_data();
void insert_data(seq *L, const char* name, const char* rg);
void destroy_data(Data **data);
void destroy_seq(seq **L);
void display_sequencial(seq *L);
size_t get_size_vet(seq *L);
void read_file_sequencial(seq *L, const char* file_name);
void resize(seq *L, size_t tam);
void insert_index(seq *L, size_t index, const char* name, const char* rg);
void insert_start_seq(seq *L, const char* name, const char* rg);
#endif
