
CC = mpicxx 
NAME1D = floyd
NAME1D = floyd1d
NAME2D = floyd2d
CFLAGS = -O3

MODULES1D = floyd1d.o Graph.o
MODULES2D = floyd2d.o Graph.o
MODULES = floyd.o Graph.o

all : floyd1d floyd2d floyd
Graph.o		:       Graph.cc Graph.h
	$(CC) $(CFLAGS) -c Graph.cc
floyd1d.o   :	floyd1d.cc
	$(CC) $(CFLAGS) -c floyd1d.cc
floyd1d :		$(MODULES1D)
	$(CC) $(CFLAGS) $(MODULES1D) -o $(NAME1D) $(EXTRALIBS)
floyd2d.o   :	floyd2d.cc
	$(CC) $(CFLAGS) -c floyd2d.cc
floyd2d :		$(MODULES2D)
	$(CC) $(CFLAGS) $(MODULES2D) -o $(NAME2D) $(EXTRALIBS)
floyd.o   :	floyd2d.cc
	$(CC) $(CFLAGS) -c floyd.cc
floyd :		$(MODULES2D)
	$(CC) $(CFLAGS) $(MODULES2D) -o $(NAME2D) $(EXTRALIBS)
	
clean	:
	rm -f $(MODULES1D) $(MODULES2D)  $(NAME1D) $(NAME2D) $(NAME)

