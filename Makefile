CC=g++
CFLAGS=-lstdc++fs -std=c++17 -Wall

all: main

run: main
	./main

clean:
	rm -rf bin/*

teste: indice_teste coordenadas_teste leitor_pesquisa_teste normas_teste rank_teste 

indice_teste: bin/indice_teste
	./bin/indice_teste

coordenadas_teste: bin/coordenadas_teste
	./bin/coordenadas_teste

rank_teste: bin/rank_teste
	./bin/rank_teste

leitor_pesquisa_teste: bin/leitor_pesquisa_teste
	./bin/leitor_pesquisa_teste

normas_teste: bin/normas_teste
	./bin/normas_teste


bin/indice.o: src/indice.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/indice_teste.o: src/indice_teste.cpp
	${CC} ${CFLAGS} -I include/ -c $^ -lstdc++fs -o $@

bin/indice_teste: bin/indice_teste.o bin/indice.o
	${CC} ${CFLAGS} -I include/ $^ -o $@ -lstdc++fs


bin/coordenadas.o: src/coordenadas.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/coordenadas_teste.o: src/coordenadas_teste.cpp
	${CC} ${CFLAGS} -I include/ -c $^ -lstdc++fs -o $@

bin/coordenadas_teste: bin/coordenadas_teste.o bin/coordenadas.o bin/indice.o
	${CC} ${CFLAGS} -I include/ $^ -o $@ -lstdc++fs


bin/leitor_pesquisa.o: src/leitor_pesquisa.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/leitor_pesquisa_teste.o: src/leitor_pesquisa_teste.cpp
	${CC} ${CFLAGS} -I include/ -c $^ -lstdc++fs -o $@

bin/leitor_pesquisa_teste: bin/leitor_pesquisa_teste.o bin/leitor_pesquisa.o bin/indice.o
	${CC} ${CFLAGS} -I include/ $^ -o $@ -lstdc++fs


bin/normas.o: src/normas.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/normas_teste.o: src/normas_teste.cpp
	${CC} ${CFLAGS} -I include/ -c $^ -lstdc++fs -o $@

bin/normas_teste: bin/normas_teste.o bin/coordenadas.o bin/indice.o bin/normas.o
	${CC} ${CFLAGS} -I include/ $^ -o $@ -lstdc++fs


bin/rank.o: src/rank.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@

bin/rank_teste.o: src/rank_teste.cpp
	${CC} ${CFLAGS} -I include/ -c $^ -lstdc++fs -o $@

bin/rank_teste: bin/rank_teste.o bin/rank.o bin/coordenadas.o bin/indice.o bin/normas.o
	${CC} ${CFLAGS} -I include/ $^ -o $@ -lstdc++fs


bin/main.o: src/main.cpp
	${CC} ${CFLAGS} -c $^ -lstdc++fs -o $@
	
main: bin/main.o bin/indice.o bin/coordenadas.o bin/rank.o bin/leitor_pesquisa.o bin/normas.o
	${CC} ${CFLAGS} $^ -o $@ -lstdc++fs