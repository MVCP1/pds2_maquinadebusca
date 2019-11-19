CC=g++
CFLAGS=-lstdc++fs -std=c++17 -Wall

all: bin/main

run: bin/main
	./bin/main
clean:
	rm -rf bin/*

teste: bin/indice_teste
	./bin/indice_teste

bin/indice.o: src/indice.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/main.o: src/main.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/indice_teste.o: src/indice_teste.cpp
	${CC} ${CFLAGS} -I include/ -c $^ -lstdc++fs -o $@

bin/indice_teste: bin/indice_teste.o bin/indice.o
	${CC} ${CFLAGS} -I include/ $^ -o $@ -lstdc++fs

bin/main: bin/main.o bin/indice.o
	${CC} ${CFLAGS} $^ -o $@ -lstdc++fs