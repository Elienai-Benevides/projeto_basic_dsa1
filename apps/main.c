#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
#include "ListRecorder.h"
#include "sort_n_search.h"
int main() {
	List *lista = create_List();
	List *lista1 = create_List();
	set_id(lista, 0);
	set_filename(lista, "./arquivos/name_cpf.txt");
	read_file(lista, get_filename(lista));//atribui dados arquivos;
	//display(lista);
	//set_id(lista1, 1);
	//set_filename(lista1, "./arquivos/other.txt");

	ListRecorder *list_recorder = create_ListRecorder();
	sort_list *sort = create_sort_n_search();//aqui vou ter que setar lista e list_recorder depois
	//sort_list *sort1 = create_sort_n_search();


	//afilia_list(sort1, lista1);
	//afilia_list_recorder(sort1, list_recorder);

	afilia_list(sort, lista);	
	afilia_list_recorder(sort, list_recorder);
	
	//#ordenar#//
	serializa(list_recorder, get_list(sort)); // serializa nesta instancia apenas listas ordenadas;
	//serializa(list_recorder, get_list(sort1));
	//display(get_list(sort));
	//display_list_recorder(list_recorder);	
	//apaga lista;
	//cria nova lista
 	destroy_sort_n_search(&sort);//destroy_List(&lista); //lista destruida dentro da sort
	//destroy_List(&lista1);
	//destroy_List(get_address_list(sort));//retornar endereco de ponteiro.	
	lista = deserializa(list_recorder, 0);
	//lista1 = deserializa(list_recorder, 1);
	/*printf("lista deserializada:: \n ");
	Node* begin = get_begin(lista);
	char cpf[30];
	strcpy(cpf, get_cpf(begin));
	printf("cpf->>> %s", cpf);*/
	printf("lista deserializada\n");
	display(lista);	
	destroy_List(&lista);
return 0;
}
