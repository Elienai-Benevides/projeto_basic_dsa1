#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "sort_n_search.h"
#include "ListRecorder.h"
#include "sequencial.h"
#include "File_Template.h"
typedef struct Menu menu;
typedef struct File_Template File_Template;
static size_t cont_id = 0;
static size_t itr_list = -1;
static size_t itr_seq = -1;
menu* create_Menu(int num_listas);
void destroy_Menu(menu **m);
void executar(menu *m);
void listar(seq **sequencial, List **linked); 
bool handle_alphanum(int *op, char C);  
#endif
