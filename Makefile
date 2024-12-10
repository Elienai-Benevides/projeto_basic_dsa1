APPS = ./apps
SRC = ./source
BIN = ./bin
OBJ = ./obj
LIB = ./lib
INCLUDE = ./include
FLAGS = -O3 -Wall 
LIBS = -lm -led -L $(LIB)

all: libed myapps
	
libed: \
	$(OBJ)/linked_list.o \
        $(OBJ)/sort_n_search.o\
	$(OBJ)/ListRecorder.o \
	$(OBJ)/sequencial.o \
	$(OBJ)/File_Template.o \
	$(OBJ)/menu.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o

myapps: \
	libed \
	$(BIN)/main01

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h		
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@	


$(BIN)/%: $(APPS)/%.c $(LIB)/libed.a 
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@ 

run: 

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*
clean_apps:
	rm -rf $(BIN)/*


