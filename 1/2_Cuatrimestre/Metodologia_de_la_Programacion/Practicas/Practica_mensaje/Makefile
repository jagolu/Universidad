SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++03 -g  -I$(INC)
all: $(BIN)/ocultar $(BIN)/revelar 
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/codificar.o : $(SRC)/codificar.cpp $(INC)/codificar.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o

$(OBJ)/ocultar.o: $(INC)/imagenES.h $(INC)/codificar.h $(SRC)/ocultar.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/ocultar.o $(SRC)/ocultar.cpp

$(OBJ)/revelar.o: $(INC)/imagenES.h $(INC)/codificar.h $(SRC)/revelar.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/revelar.o $(SRC)/revelar.cpp

$(BIN)/ocultar: $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) $(CXXFLAGS) -o $(BIN)/ocultar $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o

$(BIN)/revelar: $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) $(CXXFLAGS) -o $(BIN)/revelar $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
