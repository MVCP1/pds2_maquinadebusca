CC=g++
CFLAGS=-lstdc++fs -std=c++17 -Wall

all: main

leitor.o: leitor.h leitor.cpp
	${CC} ${CFLAGS} -c leitor.cpp -lstdc++fs

main.o: main.cpp leitor.h
	${CC} ${CFLAGS} -c main.cpp -lstdc++fs

main: main.o leitor.o
	${CC} ${CFLAGS} main.o leitor.o -o main -lstdc++fs

# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it