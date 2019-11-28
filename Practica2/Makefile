INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c 

$(BIN)/main : $(OBJ)/main.o $(OBJ)/Termino.o $(OBJ)/Diccionario.o
	$(CXX) -o $(BIN)/main $(OBJ)/main.o $(OBJ)/Termino.o $(OBJ)/Diccionario.o

$(OBJ)/Termino.o : $(SRC)/Termino.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Termino.o $(SRC)/Termino.cpp -I$(INCLUDE)

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INCLUDE)

$(OBJ)/main.o : $(SRC)/main.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/main.o $(SRC)/main.cpp -I$(INCLUDE)

 #************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
