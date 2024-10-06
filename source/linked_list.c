#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include "linked_list.h"
/*typedef struct _doubly_list{
	Node *begin;
	Node  *end;
	char filename[30];
	size_t size_list;
	int id;	
}List;
typedef struct _doubly_node{
	Node *pprev;
	Node *pnext;
	int value;
	char name[30];
	char cpf[30];
}Node;*/
int get_value(Node* curr_knot){
	return curr_knot->value;
}
char* get_name(Node* curr_knot) {
	return curr_knot->name;
}
char* get_cpf(Node* curr_knot) {
	return curr_knot->cpf;
}
int get_id(List *L) {
	return L->id;
}
void set_id(List *L, int id) {
	L->id = id;
}
char *get_filename(List *L) {
	return L->filename;
}
size_t get_size(List *L) {
	return L->size_list;
}
void set_value(Node *knot, int value) {
	knot->value = value;
}
void set_name(Node *knot, const char *name) {
	strcpy(knot->name,name);
}
void set_cpf(Node *knot, const char *cpf) {
	strcpy(knot->cpf,cpf);
}
void set_filename(List *L, const char* filename) {
	strcpy(L->filename,filename);
}
Node *create_Node(const char *name, const char *cpf) {
	Node *node = (Node*)calloc(1, sizeof(Node));
	if(node == NULL) {
		printf("Erro ao alocar na funcao ./source/create_Node\n");
	}
	//strcpy(node->name, name);
	//strcpy(node->cpf, cpf);
	node->name = name;
	node->cpf = cpf;
	node->pprev = node->pnext = NULL;
	return node;
}
List *create_List(){
	List* list = (List*)calloc(1,sizeof(List));	
	if(list == NULL) {
		printf("Erro ao alocar na funcao ./source/create_List\n");
	}
	list->begin = NULL;
	list->end = NULL;
	list->size_list = 0;
	return list;		
}
void destroy_List(List **L) {
List *aux = *L;
if(!is_empty(aux)){
	Node *itr = aux->begin;

	while(itr != NULL) {
		aux->begin = aux->begin->pnext;
		free(itr->name);
		free(itr->cpf);
		free(itr);
		itr = aux->begin;
	}
        free(aux);
	*L = NULL;
}	
}
void destroy_Node(Node **node) {
	Node *aux = *node;
	free(aux);
	*node = NULL;
}
bool is_empty(List *L) {
	if((L->begin != NULL)) {
		return false;
	} 
	return true;
}
void insert(List *L, const char *name, const char *cpf) {
	Node *node = create_Node(name, cpf);
	if(is_empty(L)) {
		L->begin = node;
		//L->end = node;
	}else{
		node->pprev = L->end;
		L->end->pnext = node;
		//L->end = node;
	}
	L->end = node;
	L->size_list++;
}
void insert_start(List *L, const char* name, const char* cpf) {
	Node *node = create_Node(name, cpf);
	if(!is_empty(L)) {
		node->pnext = L->begin;
	   	L->begin->pprev = node;	
	}else{
		L->begin = node;
		L->end = node;
	}
	L->size_list++;
}
void insert_middle(List *L, int index, const char* name, const char* cpf) {
	Node *node = create_Node(name, cpf);
	if(!is_empty(L)) {
		Node *itr = L->begin;
		int i = 0;
		while(i < index) {	
	  		itr = itr->pnext; 
			i++;
		}
		if((itr->pprev != NULL)) {
	  		node->pnext = itr;
	  		node->pprev = itr->pprev;
		  	itr->pprev = node;
		}else if((itr->pnext == NULL) && (itr->pprev == NULL)){
			node->pnext = L->end = L->begin;
			L->end->pprev = node;
			L->end = L->begin = node;
		}else{
			node->pnext = L->begin;
	  		L->begin->pprev = node;
			L->begin = node;
	  	}	
		L->size_list++;
	}	
}
void deleta(List *L, Node* data) {
	Node *itr;
	Node *itr1 = data;
	//funcao de busca binaria
	//data = node retornado
	itr = L->begin;
	if(data) {	
		if((L->begin == L->end) && (L->begin == data)) { // se for o primeiro e unico node da lista
			itr->pnext->pprev = L->begin->pprev;
			L->begin = itr->pnext;			
			destroy_Node(&itr);			
		}else {//se for o primeiro de uma lista
			itr = itr->pnext;
	  		if(itr == L->end) {
				L->begin->pnext = L->end->pnext;
				L->end = NULL;
				destroy_Node(&itr);
			}
			if(itr->pnext == NULL) {
				itr->pprev->pnext = itr->pnext;
				L->end = itr->pprev;
				destroy_Node(&itr);
				L->size_list--;

			}else{
				itr->pprev->pnext = itr->pnext;
				itr->pnext->pprev = itr->pprev;
			}
		}
	}else {
		fprintf(stderr,"data node not found\n");
		exit(EXIT_FAILURE);
	}
}
Node* binary_search(List *L, const char* data) {
	printf("Funcao a implementar\n");
	Node *node = NULL;
return node;
}
//forget it middle
void deleta_Middle(List *L, int value) {
	Node *itr, *aux;
	if(!is_empty(L)) {       
	itr = L->begin;
	   while(itr != NULL) {
	     if(itr->value == value) {
	       if(itr->pprev != NULL) {
	         if(itr->pnext == NULL) {
		    L->end = itr->pprev;
		 }
		 itr->pprev->pnext = itr->pnext;
	       }else{
		     	L->begin = itr->pnext;
	       }
			aux = itr->pprev;
			destroy_Node(&itr); //free(itr);
			itr = aux;
	     }
		itr = itr->pnext;
	   }	
	}
	L->size_list--;

}
void display(List *L) {
if(!is_empty(L)) {
	Node *itr = L->begin;
	int cont = 0;
	while(itr != NULL) {
	  cont++;
	  printf("%d)Nome:%s\n Rg:%s\n", cont, itr->name, itr->cpf);	  
	  itr = itr->pnext;
	}
}
}
void read_file(List *lista, const char *file_name) {
	FILE *file = fopen(file_name , "r");
	if(file == NULL) {
	  printf("Erro de abertura arquivo\n");
	  return;
	}
	char buffer[100];
	while((fgets(buffer, sizeof(buffer) - 1, file) != NULL)) {
		buffer[strcspn(buffer, "\n")] = '\0';
		//sscanf(buffer, "%s[^,],%s", name, cpf);
		char *token;
		char limit[] = ",";
		token = strtok(buffer, limit);
		char *new_char = (char*)calloc(strlen(token)+1, sizeof(char));
		
		//new_char[strlen(token)] = '\0';
		strcpy(new_char, token);
		token = strtok(NULL, limit);
		for(int i = 0; i < strlen(token)+1; i++) {
			token[i] = token[i+1]; 
		}	
	        char *new_char1 = (char*)calloc(strlen(token)+1, sizeof(char));	
		strcpy(new_char1, token);
		//token_name = strtok(buffer, ",");
		//toke_cpf = strtok(",", );
		insert(lista, new_char, new_char1);
	}
	fclose(file);
}
Node* get_pnext(Node *knot) {
	return knot->pnext;
}
Node* get_pprev(Node *knot) {
	return knot->pprev;
}
Node* get_begin(List *L) {
	return L->begin;
}
Node* get_end(List *L) {
	return L->end;
}
void set_pprev(Node** knot, Node** knot1) {
	Node *temp = *knot;
	Node *temp1 = *knot1;
	temp->pprev = temp1;	
}
void set_pnext(Node** knot, Node** knot1) {
	Node *temp = *knot;
	Node *temp1 = *knot1;
	temp->pnext = temp1;
}
void set_begin(List *L, Node *knot1) {
	L->begin = knot1;
}
void set_end(List *L, Node* knot1) {
	L->end = knot1;
}
void iter(Node **knot, Node *knot1) {
	Node *node = *knot;
	node = knot1->pnext; // recebe proximo pnext

}
