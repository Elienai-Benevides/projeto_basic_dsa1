#ifndef LISTRECORDER_H
#define LISTRECORDER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "sort_n_search.h"
typedef struct FileRecorder FileRecorder;
typedef struct ListRecorder ListRecorder;

ListRecorder* create_ListRecorder();
FileRecorder* create_FileRecorder();
void open_file(FileRecorder *file, const char *file_name); 
void close_file(FileRecorder *file);
void serializa(ListRecorder *L , List *lista);
List* deserializa(ListRecorder *L, int id); 
FileRecorder *search_id(ListRecorder *L, int id);
void add(ListRecorder *L, FileRecorder *file);
void display_list_recorder(ListRecorder *L);
void open_succes(int b);
#endif
