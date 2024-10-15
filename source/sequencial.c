#include "sequencial.h"
typedef struct Data {
	char* name;
	char* rg;
}Data;
typedef struct sequencial{
	Data *data;
}seq;

static size_t size_vet = 0;
static size_t curr = 0;

seq* create_sequencial() {
	seq *s = (seq*)calloc(1, sizeof(seq));
	if(s == NULL) {
		printf("Erro, nao alocado em ./source/sequencial.c/create_sequencial\n");
	}
	s->data = create_data();
	return s;
}
Data* create_data() { //desacoplar dados 
	Data* d = (Data*)calloc(1, sizeof(Data));
	if(d == NULL) {
		printf("Erro, nao alocado em ./source/sequencial.c/create_data\n");

	}
	d->name = NULL;
	d->rg = NULL;	
	return d;
}
void insert_data(seq *L, const char* name, const char* rg) {
	Data *d = L->data;
if(curr <= size_vet) {
	d[curr].name = (char*)calloc((strlen(name)+1),sizeof(char));
	if((d[curr].name  == NULL)) {printf("Erro, nao alocado em ./source/sequencial.c/insert_data\n");}
	d[curr].rg = (char*)calloc((strlen(rg)+1),sizeof(char));
	if((d[curr].rg) == NULL) {printf("Erro, nao alocado em ./source/sequencial.c/insert_data\n");}
	strcpy(d[(curr)].name, name);
	strcpy(d[(curr)].rg, rg);
	curr++;
}
}
void insert_start_seq(seq *L, const char* name, const char* rg) {
	Data **array = &L->data;
	Data *ptr = *array;
	
	if((ptr = realloc(ptr, size_vet * sizeof(Data)))) {
		for(int i = 0; i < size_vet; i++) {
			ptr[i+1] = ptr[i];
		}
	}else{
		printf("Error, reallocation\n");
	}
	ptr[0].name = (char*)calloc(strlen(name)+1, sizeof(char));
	ptr[0].rg = (char*)calloc(strlen(name)+1, sizeof(char));	
}
void insert_index(seq *L, size_t index, const char* name, const char* rg) {
	return;		
}
void destroy_data(Data **data) {
	Data *temp = *data;
	//Data *itr = *data;
	//char **string = NULL;
	//char *string_temp = NULL;
   if(temp != NULL) {
	for(int i = 0; i < size_vet; i++) {		
		free(temp[i].name);
		free(temp[i].rg);
		temp[i].name = NULL;
		temp[i].rg = NULL;

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
   }
}
void destroy_seq(seq **L) {
   seq *temp = *L;
   if(temp != NULL) { 
	destroy_data(&temp->data);
	free(temp);
	*L = NULL;
   }
}
void display_sequencial(seq *L) {
	Data *itr = L->data;
	int cont = 0;
	int i = 0;
	while(i < size_vet) {
		cont++;
		printf("%d)Nome: %s\n Rg: %s\n", cont, itr[i].name, itr[i].rg);
		puts("  ");
		i++;
	}
}
void read_file_sequencial(seq *L, const char* file_name) {
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
		for(int i = 0; i < strlen(token_rg)+1; i++) {
			token_rg[i] = token_rg[i+1];
		}		
		insert_data(L, token_name, token_rg);
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
			temp[i].rg = NULL;
			string = NULL;
			string_temp = NULL;
		}
		size_vet = tam;
		curr = 0;
			
		*ptr = realloc(*ptr, tam * sizeof(Data));
	}	
}
