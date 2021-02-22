
BIN=bin
SRC=src
INC=include
OBJ=obj
OPT=-Wall-I$(INC)
$(BIN)/main:$(OBJ)/main.o $(OBJ)/main.o
g++$(OPT)$(OBJ)/bloqueLed.o $(OBJ)/main.o-o $(BIN)/main
$(OBJ)/bloqueLed.o:$(SRC)/bloqueLed.cpp $(INC)/bloqueLed.h
g++$(OPT)-c $(SRC)/bloqueLed.cpp-o $(OBJ)/bloqueLed.o
$(OBJ)/main.o:$(SRC)/main.cpp $(INC)/bloqueLed.h
g++$(OPT)-c $(SRC)/main.cpp-o $(OBJ)/main.o
clean:echo"Limpiando....."
rm $(OBJ