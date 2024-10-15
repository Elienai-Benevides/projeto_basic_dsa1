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
	return size_list;
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
char* create_string(size_t tam) {
	char *c =(char*)calloc(tam+1, sizeof(char));	
	return c;
}
void destroy_string(char **s) {
	char* aux = *s;
	free(aux);
	*s = NULL;
}
Node *create_Node(const char *name, const char *cpf) {
	Node *node = (Node*)calloc(1, sizeof(Node));
	if(node == NULL) {
		printf("Erro ao alocar na funcao ./source/create_Node\n");
	}
	node->name = create_string(strlen(name));
	strcpy(node->name, name);
	node->cpf = create_string(strlen(cpf));	
	strcpy(node->cpf, cpf);
	
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
	size_list = 0;
	return list;		
}
void destroy_List(List **L) {
List *aux = *L;
 if(!is_empty(aux)){
	Node *itr = aux->begin;
	while(itr != NULL) {
		aux->begin = aux->begin->pnext;
		destroy_Node(&itr);
		itr = aux->begin;
	}
        free(aux);
	*L = NULL;
 }	
}
void destroy_Node(Node **node) {
	Node *aux = *node;
	destroy_string((&aux->name));
	destroy_string((&aux->cpf));
	free(aux);
	*node = NULL;
}
bool is_empty(List *L) {
	if(L != NULL) {
		if((L->begin != NULL)) {
			return false;
		} 
	}else{
		printf("struct LIsta nao declarada, log em ./source/linked_list.c/is_empty\n");
	}
	return true;
}
void insert(List *L, const char *name, const char *cpf) {
	clock_t start = clock();
	Node *node = create_Node(name, cpf);
	size_t comp, mov;
	double time;
	comp = mov = 0;
	comp++;
	if(is_empty(L)) {
		mov++;
		L->begin = node;
		//L->end = node;
	}else{
		node->pprev = L->end;
		L->end->pnext = node;
		mov+=2;
		//L->end = node;
	}
	L->end = node;
	mov++;
	size_list++;//L->size_list++;
	clock_t end = clock();
	time = timer_count(start, end); 
	printf("Insercao dos dados na lista \n Tempo: %.6f \n Nome:%s\n Rg:%s\n Comparacoes: %ld\n Movimentacao: %ld\n", time, node->name, node->cpf, comp, mov);
}
void insert_start(List *L, const char* name, const char* cpf) {
	clock_t start = clock();
	Node *node = create_Node(name, cpf);
	size_t comp, mov;
	double time;
	comp = mov = 0;
	if(!is_empty(L)) {
		node->pnext = L->begin;
	   	L->begin->pprev = node;	
		L->begin = node;
		comp += 3;
	}else{
		L->begin = node;
		L->end = node;
		comp+=2;
	}
	clock_t end = clock();
	time = timer_count(start, end);
	printf("Insercao dos dados na lista \n Tempo: %.6f\n Nome:%s\n Rg:%s\n Comparacoes: %ld\n Movimentacao: %ld\n", time, node->name, node->cpf, comp, mov);
	size_list++; //L->size_list++;
}
void insert_middle(List *L, size_t index, const char* name, const char* cpf) {
	Node *node = create_Node(name, cpf);
	clock_t start = clock();
	size_t mov, comp;
	mov = comp = 0 ;
	double time;
	if(!is_empty(L)) {
		Node *itr = L->begin;
		size_t i = 0;
	    if(index <= size_list) {
		while(i < index) {	
	  		itr = itr->pnext;
			mov++;
			i++;
		}
		comp++;
		if((itr == L->begin) && (itr == L->end)){
			node->pnext = L->begin;			
			L->begin->pprev = node;
			L->begin = node;
			L->end = node;
			mov += 4;

		}else if(itr->pprev == NULL){
				node->pnext = L->begin;
				node->pprev = L->begin->pprev;
				L->begin->pprev = node;
				L->begin = node;
				mov+=4;
		}else if(itr->pnext == NULL) {
				node->pprev = L->end->pprev;
				node->pnext = L->end;
				L->end->pprev = node;
				mov += 3;

		}else{
				node->pnext = itr;
				itr->pprev->pnext = node;
				node->pprev = itr->pprev;
				itr->pprev = node;
				mov += 4;		
		}
		size_list++;//L->size_list++;
	   }else{
		printf("Indice inexistente, e maior que tamanho a lista: %ld", size_list);
		
	   }	   
	} 
		clock_t end = clock();
		time = timer_count(start, end);
		printf("Insercao dos dados na lista \n Tempo: %.6f \n Nome:%s\n Rg:%s\n Comparacoes: %ld\n Movimentacao: %ld\n", time, node->name, node->cpf, comp, mov);
}
void deleta(List *L, Node* node) {//neste caso ja achei meu valor especifico diferente de um while() que acha todos os valores iguais a data
	//funcao de busca binaria
	//data = node retornado
	size_t mov, comp;
	mov = comp = 0;
	if(node) {	
		if((node == L->end) && (node == L->begin)) { // se for o primeiro e unico node da lista	
			destroy_Node(&node);
			L->begin = L->end = NULL;	
		}else{
			if(node->pprev == NULL) {
				node->pnext->pprev = node->pprev;
			       	L->begin = node->pnext;
				mov += 2;
				destroy_Node(&node);
			}else if(node->pnext == NULL) {
				node->pprev->pnext = node->pnext;			
				L->end = node->pprev;
				mov += 2;				
				destroy_Node(&node);				
			}else{
				node->pprev->pnext = node->pnext;
				node->pnext->pprev = node->pprev;
				mov += 2;
				destroy_Node(&node);
			}
		}
	}else{
		fprintf(stderr,"data node not found\n");
		exit(EXIT_FAILURE);
	}
	comp += 2;
	performance(&mov, &comp, mov, comp);
	size_list--;
}
Node* binary_search(List *L, const char* data) {
	printf("Funcao a implementar\n");
	Node *node = NULL;
return node;
}
void performance(size_t *mov, size_t *comp, size_t nulling_mov, size_t nulling_comp) {
	static size_t mov_;
	static size_t comp_;
	mov_ += *mov;
	comp_ += *comp;
	//printf("Comparacoes: %ld\n Movimentacao: %ld\n", comp_, mov_);
	mov_ = nulling_mov;
	comp_ = nulling_comp;	
}
double timer_count(clock_t start, clock_t end) {
	clock_t diff;
	double time_seconds;
	diff = end - start;
	time_seconds = (diff / (double)(CLOCKS_PER_SEC));
	return time_seconds;
}
void deleta_index(List *L, size_t index) {
 if(!is_empty(L)){
	clock_t start = clock();
	size_t i = 0;
	size_t mov, comp;
	double time;
	comp = mov = 0;
	Node *itr = L->begin;
	while(i < index) {
		itr = itr->pnext;
		mov++;
	i++;
	}
	printf("Deletando indice, i = %ld \n", i+1);
	i--;
	printf("Remoção dos dados na lista \n Nome:%s\n Rg:%s\n", itr->name, itr->cpf);
	deleta(L, itr);
	performance(&mov, &comp, 0, 0);
	clock_t end = clock();
	time = timer_count(start, end);
	printf("Comparacoes: %ld\n Movimentacao: %ld\n", comp, mov);
	printf("Tempo: %.6f\n", time); 
 }else{
	printf("Está vazio, nada na lista\n");
 }	
}
void deleta_middle(List *L, int value) {
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
			destroy_Node(&itr);
			itr = aux;
	     	  }
		  itr = itr->pnext;
	   }	
	}
	size_list--; //L->size_list--;
	//printf("Insercao dos dados na lista \n Nome:%s\n Rg:%s\n Comparacoes: %ld\n Movimentacao: %ld\n", node->name, node->rg, comp, mov);
}
void display(List *L) {
  if(!is_empty(L)) {
	Node *itr = L->begin;
	int cont = 0;
	while(itr != NULL) {
	  cont++;
	  printf("%d)Nome:%s\n Rg:%s\n", cont, itr->name, itr->cpf);
	  puts("  ");	  
	  itr = itr->pnext;
	}
  } 
}
void display_1(List *L) {
  if(!is_empty(L)) {	
	Node *itr = L->end;
	int cont = size_list;
	while(itr != NULL) {
	  printf("%d)Nome:%s\n Rg:%s\n", cont, itr->name, itr->cpf);
	  cont--;
	  puts("  ");	  
	  itr = itr->pprev;
	}
  }
}
void read_file(List *lista, const char *file_name) {
	clock_t start = clock();
	double time;
	FILE *file = fopen(file_name , "r");
	if(file == NULL) {
	  printf("Erro de abertura arquivo\n");
	  return;
	}
	char buffer[100];
	while((fgets(buffer, sizeof(buffer) - 1, file) != NULL)) {
		buffer[strcspn(buffer, "\n")] = '\0';
		//sscanf(buffer, "%s[^,],%s", name, cpf);
		char *token1;
		char *token2;
		char limit[] = ",";
		token1 = strtok(buffer, limit);		
		token2 = strtok(NULL, limit);
		for(int i = 0; i < strlen(token2)+1; i++) {
			token2[i] = token2[i+1]; 
		}
		insert(lista, token1, token2);
	}
	fclose(file);
	clock_t end = clock();
	time = timer_count(start, end);
	printf("open n close file timer: %6.f\n", time);

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
