#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "leitor.h"

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

    nomes = nomes_de_arquivos();

    set<string> nomes_reais = {"files/bilac",
                               "files/dias",
                               "files/drummond",
                               "files/flor",
                               "files/moraes",
                               "files/dificil"};     

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

TEST_CASE("Leitura de arquivo dificil") {
    
    multiset<string> teste = palavras_arquivo("files/dificil");
    multiset<string> real = {"batatinha",
    "quando","nasce","espalha","a","rama","pelo","chao","12345"};

    CHECK(real.size() == teste.size());
    CHECK(real == teste);
}