src = ./src
inc =./include
bin = ./bin
datos = ./datos
obj = ./obj
CPPFLAGS = -Wall -g -Og -I$(inc) -c
CPP=g++

all: $(bin)/usodiccionario $(bin)/usoguia

$(bin)/usoguia : $(obj)/usoguia.o $(obj)/guiatlf.o
	$(CPP)  $(obj)/usoguia.o  $(obj)/guiatlf.o -o $(bin)/usoguia
$(obj)/usoguia.o: $(inc)/guiatlf.h $(src)/usoguia.cpp
	$(CPP) $(CPPFLAGS) $(src)/usoguia.cpp -o $(obj)/usoguia.o
$(obj)/guiatlf.o: $(inc)/guiatlf.h $(src)/guiatlf.cpp 
	$(CPP) $(CPPFLAGS) $(src)/guiatlf.cpp -o $(obj)/guiatlf.o

$(bin)/usodiccionario: $(obj)/diccionario.o $(obj)/usodiccionario.o
	$(CPP)  $(obj)/diccionario.o $(obj)/usodiccionario.o -o $(bin)/usodiccionario

$(obj)/usodiccionario.o: $(inc)/diccionario.h $(src)/usodiccionario.cpp
	$(CPP) $(CPPFLAGS) $(src)/usodiccionario.cpp -o $(obj)/usodiccionario.o

$(obj)/diccionario.o: $(inc)/diccionario.h $(src)/diccionario.cpp 
	$(CPP) $(CPPFLAGS) $(src)/diccionario.cpp -c -o $(obj)/diccionario.o
