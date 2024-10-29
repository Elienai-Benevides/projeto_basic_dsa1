#include "File_Template.h"
typedef struct File_Template {
	char name[30];
	size_t size_file;
	char codnome[30];
}File_Template;
File_Template* create_file_template() {
	File_Template *f = (File_Template*)calloc(1, sizeof(File_Template));

	strcpy(f->name,  " ");
	strcpy(f->codnome, " ");
	f->size_file = 0;
	
	return f;
}
void destroy_Template(File_Template **T) {
	File_Template *ptr = *T;
	ptr->size_file = 0;
	free(ptr);
	*T = NULL;
}
void set_name_template(File_Template *T, const char* name) { 	
	strcpy(T->name,name);	
}
void set_size_template(File_Template *T, size_t size) {
	T->size_file = size;
}
char *get_name_template(File_Template *T) {
	return T->name;
}
size_t get_size_template(File_Template *T) {
	return T->size_file;
}
void set_cod_nome(File_Template *T, const char* codnome) { 	
	strcpy(T->codnome, codnome);
}
char* get_cod_nome(File_Template *T) {
	return T->codnome;
}
