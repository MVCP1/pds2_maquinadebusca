#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "leitor_pesquisa.h"

#include "doctest.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <set>

class LeitorPesquisaTeste {
    public:
    static string teste_formaliza_palavra(string s, LeitorPesquisa &c) {
        return c.formaliza_palavra(s);
    }

    static multiset<string> teste_frequencias(string pesquisa, IndiceInvertido &indice, LeitorPesquisa &c) {
        return c.frequencias(indice, pesquisa);
    }
};

TEST_CASE("LeitorPesquisa") {
    IndiceInvertido indice;
    indice.InserePasta("testes/leitor_teste");

    LeitorPesquisa leitor;
    LeitorPesquisaTeste leitor_teste;

    SUBCASE("frequencias()") {
        string entrada = "a a b b c a defg";

        multiset<string> real = {"a","a","a","b","b","c","defg"};

        multiset<string> retornado = leitor_teste.teste_frequencias(entrada, indice, leitor);

        CHECK(retornado == real);
    }

    SUBCASE("formaliza_palavra()"){
        CHECK("batata" == leitor_teste.teste_formaliza_palavra("BaTaTa",leitor));
        CHECK("submarinoamarelo" == leitor_teste.teste_formaliza_palavra(",.!submarino-amarelo?",leitor));
        CHECK("cuzcuz" == leitor_teste.teste_formaliza_palavra("cU;>/zc~uz",leitor));
    }
}