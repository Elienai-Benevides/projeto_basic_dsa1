#include "sequencial.h"
/*typedef struct Data {
	char* name;
	char* rg;
}Data;*/
/*typedef struct sequencial{
	Data *data;
	int id;
}seq;
*/
static size_t size_vet = 0;
static size_t curr = 0;
double timer_count_seq(clock_t start, clock_t end) {
        clock_t diff;
        double time_seconds;
        diff = end - start;
        time_seconds = (diff / (double)(CLOCKS_PER_SEC));
        return time_seconds;
}
Data *get_begin_seq(seq *L) {
	return L->data;
}
seq* create_sequencial() {
	seq *s = (seq*)calloc(1, sizeof(seq));
	if(s == NULL) {
		printf("Erro, nao alocado em ./source/sequencial.c/create_sequencial\n");
	}
	s->data = create_data();
	//s->id = id;
	//s->num_listas = num_listas;
	return s;
}
Data* create_data() { //desacoplar dados 
	Data* d = (Data*)calloc(1, sizeof(Data));
	if(d == NULL) {
		printf("Erro, nao alocado em ./source/sequencial.c/create_data\n");

	}
	d->name = NULL;
	//d->rg = NULL;	
	return d;
}
Data *get_data(seq *L) {
   return L->data;
}
char* get_name_seq(Data *data) {
    return data->name;
}
int get_rg_seq(Data *data) {
    return data->rg;
}
void insert_data(seq *L, const char* name, int rg) {
	
	
	Data *d = L->data;
if(curr < size_vet) {
	d[curr].name = (char*)calloc((strlen(name)+1),sizeof(char));
	if((d[curr].name  == NULL)) {printf("Erro, nao alocado em ./source/sequencial.c/insert_data\n");}
	d[curr].rg = rg; //(char*)calloc((strlen(rg)+1),sizeof(char));
		
	//if((d[curr].rg) == NULL) { printf("Erro, nao alocado em ./source/sequencial.c/insert_data\n");}
	strcpy(d[(curr)].name, name);
	d[curr].rg = rg;//strcpy(d[(curr)].rg, rg);
	curr++;

}
}
void insert_start_seq(seq *L, const char* name, int rg) {
	clock_t start = clock();
	size_t comp, mov;
	double time;
	comp = mov = 0;
	Data **array = &L->data;
	//Data *ptr = *array;
	Data *new = NULL;
	size_vet++;
	if((new = realloc(*array, (size_vet) * sizeof(Data)))) {
		for(int i = size_vet-1; i > 0; i--) {
			new[i] = new[i-1];
			mov++;
		}

	}else{
		printf("Error, reallocation\n");
	}
	new[0].name = (char*)calloc(strlen(name)+1, sizeof(char));
	new[0].rg = rg;//(char*)calloc(strlen(rg)+1, sizeof(char));	
	strcpy(new[0].name, name);
	mov++;
	new[0].rg = rg;
	mov++;
	if(new != NULL) {
		*array  = new;
	}
	clock_t end = clock();
        time = timer_count_seq(start, end);
        printf("Insercao dos dados na lista SEQUENCIAL \n Tempo: %.6f\n Nome:%s\n Rg:%d\n Comparacoes: %ld\n Movimentacao: %ld\n", time, new[0].name, new[0].rg, comp, mov);
}
void insert_index_seq(seq *L, size_t index, const char* name, int rg) {
	clock_t start = clock();
	size_t mov, comp;
	mov = comp = 0;
	double time;
	Data **array = &L->data;
	//Data *ptr = *array;
	Data *new = NULL;
	size_vet++;
   if((index-1) != 0) {
	if((new = realloc(*array, (size_vet) * sizeof(Data)))) {
		for(int i = size_vet-1; i > (index-1); i--) {
			new[i] = new[i - 1];
			mov++;
		}
	}else{
		printf("Error, reallocation\n");
	}
	new[index-1].name = (char*)calloc(strlen(name)+1, sizeof(char));
	new[index-1].rg = rg;//(char*)calloc(strlen(rg)+1, sizeof(char));	
	strcpy(new[index-1].name, name);
	new[index-1].rg = rg;
  }else{
	insert_start_seq(L, name, rg);	
  }
  if(new != NULL) {
	*array = new;
  }
  clock_t end = clock();
  time = timer_count_seq(start, end);
  printf("Insercao dos dados na lista SEQUENCIAL\n Tempo: %.6f \n Nome:%s\n Rg:%d\n Comparacoes: %ld\n Movimentacao: %ld\n", time, new[index-1].name, new[index-1].rg, comp, mov);


}
void insert_end_seq(seq *L, const char* name, int rg) {
	clock_t start = clock();
	size_t mov, comp;
	double time;
	mov = comp = 0;
	Data **array = &L->data;
	//Data *ptr = *array;
	Data *new = NULL;
	size_vet++;
	if((new = realloc(*array, size_vet * sizeof(Data)))) {
		/*for(int i = 0; i < (size_vet-1); ++i) {
			new[i] = new[i+1];
		}*/
	new[size_vet-1].name = (char*)calloc(strlen(name)+1, sizeof(char));
	new[size_vet-1].rg = rg;//(char*)calloc(strlen(rg)+1, sizeof(char));	
	strcpy(new[size_vet-1].name, name);
	new[size_vet-1].rg = rg;
		
	}else{
		printf("Error, reallocation\n");
	}
	if(new != NULL) {
	    *array = new;
	}
	 clock_t end = clock();
  	time = timer_count_seq(start, end);
 	 printf("Insercao dos dados na lista SEQUENCIAL\n Tempo: %.6f \n Nome:%s\n Rg:%d\n Comparacoes: %ld\n Movimentacao: %ld\n", time, new[size_vet-1].name, new[size_vet-1].rg, comp, mov);
}
void destroy_data(Data **data) {
	Data *temp = *data;
	//Data *itr = *data;
	//char **string = NULL;
	//char *string_temp = NULL;
   if(temp != NULL) {
	for(int i = 0; i < size_vet; i++) {		
		free(temp[i].name);
		//free(temp[i].rg);
		temp[i].name = NULL;
		//temp[i].rg = NULL;

		/*string = &itr[i].name;
		string_temp = *string;
		free(string_temp);
		itr[i].name = NULL;

		string = &itr[i].rg;
		string_temp = *string;
		free(string_temp);
		itr[i].rg = NULL;	
		
		string = NULL;
		string_temp = NULL;*/
	}
	free(temp);
   	*data = NULL;
	size_vet = 0;
   }
}
void destroy_seq(seq ***L, int tam) {
 if(L != NULL) {
     seq **ptr = *L;
     for(int i = 0; i < tam; i++) {
         seq *temp = ptr[i];
	if(temp != NULL) {
	 	if(((temp->data) != NULL)) { 
	   		destroy_data(&temp->data);
	 	}
	 	free(ptr[i]);
	}
     }
     free(ptr);
     **L = NULL;
     size_vet = 0;
 }
}
void display_sequencial(seq *L) {
	Data *itr = L->data;
	int cont = 0;
	int i = 0;
	while(i < size_vet) {
		cont++;
		printf("%d)Nome: %s\n Rg: %d\n", cont, itr[i].name, itr[i].rg);
		puts("  ");
		i++;
	}
}
void read_file_sequencial(seq **L, const char* file_name) {
	seq *aux = *L;
	FILE *file = fopen(file_name,"r");
	if(file == NULL) {
		printf("Erro de abertura no arquivo\n");
		return;
	}
	char buff[100];
	
	while(fgets(buff, sizeof(buff)-1, file) != NULL) {
	
		buff[strcspn(buff, "\n")] = '\0';
		char limit[] = ",";
		char* token_name = strtok(buff, limit);		
		char* token_rg = strtok(NULL, limit);
		
		insert_data(aux, token_name, atoi(token_rg));
	}
	fclose(file);
}
size_t get_size_vet(seq *L) { //deixar explícito de qual header é o tamanho, seq.
return size_vet; 
}
size_t get_curr(seq *L) {
	return curr;
}
void resize(seq *L, size_t tam) {	
	if(L != NULL) {
		Data *temp = L->data;
		Data **ptr = &L->data;
		char **string = NULL;
		char *string_temp = NULL;
		Data *new = NULL;
		for(int i = 0; i < size_vet; i++) {
			
			//free(temp[i].name); // direto
			//free(temp[i].rg);
			//temp[i].name = NULL;
			//temp[i].rg = NULL;
						
			string = &temp[i].name; //conceitual
			string_temp = *string;
			free(string_temp);
			temp[i].name = NULL;

			string = &temp[i].name;
			string_temp = *string;
			free(string_temp);
			//temp[i].rg = NULL;
			string = NULL;
			string_temp = NULL;
		}
		size_vet = tam;
		curr = 0;
	if(*ptr != NULL){			
		if((new = realloc(*ptr, (tam) * sizeof(Data)))) {
			*ptr = new;
		}
	}

	}	
}
void remove_seq(seq *L, int index) {
	clock_t start = clock();
	size_t comp, mov;
	double time;
	comp = mov = 0;
	if(((index-1) < 0) || ((index-1) >= size_vet)) {
		printf("out of bounds\n");
		return;
	}
	
	Data **d = &L->data;
	Data *new = NULL;
	printf("Excluido: Name: %s Rg: %d\n", L->data[index-1].name, L->data[index-1].rg);
	if((L->data[index-1].name != NULL) && (L->data[index-1].rg)) {
		free(L->data[index-1].name);
		L->data[index-1].name = NULL;
		//free(L->data[index-1].rg);
		//L->data[index-1].rg = NULL;
	}
	//destroy_data(&d[index-1]);
	printf("Index: %d, Size: %ld\n", index, size_vet);
	printf("Pointer d[%d]: %p\n", index-1, &L->data[index-1]);
	
	for (int i = index-1; i < (size_vet-1); i++) {
        	L->data[i] = L->data[i + 1];
		mov++;
    	}

	size_vet--;
		
	if((new = realloc(*d, size_vet * sizeof(Data)))) {
	   *d = new;
	   //L->data = *d;
	}else{
	   printf("eRRO ao alocar, em ./source/sequencial/remove_seq\n");
	}
	clock_t end = clock();
	time = timer_count_seq(start, end);
	printf("Tempo: %.6f \n Comparações: %ld\n Movimentações: %ld\n", time, comp, mov);
}
Data* set_next_seq(Data **data, int i) {
	Data *itr = *data;
	return (itr+i);	
}
void find_list_seq(seq *L) {
	clock_t start = clock();
	double time;
	size_t mov, comp;
	comp = mov = 0;
	if(L != NULL) {   
		int data;
		int cont = 0;
		bool b = false;
		Data *d = L->data;
		printf("Entre com o Rg\n");
		scanf("%d", &data);
		int i = 0;
		while(i < get_size_vet(L)) {
		cont++;
		     if((b = get_rg_seq(&d[i]) == data)) {
			printf("SEQUENCIAL<->\n");
			printf("Nome: %d\n Rg: %d\n Indice: %d\n", 
			get_name_seq(&d[i]), get_rg_seq(&d[i]), (cont));				
		   	break;
		     }		     
		     i++;
		}
		printf("retorno b: %d \n", b);
		b == true ? printf("Encontrado\n") : printf("N Encontrado\n"); 
	}
	clock_t end = clock();
	time = timer_count_seq(start, end);
	printf("Tempo: %.6f\n", time);

	puts(" ");
}
