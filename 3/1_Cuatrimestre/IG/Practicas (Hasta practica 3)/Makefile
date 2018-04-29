# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica1

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuración
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I.
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut
FILE_PLY_STL=file_ply_stl.cc
OB3D=OB3D.cpp
O3D=O3D.cpp
CUBO=cubo.cpp
TETRAEDRO=tetraedro.cpp
CILINDRO=cilindro.cpp
VASO=vaso.cpp
VASOINVERTIDO=vasoInvertido.cpp
CONO=cono.cpp
TUBO=tubo.cpp
ESFERA=esfera.cpp
PALOPELOTA=paloPelota.cpp
DOSPELOTASUNIDAS=dosPelotasUnidas.cpp
BASE=base.cpp
MODELADORWATT=modeladorWatt.cpp
OBJETO_REVOLUCION=objeto_revolucion.cpp
OBJETO_PLY=objeto_ply.cpp
# definicion del compilador
#
CC = g++

# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : practica1.o
	$(CC) -o $@ $(CXXFLAGS) $(FILE_PLY_STL) $(OB3D) $(O3D) $(CUBO) $(TETRAEDRO) $(CILINDRO) $(VASO) $(VASOINVERTIDO) $(CONO) $(TUBO) $(ESFERA) $(PALOPELOTA) $(DOSPELOTASUNIDAS) $(BASE) $(MODELADORWATT) $(OBJETO_REVOLUCION) $(OBJETO_PLY) practica1.o $(LDFLAGS)

#
#
clean:
	rm -f *.o
	rm -f $(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *

