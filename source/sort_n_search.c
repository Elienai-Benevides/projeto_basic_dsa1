#include "sort_n_search.h"
#include "ListRecorder.h"
#include "sequencial.h"
typedef struct sort_n_search {
	List *lista;
	seq *sequencial;
	//int id_lista;
	//coesao de dados na classe objeto e.t: id,e nao na classe de algorithm; 
	ListRecorder *lista_recorder;//onde tem uma Lista_Record;
	//funcao serializa aqui e deserializa na Lista
}sort_list;
void swap_string(char **s1, char **s2) {
	char *derref = *s1;
	char *derref1 = *s2;
	char temp[strlen(derref) + 1];

	strcpy(temp, derref);
	strcpy(derref, derref1);
	strcpy(derref1, temp);
}
void afilia_list(sort_list *list, List *L) {
	list->lista = L;
}
void afilia_seq(sort_list *list, seq *seq) {
	list->sequencial = seq;
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
		//List *l = s->lista;
		//ListRecorder *list_recorder = s->lista_recorder;	
		//destroy_List(&l);
		s->lista = NULL;
		//destroy_list_recorder(&list_recorder);
		s->lista_recorder = NULL;
		s->sequencial  = NULL;
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
	//cpf = get_cpf(top);
	ind = top;
		previous = get_pprev(top);
		data = get_cpf(previous);
		while((get_pprev(ind) != NULL) && (get_cpf(top) < data)) {
			prev = get_pprev(ind);	
			strcpy(get_cpf(ind), get_cpf(prev)); //get_cpf(ind) = get_cpf(prev);
			ind = get_pprev(ind);
		}
	set_cpf(ind, cpf);
	top = get_pnext(top);	
	}
   }
}
void insertion_seq(sort_list *L , size_t tam) {
	if(L && L->sequencial) {
	seq *ptr = L->sequencial;

	Data *array = get_begin_seq(ptr); 
		for(int i = 1; i < tam; i++) {
			char key_rg[20];
			char key_name[20];
			strcpy(key_rg, array[i].rg);
			strcpy(key_name, array[i].name);
			int j = i - 1;
			while((j >= 0) && (atoi(key_rg) < atoi(array[j].rg))){	
				strcpy(array[j + 1].rg, array[j].rg);
				strcpy(array[j + 1].name, array[j].name);
				--j;	
			}
			strcpy(array[j+1].rg, key_rg);
			strcpy(array[j+1].name, key_name);
		}
	}else{ printf("Classe que ordena ou ponteiro para lista sequencial, vazios\n");	}
}
void selection(sort_list *L, size_t tam) {
if(L && L->sequencial) {
	seq *ptr = L->sequencial;
	Data *array = get_begin_seq(ptr);
	int maior = 0;
	for (int i = tam - 1; i >= 0; i--) {	
		maior = atoi(array[i].rg);
		int k = 0;
		int index = 0;
		while(k < i) {
			if(atoi(array[k].rg) > maior) {
				maior = atoi(array[k].rg);
				index = k;
			}
			k++;
		}
		char key_rg[20];
		char key_name[20];
		strcpy(key_rg, array[i].rg);
		strcpy(key_name, array[i].name);
		strcpy(array[i].rg, array[index].rg);
		strcpy(array[i].name, array[index].name);
		strcpy(array[index].rg, key_rg);
		strcpy(array[index].name, key_name);
	}
}else { printf("Classe que ordena ou ponteiro para lista sequencial, vazios\n");	       }//to do em linked_list
}
void bubble(sort_list *L, size_t tam) {
	seq *ptr = L->sequencial;
	Data *array = get_begin_seq(ptr);
	for(int i = 0; i < tam; i++) {
		for(int j = 1; j < tam; j++) {	
			if(atoi(array[j].rg) < atoi(array[j-1].rg)) {	
				swap_string(&array[j].rg, &array[j-1].rg);
				swap_string(&array[j].name, &array[j-1].name);
			}
		}	
	}
}
void merge(sort_list *L, size_t init, size_t middle, size_t tam) {
	int size_s1 = middle - init + 1;
	int size_s2 = tam - middle;
	seq  *ptr  = L->sequencial;
	Data *array = get_begin_seq(ptr);
	Data s1[size_s1], s2[size_s2];
	
	for(int i = 0; i < size_s1; i++) {	
		s1[i].rg = (char*)calloc(strlen(array[init + i].rg)+1, sizeof(char));
		s1[i].name = (char*)calloc(strlen(array[init + i].name)+1, sizeof(char));
		strcpy(s1[i].rg, array[init + i].rg);			
		strcpy(s1[i].name, array[init + i].name);
	}

	for(int j = 0; j < size_s2; j++) {
		s2[j].rg = (char*)calloc(strlen(array[middle + j + 1].rg)+1, sizeof(char));
		s2[j].name = (char*)calloc(strlen(array[middle + j + 1].name)+1, sizeof(char));
		strcpy(s2[j].rg, array[middle + j + 1].rg);
		strcpy(s2[j].name, array[middle + j + 1].name);
	}
	
	int i = 0;
	int j = 0;
	int k = init;
	
	while((i < size_s1) && (j < size_s2)) {
		if(atoi(s1[i].rg) <= atoi(s2[j].rg)) {
			strcpy(array[k].rg, s1[i].rg);
			strcpy(array[k].name, s1[i].name);
			i++;
		}else {
			strcpy(array[k].rg, s2[j].rg);
			strcpy(array[k].name, s2[j].name);
			j++;
		}
		k++;
	}

	while(i < size_s1) {
		strcpy(array[k].rg, s1[i].rg);
		strcpy(array[k].name, s1[i].name);
		free(s1[i].rg);
		free(s1[i].name);
		i++;
		k++;
	}

	while(j < size_s2) {
		strcpy(array[k].rg, s2[j].rg);
		strcpy(array[k].name, s2[j].name);
		free(s2[j].rg);
		free(s2[j].name);
		j++;
		k++;
	}
	int itr = 0;	
}
void MergeSort(sort_list *L, size_t init, size_t tam) {
	if(init < tam) {
		int q = 0;
		seq *ptr = L->sequencial;
		Data *array = get_begin_seq(ptr);

		q = init + ((tam - init) / 2);
		MergeSort(L, init, q);
		MergeSort(L, q+1, tam);
		merge(L, init, q, tam);
	}
}
void ShellSort(sort_list *L, size_t tam) {
	seq *p = L->sequencial;
	Data *array = get_begin_seq(p);

	for(int interval = tam / 2; interval > 0; interval /= 2) {
		for(int i = interval; i < tam; i += 1) {
		        char key[30];
		        char key_name[30];
			char t[50];
			strcpy(key, array[i].rg);
			strcpy(key_name, array[i].name);
			int j;
			for(j = i; (j >= interval) && (atoi(key) < atoi(array[j - interval].rg)); j-=interval) {
			strcpy(array[j].rg, array[j - interval].rg);
			strcpy(t, array[j].name);
			strcpy(array[j].name, array[j - interval].name);
			strcpy(array[j - interval].name, t);
			}
			strcpy(array[j].rg, key);
		}
	 }
}
void QuickSort(sort_list *L, size_t init , size_t tam) {
   if(init < tam) {
	size_t index = partition(L, init, tam);
	QuickSort(L, init, index-1);
	QuickSort(L, index+1, tam);
   }else{
	return;	
   }	   
}
size_t partition (sort_list *L, size_t init , size_t tam) {
	seq *p = L->sequencial;
	Data *array = get_begin_seq(p);
	//int buff = sizeof(array) / sizeof(array[0]);
	size_t index = tam;//init + (tam - init) / 2;
	char pivot[(strlen(array[index].rg)+1)];
	char vector[50];
	//static int ind;
	/*while (i < tam) { 
	    for (int j = i+1; j < tam; j++) {
		if(atoi(array[j].rg) <= atoi(pivot)) {
			strcpy(vector, array[i].rg);
			strcpy(array[i].rg, array[j].rg);
			strcpy(array[j].rg, vector); // hard coding, poderiamos fazer uma funcao swap
		i++;
		}

	    	if(atoi(array[j].rg) > atoi(pivot)) {
    	    		strcpy(vector, pivot);
			strcpy(pivot, array[i].rg);
			strcpy(array[i].rg, vector);
			ind = i;	
	    	} 
	   } 
	}*/
	int k = (init - 1);
	strcpy(pivot, array[index].rg);
	for(int i = init; i < tam; i++) {
		if(atoi(array[i].rg) <= atoi(array[index].rg)) {
		k++;//conta indice
		    strcpy(vector, array[i].rg);
	    	    strcpy(array[i].rg, array[k].rg);
		    strcpy(array[k].rg, vector); // hard coding, poderiamos fazer uma funcao swap	
		    strcpy(vector, array[i].name);
		    strcpy(array[i].name, array[k].name);     // há um problema, as string copiada para outra vigente em strcpy nao se adequa ao tamanho necessario
	            strcpy(array[k].name, vector);			    
		}
	}
	strcpy(vector, array[k + 1].rg);
	strcpy(array[k + 1].rg, array[index].rg);
	strcpy(array[index].rg, vector);
    		
	strcpy(vector, array[k + 1].name);
	strcpy(array[k + 1 ].name, array[index].name);     // há um problema, as string copiada para outra vigente em strcpy nao se adequa ao tamanho necessario
	strcpy(array[index].name, vector);

	return k + 1;//return ind;
}
void Binary_Search(sort_list *L, const char *key, int init, int end) {
	seq *ptr = L->sequencial ;
	Data *array = get_begin_seq(ptr);

	if(init > end) {
		return;
	}else{
		if(!key){return;}
		int mid = (init + end) / 2;
		if (array[mid].rg == NULL) {
        		printf("Erro: Elemento na posição %d possui campo rg nulo.\n", mid);
			return;
    		}
		if(atoi(key) ==  atoi(array[mid].rg)) {
			printf("Rg encontrado: %s" , array[mid].rg);
			printf("Indice: %d", mid + 1);
		}else if(atoi(key) > atoi(array[mid].rg)) {
			Binary_Search(L, key, mid+1, end);	
		}else {
			Binary_Search(L, key, init, mid-1);
		}	
	}
}
