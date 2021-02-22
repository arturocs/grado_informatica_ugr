CXX=g++
CFLAGS= -std=c++11

all: traspuesta inversiones calcular_k

traspuesta: traspuesta.cpp
	$(CXX) $(CFLAGS) -O3 -o traspuesta traspuesta.cpp
inversiones: inversiones.cpp
	$(CXX) $(CFLAGS) -o inversiones inversiones.cpp
calcular_k: calcular_k.cpp
	$(CXX) $(CFLAGS) -o calcular_k calcular_k.cpp

.PHONY: clean
clean: 
	rm traspuesta inversiones calcular_k
