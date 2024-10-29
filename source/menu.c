#include "menu.h"
typedef struct Menu {
	List *list;
	List *list1;
	List *list2;
	List *list3;
	List *list4;
	sort_list *list_sort;
	seq *seq_list;
	ListRecorder *list_recorder;
	File_Template *template_file;	
}menu;
static size_t cont_id = 0;
menu* create_Menu() {
	menu *m = (menu*)calloc(1,sizeof(menu));
	//m->list = create_List(0);
	m->list_sort = create_sort_n_search();
	m->list_recorder = create_ListRecorder();
	m->seq_list = create_sequencial();
	m->template_file = create_file_template();
	return m;
}
void destroy_Menu(menu **m) {
	menu *temp  = *m;
	destroy_List(&temp->list);
	destroy_List(&temp->list1);
 	destroy_List(&temp->list2);
 	destroy_List(&temp->list3);
 	destroy_List(&temp->list4);

 	destroy_sort_n_search(&temp->list_sort);
	destroy_list_recorder(&temp->list_recorder);
	destroy_seq(&temp->seq_list);
	destroy_Template(&temp->template_file);	
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
		switch(op){
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
		   case 8: {
				   //destroy_List(&m->list);
			          //m->list = deserializa(m->list_recorder, 0);

				   int option = 0;
				   while(option != 6) {
					   printf("1)Listar linked list NomeRg 10: \n");
					   printf("2)Listar linked list NomeRg 1k \n");
					   printf("3)Listar linked list NomeRg 10K \n");
				           printf("4)Listar linked list NomeRg 1M \n");	   
				     	   printf("5)Listar linked list NomeRg 10M\n");   
					   printf("6) Sair\n");
					   char c;
					   handle_alphanum(&option, c);
					if(option == 1) {
					   if(m->list != NULL) {
						//m->list = deserializa(m->list_recorder, 0);
   
					   	display(m->list);
					   }else{
					   	printf("Lista vazia!\n");
					   }
					   //display_sequencial(m->seq_list);
				   	}else if(option == 2) {
					   if(m->list1 != NULL) {
						//m->list1 = deserializa(m->list_recorder, 1);

					   	display(m->list1);
					   }else{
					   	printf("Lista vazia!\n");
					   }
				 	}else if(option == 3){
					   if(m->list2 != NULL) {
						//m->list2 = deserializa(m->list_recorder, 2);

					   	display(m->list2);
					   }else{
					   	printf("Lista vazia!\n");
					   } 
					}else if(option == 4) {
					   if(m->list3 != NULL){
	
						//m->list3 = deserializa(m->list_recorder, 3);
						display(m->list3);
					   }else{
						printf("Lista vazia!\n");
					   }
					}else if(option ==5) {
					   if(m->list4 != NULL) {
						//m->list4 = deserializa(m->list_recorder, 4);
		
					   	display(m->list4);
					   }else{
						printf("Lista vazia!\n");
					   }
					}else {
						 printf("Saindo..Optou por entrada inválida ou opção 3) sair\n");

					}	
				   }
			    }
		   break;
	           case 9: { 
				   int option = 0;
				   while(option != 6) {
					   printf("1)Listar linked list NomeRg 10: \n");
					   printf("2)Listar linked list NomeRg 1k \n");
					   printf("3)Listar linked list NomeRg 10K \n");
				           printf("4)Listar linked list NomeRg 1M \n");	   
				     	   printf("5)Listar linked list NomeRg 10M\n");   
					   printf("6) Sair\n");
					   char c;
					   handle_alphanum(&option, c);
					if(option == 1) { 
						serializa(m->list_recorder, m->list); 
				   	}else if(option == 2) {
					  	serializa(m->list_recorder, m->list1); 
				 	}else if(option == 3){
					   	serializa(m->list_recorder, m->list2); 
					}else if(option == 4) {
					 	serializa(m->list_recorder, m->list3); 
					}else if(option ==5) {
					  serializa(m->list_recorder, m->list4); 
					}else {
						 printf("Saindo..Optou por entrada inválida ou opção 3) sair\n");

					}	
				   }

				   
			    }
		   break;
		   case 10: { 	
				int option = 0;
				    while(option != 6) {
					printf("Escolha os arquivos\n");
					printf("1) Arquivo de 10\n");
					printf("2) Arquivo de 1K\n");
					printf("3) Arquivo de 10k\n");
					printf("4) Arquivo de 1M\n");
					printf("5) Arquivo de ~10M\n");
					printf("6) Sair\n");
					scanf("%d", &option);
					switch(option) {
						case 1: { 
							  	m->list = create_List(cont_id++);
							
								set_recorder_list(m->list, m->list_recorder);
								set_name_template(m->template_file, "./arquivos/NomeRG10.txt");
								set_size_template(m->template_file, 10);
								set_cod_nome(m->template_file, "./arquivos/10.txt");
							  	read_file(m->list, m->template_file);
								destroy_List(&m->list);
							  	m->list = deserializa(m->list_recorder, 0);
								set_recorder_list(m->list, m->list_recorder);

							  	//resize(m->seq_list, 10);
							  	//read_file_sequencial(m->seq_list, "./arquivos/NomeRG10.txt");
						       		printf("Lista lida do arquivo\n");}
					  	break;
					   	case 2: {
								m->list1 = create_List(cont_id++);
							  	set_recorder_list(m->list1, m->list_recorder);
								set_name_template(m->template_file, "./arquivos/NomeRG1K.txt");
								set_size_template(m->template_file, 1000);
								set_cod_nome(m->template_file, "./arquivos/1K.txt");
							  	read_file(m->list1, m->template_file);
								destroy_List(&m->list1);
							  	m->list1 = deserializa(m->list_recorder, 1);
								set_recorder_list(m->list1, m->list_recorder);

							  	//resize(m->seq_list, 10);
							  	//read_file_sequencial(m->seq_list, "./arquivos/NomeRG1K.txt");
						       		printf("Lista lida do arquivo\n");}

						break;
						case 3: {  m->list2 = create_List(cont_id++);
							  	set_recorder_list(m->list2, m->list_recorder);
								set_name_template(m->template_file, "./arquivos/NomeRG10K.txt");
								set_size_template(m->template_file, 10000);
							  	set_cod_nome(m->template_file, "./arquivos/10K.txt");
								read_file(m->list2, m->template_file);
								destroy_List(&m->list2);
							  	m->list2 = deserializa(m->list_recorder, 2);
							  	set_recorder_list(m->list2, m->list_recorder);

								//resize(m->seq_list, 10);
							  	//read_file_sequencial(m->seq_list, "./arquivos/NomeRG10K.txt");
						       		printf("Lista lida do arquivo\n"); }    
						break;
						case 4: { 	m->list3 = create_List(cont_id++);
							  	set_recorder_list(m->list3, m->list_recorder);
								set_name_template(m->template_file, "./arquivos/NomeRG1M.txt");
								set_size_template(m->template_file, 1000000);
							  	set_cod_nome(m->template_file, "./arquivos/1M.txt");
								read_file(m->list3, m->template_file);
								destroy_List(&m->list3);
							  	m->list3= deserializa(m->list_recorder, 3);
							  	set_recorder_list(m->list3, m->list_recorder);

								//resize(m->seq_list, 10);
							  	//read_file_sequencial(m->seq_list, "./arquivos/NomeRG1M.txt");
						       		printf("Lista lida do arquivo\n");	
							}
						break;
						case 5: {
								m->list4 = create_List(cont_id++);
							  	set_recorder_list(m->list4, m->list_recorder);
								set_name_template(m->template_file, "./arquivos/NomeRG100M.txt");
								set_size_template(m->template_file, 11748444);
							  	set_cod_nome(m->template_file, "./arquivos/100M.txt");
								read_file(m->list4, m->template_file);
								destroy_List(&m->list4);
							  	m->list4 = deserializa(m->list_recorder, 4);
							  	set_recorder_list(m->list4, m->list_recorder);

								//resize(m->seq_list, 11748444);
							  	//read_file_sequencial(m->seq_list, "./arquivos/NomeRG100M.txt");
						       		printf("Lista lida do arquivo\n");	

						     	}
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
