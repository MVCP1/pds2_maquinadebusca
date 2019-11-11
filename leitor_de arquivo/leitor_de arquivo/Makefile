CC=g++
CFLAGS=-lstdc++fs -std=c++17 -Wall
arquivos=main.o leitor.o main 

all: main

run: main
	clear
	./main

teste: leitor_teste
	./leitor_teste

leitor.o: leitor.h leitor.cpp
	${CC} ${CFLAGS} -c leitor.cpp -lstdc++fs

main.o: main.cpp leitor.h
	${CC} ${CFLAGS} -c main.cpp -lstdc++fs

main: main.o leitor.o
	${CC} ${CFLAGS} main.o leitor.o -o main -lstdc++fs

leitor_teste.o: leitor_teste.cpp doctest.h
	${CC} ${CFLAGS} -c leitor_teste.cpp -lstdc++fs

leitor_teste: leitor_teste.o leitor.o
	${CC} ${CFLAGS} leitor_teste.o leitor.o -o leitor_teste -lstdc++fs

clean:
	rm -f $arquivos *.o