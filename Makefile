APPS = ./apps
SRC = ./source
BIN = ./bin
OBJ = ./obj
LIB = ./lib
INCLUDE = ./include
FLAGS = -O3 -Wall 
LIBS = -lm -led -L $(LIB)
COMENTARIO = "A parada eh que se n existisse checkagem na criacao dos bin com libed.a nas depend do target myapps(dependencias)\
	     poderia dar desincronizacao na compilacao \
	     tambem posso colocar em myapps: como dependencia um novo target libed que checa dependen de new obj e update ./lib"\

all: libed myapps

hello:
	echo "Hallo1"
	tree .
	
libed: \
	$(OBJ)/mytime.o \
	$(OBJ)/linked_list.o \
        $(OBJ)/sort_n_search.o\
	$(OBJ)/ListRecorder.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o

myapps: \
	libed \
	$(BIN)/main

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h		
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@	


$(BIN)/%: $(APPS)/%.c $(LIB)/libed.a 
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@ 

run:
	$(BIN)/app
	$(BIN)/mytime 

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/* ./arquivos/generic_file.txt
clean_apps:
	rm -rf $(BIN)/*


