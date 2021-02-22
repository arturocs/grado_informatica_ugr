CXX=g++
CFLAGS= -std=c++11 -O3

all: subsecuencia subsecuencia

subsecuencia: subsecuencia.cpp
	$(CXX) $(CFLAGS) -o subsecuencia subsecuencia.cpp

generador: generador.cpp
	$(CXX) $(CFLAGS) -o generador generador.cpp	

.PHONY: clean
clean: 
	rm subsecuencia generador
