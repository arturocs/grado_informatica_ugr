src = ./src
inc =./include
bin = ./bin
datos = ./datos
obj = ./obj
CPPFLAGS = -Wall -O2 -g -I$(inc) -c -std=c++11

all: $(bin)/UsoBolsaLetras $(bin)/Juego $(bin)/TestDiccionario

$(bin)/UsoBolsaLetras : $(obj)/UsoBolsaLetras.o $(obj)/BolsaLetras.o
	g++  $(obj)/UsoBolsaLetras.o $(obj)/BolsaLetras.o -o $(bin)/UsoBolsaLetras

$(obj)/UsoBolsaLetras.o: $(src)/BolsaLetras.cpp
	g++ $(CPPFLAGS) $(src)/UsoBolsaLetras.cpp -o $(obj)/UsoBolsaLetras.o

$(obj)/BolsaLetras.o: $(inc)/BolsaLetras.h $(src)/BolsaLetras.cpp
	g++ $(CPPFLAGS) $(src)/BolsaLetras.cpp -o $(obj)/BolsaLetras.o

$(bin)/Juego : $(obj)/Juego.o $(obj)/Letras.o
	g++  $(obj)/Juego.o $(obj)/Letras.o -o $(bin)/Juego

$(obj)/Juego.o: $(src)/Juego.cpp
	g++ $(CPPFLAGS) $(src)/Juego.cpp -o $(obj)/Juego.o

$(obj)/Letras.o: $(inc)/Letras.h $(inc)/Diccionario.h $(src)/Letras.cpp
	g++ $(CPPFLAGS) $(src)/Letras.cpp -o $(obj)/Letras.o

$(bin)/TestDiccionario : $(obj)/TestDiccionario.o
	g++  $(obj)/TestDiccionario.o -o $(bin)/TestDiccionario

$(obj)/TestDiccionario.o: $(inc)/Diccionario.h $(src)/TestDiccionario.cpp
	g++ $(CPPFLAGS) $(src)/TestDiccionario.cpp -o $(obj)/TestDiccionario.o

 #************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

clean :
	echo "Limpiando..."
	rm -f $(obj)/*
	rm -f $(bin)/*

mrproper : clean
	-rm -rf doc/html/*
	-rm -rf doc/html
