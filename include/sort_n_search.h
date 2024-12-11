#ifndef SORT_N_SEARCH_H
#define SORT_N_SEARCH_H
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "sequencial.h"
#include <string.h>
typedef struct sort_n_search sort_list;
typedef struct ListRecorder ListRecorder;


//typedef struct _doubly_list List;
//typedef struct _doubly_node Node;
void swap_string(char **s1, char **s2);
List* get_list(sort_list *list);
List** get_address_list(sort_list *list);
sort_list* create_sort_n_search();
void destroy_sort_n_search(sort_list **list); 
void afilia_list(sort_list *list, List *L);
void afilia_seq(sort_list *list, seq *seq); 
void afilia_list_recorder(sort_list *list, ListRecorder *lista_recorder);

void insertion(sort_list *L);
void insertion_seq(sort_list *L, size_t tam);
void selection(sort_list *L, size_t tam);
void bubble(sort_list *L, size_t tam);
void MergeSort(sort_list *L, size_t init, size_t tam);
void merge(sort_list *L, size_t init, size_t middle, size_t tam);
void ShellSort(sort_list *L, size_t tam);
void QuickSort(sort_list *L, size_t init , size_t tam);
size_t partition (sort_list *L, size_t init , size_t tam);
void Binary_Search(sort_list *L, const char *key, int init, int end);
#endif


