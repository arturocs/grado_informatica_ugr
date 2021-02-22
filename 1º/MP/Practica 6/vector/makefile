
SRC=src
INC=include
OBJ=obj
BIN=bin
LIB=lib
CXX=g++
CPPFLAGS=-Wall-g--std=c++11-c-I$(INC)
all:$(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen $(BIN)/arteASCII2
$(BIN)/testimagen:$(OBJ)/testimagen $(LIB)/libimagen
g++ -o $(BIN)/testimagen $(OBJ)/testimagen.o-L$(LIB)/ -limagen
$(BIN)/testplano:$(OBJ)/testplano $(LIB)/libimagen
g++ -o $(BIN)/testplano $(OBJ)/testplano.o-L$(LIB)/ -limagen
$(BIN)/testarteASCII:$(OBJ)/testarteASCII $(LIB)/libimagen
g++ -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o-L$(LIB)/ -limagen
$(BIN)/arteASCII2:$(OBJ)/arteASCII2 $(LIB)/libimagen
g++ -o $(BIN)/arteASCII2 $(OBJ)/arteASCII2.o-L$(LIB)/ -limagen
$(OBJ)/imagen:$(OBJ)/byte $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/byte.h $(INC)/lista.h
g++$(CPPFLAGS)$(SRC)/imagen.cpp-o $(OBJ)/imagen.o
$(OBJ)/testimagen:$(SRC)/testimagen.cpp
g++$(CPPFLAGS)$(SRC)/testimagen.cpp-o $(OBJ)/testimagen.o
$(OBJ)/pgm:$(INC)/pgm.h $(SRC)/pgm.cpp
g++$(CPPFLAGS)$(SRC)/pgm.cpp-o $(OBJ)/pgm.o
$(OBJ)/testplano:$(SRC)/testplano.cpp
g++$(CPPFLAGS)$(SRC)/testplano.cpp-o $(OBJ)/testplano.o
$(OBJ)/byte:$(SRC)/byte.cpp $(INC)/byte.h
g++$(CPPFLAGS)$(SRC)/byte.cpp-o $(OBJ)/byte.o
$(OBJ)/testarteASCII:$(SRC)/testarteASCII.cpp
g++$(CPPFLAGS)$(SRC)/testarteASCII.cpp-o $(OBJ)/testarteASCII.o
$(OBJ)/arteASCII2:$(SRC)/arteASCII2.cpp $(SRC)/imagen.cpp $(SRC)/lista.cpp
g++$(CPPFLAGS)$(SRC)/arteASCII2.cpp-o $(OBJ)/arteASCII2.o
$(OBJ)/lista:$(SRC)/lista.cpp $(INC)/lista.h
g++$(CPPFLAGS)$(SRC)/lista.cpp-o $(OBJ)/lista.o
$(LIB)/libimagen:$(OBJ)/imagen $(OBJ)/pgm $(OBJ)/byte $(OBJ)/lista
ar rsv $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o#************documentación*******documentacion:doxygen doc/doxys/Doxyfile#************Limpieza************clean:echo"Limpiando..."
rm $(OBJ