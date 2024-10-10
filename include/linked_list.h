#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
	typedef struct ListRecorder ListRecorder;
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
		int id;	
	}List;       
	static size_t size_list = 0; 
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
	size_t get_size(List *L);

	Node* create_Node(const char* name, const char* cpf);
	char* create_string(size_t tam);
	List* create_List();
	void destroy_string(char** s);
	void insert(List *L, const char*name, const char* cpf);
	void insert_start(List *L, const char *name, const char *cpf);
	void insert_middle(List *L, size_t index, const char *name, const char *cpf);
	void destroy_List(List **L);
	void destroy_Node(Node **node);
	void deleta_middle(List *L, int value); //interessante que a assinatura deste metodo na implementaÇÃo independe do seguno parametro  int value mas considera o tipo, apenas.
	void deleta_index(List *L, size_t index); 
	void deleta(List *L, Node* node);//deleta apos busca binaria
	Node *binary_search(List *L, const char* data);
	bool is_empty(List *L);
	void display(List *L);
	void iter(Node **knot, Node *knot1);

	void read_file(List *lista, const char *file_name);

	Node* get_pnext(Node *knot);
	Node* get_pprev(Node *knot);
	Node* get_begin(List* L);
	Node* get_end(List* L);
	void set_begin(List *L, Node *knot1);
	void set_end(List *L, Node* knot1);
	void set_pprev(Node **knot, Node** knot1);
	void set_pnext(Node **knot, Node** knot1);
#endif
