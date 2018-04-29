CXX = g++
AR = ar
CXXFLAGS = -Wall -g
INC = include/
BIN = bin/
OBJ = obj/
SRC = src/

all : $(BIN)BuscaMinas

clean:
	echo “Limpiando…”
	-rm $(OBJ)*.o
	-rm */*~
	-rm *~

mrproper: clean
	-rm $(BIN)BuscaMinas

$(BIN)BuscaMinas: $(OBJ)BuscaMinas.o $(OBJ)CampoMinas.o $(OBJ)Tablero.o
	$(CXX) -o $(BIN)BuscaMinas $(OBJ)BuscaMinas.o $(OBJ)CampoMinas.o $(OBJ)Tablero.o

$(OBJ)BuscaMinas.o: $(INC)Tablero.h $(INC)CampoMinas.h $(SRC)BuscaMinas.cpp
	$(CXX) -c -o $(OBJ)BuscaMinas.o -I ./$(INC) $(SRC)BuscaMinas.cpp

$(OBJ)Tablero.o: $(INC)Tablero.h $(SRC)Tablero.cpp
		$(CXX) -c $(CXXFLAGS) -o $(OBJ)Tablero.o -I ./$(INC) $(SRC)Tablero.cpp

$(OBJ)CampoMinas.o: $(INC)Tablero.h $(INC)CampoMinas.h $(SRC)CampoMinas.cpp
	$(CXX) -c -o $(OBJ)CampoMinas.o -I ./$(INC) $(SRC)CampoMinas.cpp
