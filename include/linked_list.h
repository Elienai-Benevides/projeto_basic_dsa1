#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <time.h>
#include <File_Template.h>
#define NAME_RG_10M 11748444
#define NAME_RG_10K 10000
#define NAME_RG_1k 1000
#define NAME_RG_10 10
	typedef struct ListRecorder ListRecorder;
	typedef struct File_Template File_Template;
	//typedef struct _doubly_list List;	
	typedef struct _doubly_node Node;
	
	typedef struct _doubly_node{
		Node *pprev;
		Node *pnext;
		int value;
		char *name;
		char *cpf;
	}Node; 
	typedef struct _doubly_list{
		Node *begin;
		Node  *end;
		char filename[30];
		//size_t size_list;
		ListRecorder *recorder_list;
		int id;	
	}List;       
	static size_t size_list = 0; 
	
	void set_recorder_list(List *L, ListRecorder *recorder_list);
	int get_value(Node* curr_knot);
	char* get_name(Node* curr_knot);
	char* get_cpf(Node* curr_knot);
	void set_value(Node *knot, int value); 
	void set_name(Node *knot, const char *name); 
	void set_cpf(Node *knot, const char *cpf);
        void set_filename(List *L,const char *filename);	
	int get_id(List *L);
	void set_id(List *L, int id);
	char *get_filename(List *L);
	size_t get_size();


	Node* create_Node(const char* name, const char* cpf);
	char* create_string(size_t tam);
	List* create_List(int id, int num_listas);
	void destroy_string(char** s);
	void insert(List **L, const char* name, const char* cpf);
	void insert_start(List *L, const char *name, const char *cpf);
	void insert_middle(List *L, size_t index, const char *name, const char *cpf);
	void destroy_List(List ***L, int tam);
	void destroy_Node(Node **node);
	void deleta_middle(List *L, int value); //interessante que a assinatura deste metodo na implementaÇÃo independe do seguno parametro  int value mas considera o tipo, apenas.
	void deleta_index(List *L, size_t index); 
	void deleta(List *L, Node* node);//deleta apos busca binaria
	Node *binary_search(List *L, const char* data);
	bool is_empty(List *L);
	void push(List **L, const char *name, const char *cpf);
	void iter(Node **knot, Node *knot1);
	void read_file(List **lista, File_Template *T);

	double timer_count(clock_t start, clock_t end);
	Node* get_pnext(Node *knot);
	Node* get_pprev(Node *knot);
	Node* get_begin(List* L);
	Node* get_end(List* L);
	void set_begin(List *L, Node *knot1);
	void set_end(List *L, Node* knot1);
	void set_pprev(Node **knot, Node** knot1);
	void set_pnext(Node **knot, Node** knot1);
	void performance(size_t *mov, size_t *comp, size_t nulling_mov, size_t nulling_comp);
	void display(List *L);
	void display_1(List *L);
	void set_size(size_t size);
	void find_list(List *L);
#endif
