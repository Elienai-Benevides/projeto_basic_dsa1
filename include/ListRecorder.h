#ifndef LISTRECORDER_H
#define LISTRECORDER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "sort_n_search.h"
typedef struct FileRecorder FileRecorder;
typedef struct FileRecorder {
	FILE *file;
	char file_name[30];
	int id;
	FileRecorder *pnext;
	FileRecorder *pprev;
}FileRecorder;
typedef struct ListRecorder ListRecorder;
static size_t size_list_recorder  = 0; 
ListRecorder* create_ListRecorder();
FileRecorder* create_FileRecorder();
void destroy_list_recorder(ListRecorder **list_recorder);
void destroy_file_recorder(FileRecorder **file_recorder);
const char* get_FileRecorder_name(FileRecorder *f);
void set_FileRecorder_name(FileRecorder *f, const char* name);
void open_file(FileRecorder *file, const char *file_name); 
void close_file(FileRecorder *file);
void serializa(ListRecorder *L , List *lista);
List* deserializa(ListRecorder *L, int id); 
FileRecorder *search_id(ListRecorder *L, int id);
void add(ListRecorder *L, FileRecorder *file);
void display_list_recorder(ListRecorder *L);
void open_succes(int b);
size_t get_size_list_recorder();

void set_FileRecorder_id(FileRecorder *f,int id);
void set_FileRecorder_file(FileRecorder *f, FILE *ptr);
FILE* get_FileRecorder_file(FileRecorder *f);
#endif
