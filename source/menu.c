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
		printf("7)Procurar nó com campo rg");
		printf("8)Mostrar lista na tela\n");
		printf("9)Salvar a lista em arquivo\n");
		printf("10)Ler a lista de um arquivo\n");
		printf("11)Sair do Sistema\n");
		puts(" ");
		printf("> ");
		scanf("%d", &op);
		switch(op) {
		   case 1: { 
				   printf("Entre com os dados; \n");
			           printf("NOME:\n");
				   scanf("%s", name);
				   printf("RG:\n");
				   scanf("%s", cpf);
				   insert_start(m->list,name,cpf); }
		   break;
		   case 2: { 
				   printf("Entre com os dados; \n");
			           printf("NOME:\n");
				   scanf("%s", name);
				   printf("RG:\n");
				   scanf("%s", cpf);
				   printf("INDIce\n");
				   scanf("%d", &index);
				   insert_middle(m->list, index,name,cpf); }
		   break;
		   case 3: { 
				   printf("Entre com os dados; \n");
			           printf("NOME:\n");
				   scanf("%s", name);
				   printf("RG:\n");
				   scanf("%s", cpf);
				   insert(m->list,name,cpf); }
		   break;
		   case 4: { deleta_index(m->list,1); }
		   break;
		   case 5: { 
				   printf("INDIce\n");
				   deleta_index(m->list,index); }
		   break;
		   case 6: { deleta_index(m->list, get_size(m->list)); }
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
					switch(option) {
						case 1: { read_file(m->list, "a");  }
					   	break;
					   	case 2: { read_file(m->list, "b");  }
						break;
						case 3: { read_file(m->list,  "c");  }
						break;
						case 4: { read_file(m->list, "d");  }
						break;
						case 5: { read_file(m->list, "e");  }
						break;
						case 6: { printf("Saindo...\n"); }
						default: { printf("Opção inválida, tente novamente\n"); }
					}

				    }
		   }
		   case 11: { printf("Saindo...\n"); }	
		   break;
		   default: { printf("Opcao invalida, tente novamente\n"); }
		}
	}
}
