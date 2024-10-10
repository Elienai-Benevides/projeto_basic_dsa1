#include "ListRecorder.h"
typedef struct ListRecorder{
	FileRecorder *start;
	FileRecorder *stop;
	int recorder_number;
}ListRecorder;
typedef struct FileRecorder {
	FILE *file;
	char file_name[30];
	int id;
	FileRecorder *pnext;
	FileRecorder *pprev;
}FileRecorder;
ListRecorder* create_ListRecorder() {
	ListRecorder *list = (ListRecorder*)calloc(1, sizeof(ListRecorder));
	if(list == NULL) {
		printf("Erro ao alocar na funcao ./source/create_ListRecorder\n");
	}
	list->start = NULL;
	list->stop = NULL;	
	list->recorder_number = -1;
	return list;
}
FileRecorder* create_FileRecorder(){
	FileRecorder *f = (FileRecorder*)calloc(1, sizeof(FileRecorder));
	if(f == NULL) {
		printf("Erro ao alocar na funcao ./source/create_FileRecorder\n");
	}
	f->pnext = NULL;
	f->pprev = NULL;
	f->id = -1;
	strcpy(f->file_name, " ");
	return f;
}
void destroy_list_recorder(ListRecorder **list_recorder) {
	ListRecorder *temp = *list_recorder;
	if(temp != NULL) {
		FileRecorder *itr = temp->start;
		FileRecorder *ptr;
		ptr = itr;
		while(itr != NULL) {
	  	itr = itr->pnext;
	  	free(ptr);	
	  	ptr = itr;
		}
		*list_recorder = NULL;
	}else{ printf("lista inexistente em ./source/ListRecorder/destroy_list_recorder\n");
	}
}
void destroy_file_recorder(FileRecorder **file_recorder) {
	FileRecorder *temp = *file_recorder;
	temp->file = NULL;
	strcpy(temp->file_name, " ");

	temp->id = 0;
	free(temp);
	*file_recorder = NULL;
	}
// Abertura de arquivo apenas para funcao aqui
void open_file(FileRecorder *file, const char *file_name) {
	file->file = fopen(file_name, "ab");	
		if(file->file == NULL) {
			printf("Erro ao abrir arquivo");
		}
	//}else{
	//	printf("arquivo existente\n");// caso queira fazer append
	//}
}
void close_file(FileRecorder *file) {
	if(file->file!=NULL) {
	  fclose(file->file);
	}else{
		file->file = NULL;
	}
}
//funcao p lista
void serializa(ListRecorder *L , List *lista) { // apenas serializo uma lista quue acaba de ser ordenada.
	FileRecorder *f = create_FileRecorder();	
	open_file(f,"./arquivos/generic_file.txt");//arquivo da lista dps ordenada
	//depois de abrir o arquivo da lista ordenada em sort_list;
	//
	//new document serializated
     if(f->file != NULL) {	
	f->id = get_id(lista);//atribui id a lista dps de ordenada
	strcpy(f->file_name, "./arquivos/generic_file.txt");//get_filename(lista));
        size_t tam = get_size(lista);
	Node *itr = lista->begin;//reduz o tamanho da estrutura
	//open_succes(fwrite(&(f->id), sizeof(int), 1, f->file));
	open_succes(fwrite(&tam, sizeof(size_t), 1, f->file));
	while(itr != NULL) {	
		int s_1 = strlen(itr->name);//+1;
		int s_2 = strlen(itr->cpf);//+1;
		//open_succes(fwrite(itr,sizeof(Node),1, f->file));
		open_succes(fwrite(&s_1, sizeof(int),1, f->file));
		open_succes(fwrite(itr->name, sizeof(char), s_1, f->file));
		open_succes(fwrite(&s_2, sizeof(int),1, f->file));
		open_succes(fwrite(itr->cpf, sizeof(char), s_2, f->file));
		
		itr =  itr->pnext;//funcao iteradora	
	}	
     	add(L, f);
     }else{
	printf("file nullo em ./source/ListRecorder/serializa\n");	
     }	     
	close_file(f);
}
void open_succes(int b) {
	if(!b){
		printf("fracasso\n");
	}
}
//funcao p lista
List* deserializa(ListRecorder *L, int id) { //deserializo uma lista que ja foi ordenada por sort_list na id de lista.
	FileRecorder *file = NULL;
	List *lista = create_List();
        file = search_id(L, id);
        //criar lista again                
	if(file != NULL) {
	file->file = fopen(file->file_name, "rb");
	//printf("NOME ARQUI%s\n", file->file_name);
	  size_t tam_list;
	  int id;
	  int tam_name;
	  int tam_cpf;
	  fread(&tam_list, sizeof(size_t), 1, file->file);
	  int i = 0;
	  //printf("./source/deseri = %ld\n", tam_list);
	  while(i < tam_list) {
		        Node *node = (Node*)calloc(1, sizeof(Node));
			fread(&tam_name, sizeof(int), 1, file->file);
			node->name = create_string(tam_name);//(char*)calloc(tam_name, sizeof(char));
			fread(node->name, sizeof(char), tam_name, file->file);
			fread(&tam_cpf, sizeof(int), 1, file->file);
			node->cpf = create_string(tam_cpf);//(char*)calloc(tam_cpf, sizeof(char));
		    	fread(node->cpf, sizeof(char),tam_cpf, file->file);
			if((lista->begin) == NULL) {
				lista->begin = lista->end = node;	
		   	}else{
				node->pprev = lista->end;
				lista->end->pnext = node;
		   	}
		   	lista->end = node;			
		    i++;
	   }			   
	  close_file(file); 		
	  
	}else{
		printf("Nao foi possivel achar o arquivo\n");
	}	
	return lista;	  
}
FileRecorder *search_id(ListRecorder *L, int id) {
    FileRecorder *itr;
    FileRecorder *found;
    int flag = 0;
    if(L != NULL) {
	itr = L->start;	
        while ((itr != NULL) && !flag) {
		if(itr->id == id) {
			found = itr;
			flag = 1;
		}
		if(flag) {
			return found;
		}
		itr = itr->pnext;	
	}
     }
    return NULL;
}
void add(ListRecorder *L, FileRecorder *file) {
	if(file != NULL) {
		if(L->start == NULL) {
			L->start = file;
			L->stop = file;
		}else {
			L->stop->pnext = file;
			file->pprev = L->stop;
			L->stop = file;
		}
		L->recorder_number++;
	}
}
void display_list_recorder(ListRecorder *L) {
	FileRecorder *itr = L->start;
	while(itr != NULL) {
		printf("Address FILE: %p\nfilename = %s\n id = %d\n",itr->file, itr->file_name,itr->id);
		itr = itr->pnext;
	}
}
