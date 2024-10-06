#ifndef SORT_N_SEARCH_H
#define SORT_N_SEARCH_H
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include <string.h>
typedef struct sort_n_search sort_list;
typedef struct ListRecorder ListRecorder;
//typedef struct _doubly_list List;
//typedef struct _doubly_node Node;
List* get_list(sort_list *list);
List** get_address_list(sort_list *list);
sort_list* create_sort_n_search();
void destroy_sort_n_search(sort_list **list); 
void afilia_list(sort_list *list, List *L);
void afilia_list_recorder(sort_list *list, ListRecorder *lista_recorder);
void swap(int *a, int *b);
void insertion(sort_list *L);
void selection(int *vet, int tam);
void bubble();
void merge();
void shell();
#endif


