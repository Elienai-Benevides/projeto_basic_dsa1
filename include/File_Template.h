#ifndef FILE_TEMPLATE_H
#define FILE_TEMPLATE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct File_Template File_Template;
File_Template* create_file_template();
void set_name_template(File_Template *T, const char* name);
void set_size_template(File_Template *T, size_t size);
char *get_name_template(File_Template *T);
size_t get_size_template(File_Template *T);
void set_cod_nome(File_Template *T, const char* codnome);
void destroy_Template(File_Template **T);
char* get_cod_nome(File_Template *T);
#endif
