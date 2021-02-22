
all:bin/cm
bin/cm:obj/main.o lib/libcosa.a
g++ -o bin/cm obj/main.o-lcosa-Llib
obj/main.o:src/main.cpp include/punto.h include/circulo.h
g++ -c src/main.cpp-o obj/main.o-Iinclude
obj/punto.o:src/punto.cpp include/punto.h
g++ -c src/punto.cpp-o obj/punto.o-Iinclude
obj/circulo.o:src/circulo.cpp include/punto.h include/circulo.h
g++ -c src/circulo.cpp-o obj/circulo.o-Iinclude
lib/libcosa.a:obj/circulo.o obj/punto.o
ar-rvs lib/libcosa.a obj/punto.o obj/circulo.o
clean:rm bi