#define CLOCKS_PER_SEC
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"
#include "mytime.h"
#define TAM_LISTA 20
int main(int argc, const char *argv[]){
	//------- CHAINED DOUBLY LIST-----------------------
	
	List *L = create_List();
	

	insert(L, 11);
	//insert(L, 2);
	//insert(L, 33);
	//insert(L, 42);
	//insert(L, 15);
	display(L);
        //insert_start(L ,100);			
 
	//deleta_Middle(L, 999);

        //destroy_list(&L);
	//printf("\nadicÃo no ìnicio\n");

	display(L);
		deleta_Middle(L, 11);
	//	deleta_Middle(L, 33);
//		deleta_Middle(L, 15);
	//	deleta_Middle(L,15);

		//puts("tentar deletaer um elemento qu nao exite");
		//deleta_Middle(L, 999);

		printf("excluiu o valor escolhido\n");	
		display(L);
		puts(" ");
	//	puts("deletae o 2");
	//	deleta_Middle(L, 2);

		display(L);

		//puts("REMOve o 42");
		//deleta_Middle(L, 42);

		display(L);

		// ------------SIMPLE CHAINED LIST----------------
		
		
		/*linked_list *L_fast = linkedlist_create();
			
		add_end_list(L_fast, 17);
		add_end_list(L_fast, 22);
		add_end_list(L_fast, 35);
		add_end_list(L_fast, 99);
		
		display(L_fast);
		//linked_list_deleta_begin(L_fast, 1);
		//linked_list_deleta_Middle(L_fast, 3);
	//my_deleta_func(L_fast, 4);
	//my_deleta_func(L_fast, 3);
	//my_deleta_func(L_fast, 2);
	//my_deleta_func(L_fast, 1);//
		printf("first value of list = %d\n", Middle_value(L_fast, 5));
	linked_list_destroy(&L_fast);//nao tenho como acessar este endereço mais depois de executar esta funcao com uma funcao de display toda a lista na main
	
	//first_value(L_fast); --------> segfault;

	puts("depois da remoção ------>\n ");
//	display(L_fast);
	*/	
	/*float result;
	clock_t start;
	clock_t end;
	linked_list *L_slow = linkedlist_create();
	linked_list *L_fast = linkedlist_create();
	linked_list *L_new_insert = linkedlist_create();
	printf("\n %d <n_elementos>\n", argc);
	int n_elem = atoi(argv[1]);

	printf("n,time\n");
	if(argc != 2) {
		printf("\n %d <n_elementos>\n", argc);
	
		printf("\n argv = %s \n", *argv);
		exit(-1);
	}
	puts("");

	printf("\n argv = %s \n", *argv);

	printf("usando func add_end_list(a rapida)\n");
	puts("antes da remocao ------->\n");	
	add_end_list(L_fast, 1);
	add_end_list(L_fast, 2);
	add_end_list(L_fast, 3);
	add_end_list(L_fast, 4);
	display(L_fast);
	linked_list_deleta(L_fast, 3);

	puts("depois da remoção ------>\n ");
	display(L_fast);
	puts("mais uma remocao  ------>\n ");
	linked_list_deleta(L_fast, 2);
	display(L_fast);
	srand(time(NULL));
	//int val
	
	free(L_slow);
	free(L_fast);

	L_slow = linkedlist_create();
	L_fast = linkedlist_create();

	start = clock();
	for(int i = 0, cont = 2; i < TAM_LISTA; i++,cont++) {
		//val = rand()%10+1;
		//add_first_list(L, cont); 1) first method
		add_end_list_slow(L_slow, cont);	  //2)second methodd
		
	}
	end = clock();
	result = delta(start, end);
	printf("\nDelta lista lenta = %f\n", result);

	start = clock();
 	for(int i = 0, cont = 2; i < TAM_LISTA; i++,cont++) {
		//val = rand()%10+1;
		//add_first_list(L, cont); 1) first method
		//add_end_list_slow(L, cont);    2)second methodd
		add_end_list(L_fast, cont);
 	}
	end = clock();
	result = delta(start, end);
	printf("Delta lista rapida = %f\n", result);

	for(int i = 0, cont = 2; i < TAM_LISTA; i++,cont++) {
		//val = rand()%10+1;
		//add_first_list(L, cont); 1) first method
		//add_end_list_slow(L, cont);    2)second methodd
		add_first_list(L_new_insert, cont);
 	}


 
      	 display(L_new_insert);
	 linked_list **p = &L_slow; // **p = &L(certo, aqui tem um &de ptr para strct,  **p = L , aqui ha um & strct linked_list
   	 printf("\ntamanho &L: %ld\n", sizeof(&L_slow));
	 printf("\ntamanho L: %ld\n", sizeof(*p)); // p = &L

        linked_list **p1 = &L_fast; // **p = &L(certo, aqui tem um &de ptr para strct,  **p = L , aqui ha um & strct linked_list
   	 printf("\ntamanho &L: %ld\n", sizeof(&L_fast));
	 printf("\ntamanho L: %ld\n", sizeof(*p1)); // p = &L
*/
       return 0;
}

