CC=g++
CFLAGS=-lstdc++fs -std=c++17 -Wall
arquivos=main.o indice.o main 

all: main

run: main
	clear
	./main

teste: indice_teste
	./indice_teste

indice.o: indice.h indice.cpp
	${CC} ${CFLAGS} -c indice.cpp -lstdc++fs

main.o: indice.h  main.cpp
	${CC} ${CFLAGS} -c main.cpp -lstdc++fs

main: main.o indice.o
	${CC} ${CFLAGS} main.o indice.o -o main -lstdc++fs

indice_teste.o: indice_teste.cpp doctest.h
	${CC} ${CFLAGS} -c indice_teste.cpp -lstdc++fs

indice_teste: indice_teste.o indice.o
	${CC} ${CFLAGS} indice_teste.o indice.o -o indice_teste -lstdc++fs

clean:
	rm -f $arquivos *.o