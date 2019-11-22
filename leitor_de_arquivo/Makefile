CC=g++
CFLAGS=-lstdc++fs -std=c++17 -Wall

all: bin/main

run: bin/main
	./bin/main

clean:
	rm -rf bin/*

teste: indice_teste coordenadas_teste leitor_teste

indice_teste: bin/indice_teste
	./bin/indice_teste
	
coordenadas_teste: bin/coordenadas_teste
	./bin/coordenadas_teste

leitor_teste: bin/leitor_teste
	./bin/leitor_teste

bin/indice.o: src/indice.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/indice_teste.o: src/indice_teste.cpp
	${CC} ${CFLAGS} -I include/ -c $^ -lstdc++fs -o $@

bin/indice_teste: bin/indice_teste.o bin/indice.o
	${CC} ${CFLAGS} -I include/ $^ -o $@ -lstdc++fs
	
bin/coordenadas.o: src/coordenadas.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/coordenadas_teste.o: src/coordenadas_teste.cpp bin/indice.o
	${CC} ${CFLAGS} -I include/ -c $^ -lstdc++fs -o $@

bin/coordenadas_teste: bin/coordenadas_teste.o bin/coordenadas.o bin/indice.o
	${CC} ${CFLAGS} -I include/ $^ -o $@ -lstdc++fs

bin/leitor.o: src/leitor.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/leitor_teste.o: src/leitor_teste.cpp
	${CC} ${CFLAGS} -I include/ -c $^ -lstdc++fs -o $@

bin/leitor_teste: bin/leitor_teste.o bin/leitor.o
	${CC} ${CFLAGS} -I include/ $^ -o $@ -lstdc++fs
	
bin/main.o: src/main.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@
	
bin/main: bin/main.o bin/indice.o bin/coordenadas.o bin/leitor.o
	${CC} ${CFLAGS} $^ -o $@ -lstdc++fs
