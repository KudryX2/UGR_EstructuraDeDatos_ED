SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/testdiccionario $(BIN)/letras $(BIN)/cantidad_letras

$(BIN)/testdiccionario : $(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o $(OBJ)/Bolsa.o 
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o $(OBJ)/Bolsa.o

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INC)

$(OBJ)/Letra.o : $(SRC)/Letra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Letra.o $(SRC)/Letra.cpp -I$(INC)

$(OBJ)/Bolsa.o : $(SRC)/Bolsa.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Bolsa.o $(SRC)/Bolsa.cpp -I$(INC)

$(OBJ)/testdiccionario.o : $(SRC)/testdiccionario.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp -I$(INC)


$(BIN)/letras : $(OBJ)/letras.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o $(OBJ)/Bolsa.o  $(OBJ)/Juego.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o $(OBJ)/Bolsa.o $(OBJ)/Juego.o

$(OBJ)/letras.o : $(SRC)/Letras.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/letras.o $(SRC)/Letras.cpp -I$(INC)


$(BIN)/cantidad_letras : $(OBJ)/CantidadLetras.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/CantidadLetras.o

$(OBJ)/CantidadLetras.o : $(SRC)/CantidadLetras.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/CantidadLetras.o $(SRC)/CantidadLetras.cpp -I$(INC)

$(OBJ)/Juego.o : $(SRC)/Juego.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Juego.o $(SRC)/Juego.cpp -I$(INC)


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario:
$(BIN)/Letras:
$(BIN)/cantidad_letras:


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
