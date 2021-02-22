CXX=g++
CFLAGS= -std=c++11 -O3

all: viajante_cercania viajante_sort viajante_triangulo distancia generamatrices gasolina

viajante_cercania: viajante_cercania.cpp
	$(CXX) $(CFLAGS) -o viajante_cercania viajante_cercania.cpp
viajante_sort: viajante_sort.cpp
	$(CXX) $(CFLAGS) -o viajante_sort viajante_sort.cpp
viajante_triangulo: viajante_triangulo.cpp
	$(CXX) $(CFLAGS) -o viajante_triangulo viajante_triangulo.cpp
distancia: distancia.cpp
	$(CXX) $(CFLAGS) -o distancia distancia.cpp
generamatrices: generamatrices.cpp
	$(CXX) $(CFLAGS) -o generamatrices generamatrices.cpp
gasolina: gasolina.cpp
	$(CXX) $(CFLAGS) -o gasolina gasolina.cpp

.PHONY: clean
clean: 
	rm viajante_cercania viajante_sort viajante_triangulo distancia generamatrices gasolina
