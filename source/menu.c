#include "menu.h"
typedef struct Menu {
	List* list;
	sort_list *list_sort;
	ListRecorder *list_recorder;
}menu;
menu* create_Menu() {
	menu *m = (menu*)calloc(1,sizeof(menu));
	m->list = create_List();
	m->list_sort = create_sort_n_search();
	m->list_recorder = create_ListRecorder();
	return m;	
}
void destroy_Menu(menu **m) {
	menu *temp  = *m;
	List *list_linked = temp->list;
	sort_list *list_sort = temp->list_sort;
	ListRecorder* list_recorder = temp->list_recorder;
	
	destroy_List(&list_linked);
 	destroy_sort_n_search(&list_sort);
	destroy_list_recorder(&list_recorder);
	
	temp->list = NULL;
	temp->list_sort = NULL;
	temp->list_recorder = NULL;
}
bool handle_alphanum(int *op, char C) {
	if(scanf("%d", op) != 1) {
		printf("Entrada invalida, entre com um inteiro\n");
		while(((C = getchar()) != '\n') && (C != EOF)) {
		//	if(C == '\n') { break;}
		}

		return false;
	}
	return true;
}
void executar(menu *m) {
	int op = 0;
	char name[30], cpf[30];
	int index;
	char filename[30];
	while(op != 11) {
		printf("Forneça a as seguintes opções de entrada\n");
		printf("1)inserir no inicio da lista\n");
		printf("2)inserir na posicao N\n");
		printf("3)inserir no fim da lista\n");
		printf("4)Remover no inicio da lista\n");
		printf("5)Remover na posição N da lista\n");
		printf("6)Remover no fim da lista\n");
		printf("7)Procurar nó com campo rg\n");
		printf("8)Mostrar lista na tela\n");
		printf("9)Salvar a lista em arquivo\n");
		printf("10)Ler a lista de um arquivo\n");
		printf("11)Sair do Sistema\n");
		puts(" ");
		printf("> ");
		//scanf("%d", &op);
		char c;
		if(!handle_alphanum(&op, c)) { continue;}
		switch(op) {
		   case 1: { 
				   printf("Entre com os dados; \n");
			           printf("NOME:\n");
				   scanf("%s", name);
				   printf("RG:\n");
				   scanf("%s", cpf);
				   insert_start(m->list,name,cpf);
			  printf("tamanho lista = %ld!", get_size(m->list)); }
		   break;
		   case 2: { 
				   printf("Entre com os dados; \n");
			           printf("NOME:\n");
				   scanf("%s", name);
				   printf("RG:\n");
				   scanf("%s", cpf);
				   printf("INDIce\n");
				   scanf("%d", &index);
				   insert_middle(m->list, (index-1),name,cpf); }
		   break;
		   case 3: { 
				   printf("Entre com os dados; \n");
			           printf("NOME:\n");
				   scanf("%s", name);
				   printf("RG:\n");
				   scanf("%s", cpf);
				   insert(m->list,name,cpf);
			  }
		   break;
		   case 4: { 
				   deleta_index(m->list,0);
			   }
		   break;
		   case 5: { 
				   printf("Defina o indice\n");
				   int index = 0;
				   scanf("%d", &index);
				   deleta_index(m->list,(index-1));
			   }
		   break;
		   case 6: {
				   deleta_index(m->list, get_size(m->list)-1);
			   }
		   break;
		   case 7: {  
			      List *lista = m->list;	   
			      Node* n = get_begin(lista);
			      char data[30];
			      int cont = 0;
			      bool b = false;
			      printf("Entre com o Rg");
			      scanf("%s", data);
			      while(n != NULL) {
				  cont++;
			          if((b = (strcmp(get_cpf(n), data) == 0)) ) {
					printf("name: %s\n Rg: %s\n Indice: %d", 
					get_name(n), get_cpf(n), (cont));
						
				   }
				      n = get_pnext(n);
			       }
			      b == true ? printf("Encontrado\n") : printf("N Encontrado\n"); 

	 /*binary_search*/ }
		   break;
		   case 8: { display(m->list);}
		   break;
	           case 9: { serializa(m->list_recorder, m->list); }
		   break;
		   case 10: { 	
				int option = 0;
				    while(option != 6) {
					printf("Escolha os arquivos\n");
					printf("1)Arquivo de 10\n");
					printf("2)Arquivo de 100\n");
					printf("3)Arquivo de 1k\n");
					printf("4)Arquivo de 1M\n");
					printf("5)Arquivo de 100M\n");
					printf("6)Sair\n");
					scanf("%d", &option);
					switch(option) {
						case 1: { read_file(m->list, "./arquivos/NomeRG1K.txt");
						       printf("Lista lida do arquivo\n");}
					  	break;
					   	case 2: { 
						       read_file(m->list, "b"); 
						       printf("Lista lida do arquivo\n");}
						break;
						case 3: { 

								read_file(m->list,  "c");
						      		printf("Lista lida do arquivo\n");						   }
						break;
						case 4: { read_file(m->list, "d"); 
						       	  printf("Lista lida do arquivo\n");	
							
							}
						break;
						case 5: {							
								read_file(m->list, "e");
						     		printf("Lista lida do arquivo\n"); 	}
						break;
						case 6: { printf("Saindo...\n"); }
						break;
						default: { printf("Opção inválida, tente novamente\n"); }
					}

				    }
		   }
	           break;
		   case 11: { printf("Saindo...\n"); }	
		   break;
		   default: { printf("Opcao invalida, tente novamente\n"); }
		   break;
		}
	}
}
