
SRC=src
INC=include
OBJ=obj
BIN=bin
LIB=lib
CXX=g++
CPPFLAGS=-Wall-g-c-I$(INC)
all:$(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen $(BIN)/arteASCII
$(BIN)/testimagen:$(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/testimagen.o $(OBJ)/byte.o
$(CXX)-o $(BIN)/testimagen $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/testimagen.o $(OBJ)/byte.o
$(BIN)/testplano:$(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/testplano.o $(OBJ)/byte.o
$(CXX)-o $(BIN)/testplano $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/testplano.o $(OBJ)/byte.o
$(BIN)/testarteASCII:$(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/testarteASCII.o $(OBJ)/byte.o
$(CXX)-o $(BIN)/testarteASCII $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/testarteASCII.o $(OBJ)/byte.o
$(BIN)/arteASCII:$(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/arteASCII.o $(OBJ)/byte.o
$(CXX)-o $(BIN)/arteASCII $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/arteASCII.o $(OBJ)/byte.o
$(OBJ)/imagen.o:$(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/byte.h $(INC)/pgm.h
$(CXX)$(CPPFLAGS)-o $(OBJ)/imagen.o $(SRC)/imagen.cpp
$(OBJ)/pgm.o:$(SRC)/pgm.cpp $(INC)/pgm.h
$(CXX)$(CPPFLAGS)-o $(OBJ)/pgm.o $(SRC)/pgm.cpp
$(OBJ)/byte.o:$(SRC)/byte.cpp $(INC)/byte.h $(INC)/imagen.h $(INC)/pgm.h
$(CXX)$(CPPFLAGS)-o $(OBJ)/byte.o $(SRC)/byte.cpp
$(OBJ)/testimagen.o:$(SRC)/testimagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
$(CXX)$(CPPFLAGS)-o $(OBJ)/testimagen.o $(SRC)/testimagen.cpp
$(OBJ)/testplano.o:$(SRC)/testplano.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
$(CXX)$(CPPFLAGS)-o $(OBJ)/testplano.o $(SRC)/testplano.cpp
$(OBJ)/testarteASCII.o:$(SRC)/testarteASCII.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
$(CXX)$(CPPFLAGS)-o $(OBJ)/testarteASCII.o $(SRC)/testarteASCII.cpp
$(OBJ)/arteASCII.o:$(SRC)/arteASCII.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
$(CXX)$(CPPFLAGS)-o $(OBJ)/arteASCII.o $(SRC)/arteASCII.cpp
$(LIB)/libimagen.a:$(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/testimagen.o $(OBJ)/testarteASCII.o $(OBJ)/testplano.o
ar-rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/testimagen.o $(OBJ)/testarteASCII.o $(OBJ)/testplano.o#************documentación*******documentacion:doxygen doc/doxys/Doxyfile#************Limpieza************clean:echo"Limpiando"
rm $(OBJ