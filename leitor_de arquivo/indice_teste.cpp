#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "indice.h"

#include "doctest.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

TEST_CASE("Nomes de arquivos") {
    vector<string> nomes;

    nomes = nomes_de_arquivos("arquivos_teste");

    set<string> nomes_reais = {"arquivos_teste/bilac",
                               "arquivos_teste/dias",
                               "arquivos_teste/drummond",
                               "arquivos_teste/flor",
                               "arquivos_teste/moraes",
                               "arquivos_teste/dificil"};

    set<string> nomes_retornados;

    CHECK(nomes.size() == nomes_reais.size());

    for(auto s : nomes) {
        CHECK(nomes_reais.count(s));
    }
}

TEST_CASE("Letras maiusculas") {
    CHECK("batata" == formaliza_palavra("BaTaTa"));
}

TEST_CASE("Pontuacao") {
    CHECK("submarinoamarelo" == formaliza_palavra(",.!submarino-amarelo?"));
}

TEST_CASE("Cria indice invertido") {

    map<string,multiset<string> > teste;

    insere_indice_invertido(teste, "arquivos_teste/dificil");


    CHECK(teste.size() == 9);

    multiset<string> real = {"arquivos_teste/dificil","arquivos_teste/dificil",
                             "arquivos_teste/dificil","arquivos_teste/dificil"};

    CHECK(teste["nasce"] == real);
}
