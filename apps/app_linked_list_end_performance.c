#define CLOCKS_PER_SEC
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"
#include "mytime.h"
#define TAM_LISTA 20
int main(int argc, const char *argv[]){
	float result;
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


	for(int i = 0; i < n_elem; i++)  {
		start = clock();
		add_end_list_slow(L_slow, i);	
		end = clock();
		result = delta(start, end);
		printf("\ntempo comparacao = %d, %f \n",i, result);
	}

	srand(time(NULL));
	//int val;
	
/*	free(L_slow);
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

	free(L);
       return 0;
}

