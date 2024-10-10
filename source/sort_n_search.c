#include "sort_n_search.h"
#include "ListRecorder.h"
typedef struct sort_n_search {
	List *lista;
	//int id_lista;
	//coesao de dados na classe objeto e.t: id,e nao na classe de algorithm; 
	ListRecorder *lista_recorder;//onde tem uma Lista_Record;
	//funcao serializa aqui e deserializa na Lista
}sort_list;
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void afilia_list(sort_list *list, List *L) {
	list->lista = L;
}
void afilia_list_recorder(sort_list *list, ListRecorder *lista_recorder) {
	list->lista_recorder = lista_recorder;
}
List* get_list(sort_list *list) {
	return (list->lista);	
}
List **get_address_list(sort_list *list) {
	return &(list->lista);
}
//to do: crio construtora e atribuir lista
sort_list* create_sort_n_search() {
	sort_list *s = (sort_list*)calloc(1, sizeof(sort_list));
	if(s == NULL) {
		printf("Erro ao alocar na funcao ./source/sort_n_search.c/create_sort_n_search\n");
	}
	s->lista = NULL;
	s->lista_recorder = NULL;
	return s;
}
void destroy_sort_n_search(sort_list** list) {
	sort_list *s = *list;
     if(s != NULL) {	
		List *l = s->lista;
		ListRecorder *list_recorder = s->lista_recorder;	
		//destroy_List(&l);
		s->lista = NULL;
		//destroy_list_recorder(&list_recorder);
		s->lista_recorder = NULL;
		free(s);
		*list = NULL;	
     }else {
	     printf("classe sort_n_search inexistente\n");
     }
}
void insertion(sort_list *L) {
   List *Laux = L->lista;
   if(!is_empty(Laux)) {
	char *cpf;
	char *data;
	Node *previous;
	Node *prev;
	Node *first_node = get_begin(Laux);
	Node *top = get_pnext(first_node);
	Node *ind = top;
	cpf = get_cpf(top);

	while(get_pnext(top) != NULL) {
	cpf = get_cpf(top);
	ind = top;
		previous = get_pprev(top);
		data = get_cpf(previous);
		while((get_pprev(ind) != NULL) && (cpf < data)) {
			prev = get_pprev(ind);	
			strcpy(get_cpf(ind), get_cpf(prev));//get_cpf(ind) = get_cpf(prev);
			ind = get_pprev(ind);
		}
	set_cpf(ind, cpf);
	top = get_pnext(top);	
	}
   }
}
void selection(int *vet, int tam) {
	int index = 0;
	int k = 0;

	for(int i = tam - 1; i > 0; i++) {
		
		while(k < i) {
			if(vet[k] > vet[i]) {
				index = k;
			}
		k++;
		}
	swap(&vet[index], &vet[i]);
	}	
//to do em linked_list
}
void bubble();
void merge();
void shell();


