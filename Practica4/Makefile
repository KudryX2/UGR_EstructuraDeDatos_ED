SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


$(BIN)/pruebadiccionario : $(OBJ)/pruebadiccionario.o $(OBJ)/Termino.o $(OBJ)/Diccionario.o
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o $(OBJ)/Termino.o $(OBJ)/Diccionario.o

$(OBJ)/Termino.o : $(SRC)/Termino.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Termino.o $(SRC)/Termino.cpp -I$(INC)

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INC)

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp -I$(INC)

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario:



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
