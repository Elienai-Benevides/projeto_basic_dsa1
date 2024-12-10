#include "menu.h"
typedef struct Menu {
	List **listas;
	sort_list *list_sort;
	seq **seq_list;
	ListRecorder *list_recorder;
	File_Template *template_file;
	int num_listas;	
}menu;
menu* create_Menu(int num_listas) {
	menu *m = (menu*)calloc(1,sizeof(menu));
	m->num_listas = num_listas;
	m->listas = NULL;
	m->seq_list = NULL;
	m->listas = (List**)calloc(num_listas, sizeof(List*));
	m->seq_list = (seq**)calloc(num_listas, sizeof(seq*));
	for(int i = 0; i < num_listas; i++) {
		m->listas[i] = create_List(i, 1);
		m->seq_list[i] = create_sequencial();
	}
	m->list_sort = create_sort_n_search();
	m->list_recorder = create_ListRecorder();
	//m->seq_list = create_sequencial();
	m->template_file = create_file_template();
	return m;
}
void destroy_Menu(menu **m) {
	menu *temp  = *m;
	destroy_List(&temp->listas, temp->num_listas);
 	destroy_sort_n_search(&temp->list_sort);
	destroy_list_recorder(&temp->list_recorder);
	destroy_seq(&temp->seq_list, temp->num_listas);
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
void listar(seq **sequencial, List **linked) {
  seq *seq_list = *sequencial;
  List *list = *linked; 
  if(((seq_list != NULL) && (get_data(seq_list))) && ((list != NULL) && (get_begin(list)))) {
	Data *seq = get_data(seq_list);
	Node *itr = list->begin;
	int cont = 0;
	int i = 0;
	printf("\t----------------------------------\t---------------------------------\n");
	printf("\t\tLISTA SEQUENCIAL\t\t\t\tLISTA LIGADA\n");
	printf("\t--------------------------------------\t-----------------------------\n");
	printf("\n");
	char C;
	while((i < get_size_vet(seq_list)) && (itr != NULL)) {
		cont++;
		printf("|%d)Nome1: %s", cont, get_name_seq(set_next_seq(&seq, i)));
		printf("\t\t\t\t\t\t\t");

		printf("|%d)Nome2: %s|\n",cont, get_name(itr));

		printf("|Rg1: %s", get_rg_seq(set_next_seq(&seq, i)));
		printf("\t\t\t\t\t\t\t");
	
		printf("|Rg2: %s|\n",get_cpf(itr));
		puts(" ");		
	  	itr = itr->pnext;
		i++;
	}
  }else{
	printf("Listas vazias\n");	
  }
}
void executar(menu *m) {
	int op = 0;
	char name[30], cpf[30];
	int index;
	char filename[30];

	while(op != 12) {
		printf("Forneça a as seguintes opções de entrada\n");
		printf("1)inserir no inicio da lista\n");
		printf("2)inserir na posicao N\n");
		printf("3)inserir no fim da lista\n");
		printf("4)Remover no inicio da lista\n");
		printf("5)Remover na posição N da lista\n");
		printf("6)Remover no fim da lista\n");
		printf("7)Procurar nó com campo rg\n");
		printf("8)Ordenar lista\n");
		printf("9)Mostrar lista na tela\n");
		printf("10)Salvar a lista em arquivo\n");
		printf("11)Ler a lista de um arquivo\n");
		printf("12)Sair do Sistema\n");
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

				   insert_start(m->listas[itr_list], name, cpf);
				   insert_start_seq(m->seq_list[itr_seq], name, cpf);

			           //printf("tamanho lista = %ld!", get_size(m->listas[itr_list])); 
			   }
		   break;
		   case 2: { 
				   printf("Entre com os dados; \n");
			           printf("NOME:\n");
				   scanf("%s", name);
				   printf("RG:\n");
				   scanf("%s", cpf);
				   printf("INDIce\n");
				   scanf("%d", &index);
				   
				   insert_middle(m->listas[itr_list], index-1, name, cpf);
				   insert_index_seq(m->seq_list[itr_seq], index, name, cpf);
			}
		   break;
		   case 3: { 
				   printf("Entre com os dados; \n");
			           printf("NOME:\n");
				   scanf("%s", name);
				   printf("RG:\n");
				   scanf("%s", cpf);

				   insert(&(m->listas[itr_list]), name, cpf);
				   insert_end_seq(m->seq_list[itr_seq], name, cpf);
			   }
		   break;
		   case 4: { 	 			
			           deleta_index(m->listas[itr_list], 0);
				   remove_seq(m->seq_list[itr_seq], 1);	   				
			   }
		   break;
		   case 5: { 
				   printf("Defina o indice\n");
				   int index = 0;
				   scanf("%d", &index);

				   deleta_index(m->listas[itr_list], (index-1));
			   	   remove_seq(m->seq_list[itr_list], (index)); 	   
			   }
		   break;
		   case 6: {
				   deleta_index(m->listas[itr_list], (get_size(&m->listas[itr_list])-1));
 				   remove_seq(m->seq_list[itr_seq], (get_size_vet(m->seq_list[itr_seq])));
			   }
		   break;
		   case 7: { 
				int o = 0;

				while(o != 3) {
				  	printf("1)Busca sequencial\n");
					printf("2)Busca Binária\n");
					printf("3)Sair\n");
					char c;
					if(!handle_alphanum(&o, c)) { continue; }
				  if(o == 1){	   
				   	find_list(m->listas[itr_list]);
				   	find_list_seq(m->seq_list[itr_seq]);
				  }else if (o == 2) {
					char key[30];
					printf("Entre com o Dado: \n");
					scanf("%s", key);
					clock_t start = clock();
					double time;

					Binary_Search(m->list_sort, key, 0, get_size_vet(m->seq_list[itr_list]) - 1);
					clock_t end_ = clock();
					time = timer_count(start, end_);
					printf("Tempo: %.6f \n", time);
					puts(" ");

				  }else if(o == 3) {
					printf("Saindo... ou Entrada desconhecida\n");
				  }
				}	  

	 /*binary_search*/ }
		   break;
		   case 8: {
				int opt = 0;
				while(opt != 7) {
					printf("1)Bubble Sort\n");
					printf("2)Selection Sort\n");
					printf("3)Insertion Sort\n");
					printf("4)Merge Sort\n");
					printf("5)Quick Sort\n");
					printf("6)Shell Sort\n");
					printf("7)Sair");
					char c;
					if(!handle_alphanum(&opt, c)) { continue;}
					
					if (opt == 1) {
						bubble(m->list_sort, get_size_vet(m->seq_list[itr_seq]));	
					}else if(opt == 2) {
						selection(m->list_sort, get_size_vet(m->seq_list[itr_seq]));
					}else if(opt == 3) {
						insertion_seq(m->list_sort, get_size_vet(m->seq_list[itr_seq])); 
					}else if(opt == 4) {
							MergeSort(m->list_sort, 0, get_size_vet(m->seq_list[itr_seq]) - 1);
					}else if(opt == 5) {
							QuickSort(m->list_sort, 0, get_size_vet(m->seq_list[itr_seq]) - 1);	
					}else if(opt == 6) {
							ShellSort(m->list_sort, get_size_vet(m->seq_list[itr_seq])); 
					}else{
						printf("Saindo...\n");
					}
			         }
			   }
		   break;
		   case 9: {
				
				   listar(&m->seq_list[itr_seq], &m->listas[itr_list]);
				   
			   }
		   break;
	           case 10: { 
				   serializa(m->list_recorder, m->listas[itr_list]);					   
			    }
		   break;
		   case 11: { 	
				char name_file[30] = {"./arquivos/NomeRG10.txt" };
					printf("Entre com nome do arquivo: \n");
					//scanf("%s", name_file);					  				
					//set_recorder_list(m->list, m->list_recorder);
					set_name_template(m->template_file, name_file);
					//set_size_template(m->template_file, 10);
					//set_cod_nome(m->template_file, "./arquivos/10.txt");
					read_file(&m->listas[++itr_list], m->template_file);
					//destroy_List(&m->list);
					//m->list = deserializa(m->list_recorder, 0);
					//set_recorder_list(m->list, m->list_recorder);
					resize(m->seq_list[++itr_seq], get_size()/*m->listas[itr_list])*/);
					printf("check %ld\n", get_size() /*m->listas[itr_list])*/);
					read_file_sequencial(&m->seq_list[itr_seq], name_file);
					
					afilia_seq(m->list_sort, (m->seq_list[itr_seq]));
						
					printf("itr_list: %ld \n ",itr_list);
					printf("itr_seq: %ld \n", itr_seq);
		   }
	           break;
		   case 12: { printf("Saindo...\n"); }	
		   break;
		   default: { printf("Opcao invalida, tente novamente\n"); }
	           break;
		}
	}
}
