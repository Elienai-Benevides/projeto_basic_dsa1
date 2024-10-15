#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "sort_n_search.h"
#include "ListRecorder.h"
#include "sequencial.h"
typedef struct Menu menu;
menu* create_Menu();
void destroy_Menu(menu **m);
void executar(menu *m);
bool handle_alphanum(int *op, char C); 
#endif
