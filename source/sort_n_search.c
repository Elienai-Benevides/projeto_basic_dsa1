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
	        char *n;
		n = NULL;
		n = (char*)calloc((strlen(*s1) + 1), sizeof(char));
		strcpy(n, *s1);
		char *ptr_char;
		if((ptr_char = realloc(*s1, strlen(*s2) + 1))) {
	        	*s1 = ptr_char;
		}
		strcpy(*s1, *s2);
	        if((ptr_char = realloc(*s2, (strlen(n) + 1)))) {
			*s2 = ptr_char;
		}
		strcpy(*s2, n);
		free(n);
}
void fit_string(char **s1, char **s2) {
		char *ptr_char;
		if((ptr_char = realloc(*s1, strlen(*s2) + 1))) {
	        	*s1 = ptr_char;
		}
		strcpy(*s1, *s2);
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
			int key_rg;
			char key_name[20];
			key_rg = array[i].rg;
			strcpy(key_name, array[i].name);
			int j = i - 1;
			while((j >= 0) && (key_rg < array[j].rg)){	
				array[j + 1].rg = array[j].rg;
				strcpy(array[j + 1].name, array[j].name);
				--j;	
			}
			array[j+1].rg = key_rg;
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
		maior = array[i].rg;
		int k = 0;
		int index = 0;
		while(k < i) {
			if(array[k].rg > maior) {
				maior = array[k].rg;
				index = k;
			}
			k++;
		}
		int key_rg;
		char key_name[20];
		key_rg = array[i].rg;
		strcpy(key_name, array[i].name);
		array[i].rg = array[index].rg;
		strcpy(array[i].name, array[index].name);
		array[index].rg = key_rg;
		strcpy(array[index].name, key_name);
         }
}else { printf("Classe que ordena ou ponteiro para lista sequencial, vazios\n");	       }//to do em linked_list
}
void bubble(sort_list *L, size_t tam) {
	seq *ptr = L->sequencial;
	Data *array = get_begin_seq(ptr);
	for(int i = 0; i < tam; i++) {
		for(int j = 1; j < tam; j++) {	
			if(array[j].rg < array[j-1].rg) {
				int aux;
				aux = array[j].rg;	
				array[j].rg  = array[j-1].rg;
				array[j-1].rg = aux;
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
	//Data s1[size_s1], s2[size_s2];
	Data *s1, *s2;
	s1 = (Data*)calloc(size_s1, sizeof(Data));
	s2 = (Data*)calloc(size_s2, sizeof(Data));
	for(int i = 0; i < size_s1; i++) {	
		//s1[i].rg = (char*)calloc(strlen(array[init + i].rg)+1, sizeof(char));
		//s1[i].name = (char*)calloc(strlen(array[init + i].name)+1, sizeof(char));
		s1[i].rg = array[init + i].rg;			
		fit_string(&s1[i].name, &array[init + i].name);
	}

	for(int j = 0; j < size_s2; j++) {
		//s2[j].rg = (char*)calloc(strlen(array[middle + j + 1].rg)+1, sizeof(char));
		//s2[j].name = (char*)calloc(strlen(array[middle + j + 1].name)+1, sizeof(char));
		s2[j].rg = array[middle + j + 1].rg;
		fit_string(&s2[j].name, &array[middle + j + 1].name);
	}
	
	int i = 0;
	int j = 0;
	int k = init;
	
	while((i < size_s1) && (j < size_s2)) {
		if(s1[i].rg <= s2[j].rg) {
		     if(s2[i].rg != s1[j].rg){
			fit_string(&array[k].name, &s1[i].name);
	             }else {
			strcpy(array[k].name, s1[i].name);		
		     }
			array[k].rg = s1[i].rg;
		     i++;
		}else {
			array[k].rg = s2[j].rg;
			fit_string(&array[k].name, &s2[j].name);
			j++;
		}
		k++;
	}

	while(i < size_s1) {
		array[k].rg = s1[i].rg;
		fit_string(&array[k].name, &s1[i].name);
		free(s1[i].name);
		i++;
		k++;
	}
	free(s1);
	while(j < size_s2) {
		array[k].rg = s2[j].rg;
		fit_string(&array[k].name, &s2[j].name);
		free(s2[j].name);
		j++;
		k++;
	}
	free(s2);
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
		        int key;
		        //char key_name[30];
			//char t[50];
			key = array[i].rg;
			//strcpy(key_name, array[i].name);
			int j;
			for(j = i; (j >= interval) && (key < array[j - interval].rg); j-=interval) {
			
			swap_string(&array[j].name, &array[j - interval].name);	
			array[j].rg = array[j - interval].rg;
			}
			array[j].rg = key;
		}
	 }
}
void QuickSort(sort_list *L, int init , int tam) {
  if(init < tam) {
	seq *p = L->sequencial;
	Data *array = get_begin_seq(p);
	//int buff = sizeof(array) / sizeof(array[0]);
	uint32_t pivo =(tam + init)/2;
	int left = init;
	int right = tam - 1;
	int var;
     if(array != NULL){
	while(left <= right){
		while(array[left].rg < array[pivo].rg) { left++; }
		while(array[right].rg > array[pivo].rg) { right--; }	
	     
		  swap_string(&array[left].name, &array[right].name);
		  var = array[left].rg;
		  array[left].rg = array[right].rg;
		  array[right].rg = var;		
		  
		  left++;
		  right--;			
	}
	if(right > init) { QuickSort(L, init, right + 1); }
	if(left < tam) { QuickSort(L, left, tam); }
     }
   }
}
void Binary_Search(sort_list *L, int key, int init, int end) {
	seq *ptr = L->sequencial;
	Data *array = get_begin_seq(ptr);

	if(init > end) {
		return;
	}else{
		if(!key) {return;}
		int mid = (init + end) / 2;
		if (!array[mid].rg) {
        		printf("Erro: Elemento na posição %d possui campo rg nulo.\n", mid);
			return;
    		}
		if(key == array[mid].rg) {
			printf("Rg encontrado: %d" , array[mid].rg);
			printf("Indice: %d", mid + 1);
		}else if(key > array[mid].rg) {
			Binary_Search(L, key, mid+1, end);	
		}else {
			Binary_Search(L, key, init, mid-1);
		}	
	}
}

/*	clock_t start = clock();
	size_t mov, comp;
	mov = comp = 0 ;
	double time;
	if(!is_empty(L)) {
		Node *itr = L->begin;
		size_t i = 0;
	    if(index <= size_list) {
		while(i < index) {	
	  		itr = itr->pnext;
			mov++;
			i++;
		}
		comp++;
		if((itr == L->begin) && (itr == L->end)){
			node->pnext = L->begin;			
			L->begin->pprev = node;
			L->begin = node;
			L->end = node;
			mov += 4;

		}else if(itr->pprev == NULL){
				node->pnext = L->begin;
				node->pprev = L->begin->pprev;
				L->begin->pprev = node;
				L->begin = node;
				mov+=4;
		}else if(itr->pnext == NULL) {
				node->pprev = L->end->pprev;
				node->pnext = L->end;
				L->end->pprev = node;
				mov += 3;

		}else{
				node->pnext = itr;
				itr->pprev->pnext = node;
				node->pprev = itr->pprev;
				itr->pprev = node;
				mov += 4;		
		}
		size_list++;//L->size_list++;
	   }else{
		printf("Indice inexistente, e maior que tamanho a lista: %ld", size_list);
		
	   }	   
	} 
		clock_t end = clock();
		time = timer_count(start, end);
		printf("LISTA LIGADA\n");
	printf("Insercao dos dados na lista \n Tempo: %.6f \n Nome:%s\n Rg:%s\n Comparacoes: %ld\n Movimentacao: %ld\n", time, node->name, node->cpf, comp, mov);
*/
