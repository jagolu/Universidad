AR= ar
CXX= g++
CXXFLAGS= -I./include -Wall -g
LDFLAGS= -L./lib
LDLIBS= -lformas

all: bin/central bin/area bin/longitud bin/delimitador
bin/delimitador: obj/delimitador.o lib/libformas.a
	$(CXX) $(CXXFLAGS) -o bin/delimitador obj/delimitador.o $(LDFLAGS) $(LDLIBS)
obj/delimitador.o: include/punto.h src/delimitador.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/delimitador.o src/delimitador.cpp
bin/central: obj/central.o lib/libformas.a
	$(CXX) $(CXXFLAGS) -o bin/central obj/central.o $(LDFLAGS) $(LDLIBS)
obj/central.o: include/punto.h include/circulo.h src/central.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/central.o src/central.cpp
bin/area: obj/area.o lib/libformas.a
	$(CXX) $(CXXFLAGS) -o bin/area obj/area.o $(LDFLAGS) $(LDLIBS)
obj/rectangulo.o: include/rectangulo.h src/rectangulo.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/rectangulo.o src/rectangulo.cpp
obj/punto.o: include/punto.h src/punto.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/punto.o src/punto.cpp
obj/circulo.o: include/circulo.h src/circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/circulo.o src/circulo.cpp
lib/libformas.a: obj/punto.o obj/circulo.o obj/rectangulo.o
	$(AR) -rvs lib/libformas.a obj/punto.o obj/circulo.o obj/rectangulo.o
obj/area.o: include/circulo.h src/area.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/area.o src/area.cpp
bin/longitud: obj/longitud.o lib/libformas.a
	$(CXX) $(CXXFLAGS) -o bin/longitud obj/longitud.o $(LDFLAGS) $(LDLIBS)
obj/longitud.o: include/punto.h src/longitud.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/longitud.o src/longitud.cpp 
mrproper: clean
	-rm bin/central bin/area bin/longitud bin/delimitador
clean:
	-rm obj/*.o lib/*.a
