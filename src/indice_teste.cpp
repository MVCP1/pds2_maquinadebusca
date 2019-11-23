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

class IndiceTeste {
    public:
        IndiceTeste(IndiceInvertido *indice_ptr) {
            teste_indice_ptr_ = indice_ptr;
        }

        void teste_InsereArquivo(string nome_arquivo) {
            teste_indice_ptr_->InsereArquivo(nome_arquivo);
        }

        void teste_InsereNomesArquivos(string nome_arquivo) {
            teste_indice_ptr_->InsereNomesArquivos(nome_arquivo);
        }

        string teste_formaliza_palavra(string palavra) {
            return teste_indice_ptr_->formaliza_palavra(palavra);
        }

        map<string,multiset<string> > teste_indice_invertido() {
            return teste_indice_ptr_->indice_invertido_;
        }

        set<string> teste_todas_palavras() {
            return teste_indice_ptr_->todas_palavras_;
        }

    private:
        IndiceInvertido *teste_indice_ptr_;
};

TEST_CASE("Leitor Índice Invertido") {
    IndiceInvertido indice;
    IndiceTeste indice_teste(&indice);

    SUBCASE("InsereNomesArquivos()") {
        indice_teste.teste_InsereNomesArquivos("testes/arquivos_teste");
        vector<string> nomes = indice.nomes_arquivos();

        set<string> nomes_reais = {"testes/arquivos_teste/bilac",
                                    "testes/arquivos_teste/drummond",
                                    "testes/arquivos_teste/flor",
                                    "testes/arquivos_teste/dias",
                                    "testes/arquivos_teste/moraes",
                                    "testes/arquivos_teste/dificil"};

        REQUIRE(nomes.size() == nomes_reais.size());

        for(auto s : nomes) {
            CHECK(nomes_reais.count(s));
        }
    }

    SUBCASE("todas_palavras_") {
        indice_teste.teste_InsereArquivo("testes/leitor_teste/leitor");
        set<string> nomes_reais = {"a","b","c","defg"};
        set<string> nomes_retornados = indice_teste.teste_todas_palavras();

        REQUIRE(nomes_retornados.size() == nomes_reais.size());
        CHECK(nomes_retornados == nomes_reais);
    }

    SUBCASE("nomes_arquivos()") {
        indice_teste.teste_InsereNomesArquivos("testes/arquivos_teste");

        vector<string> nomes = indice.nomes_arquivos();

        set<string> nomes_reais = {"testes/arquivos_teste/bilac",
                                    "testes/arquivos_teste/drummond",
                                    "testes/arquivos_teste/flor",
                                    "testes/arquivos_teste/dias",
                                    "testes/arquivos_teste/moraes",
                                    "testes/arquivos_teste/dificil"};

        REQUIRE(nomes.size() == nomes_reais.size());

        for(auto s : nomes) {
            CHECK(nomes_reais.count(s));
        }
    }

    SUBCASE("InsereArquivo(string)") {
        indice_teste.teste_InsereArquivo("testes/arquivos_teste/dificil");
        map<string,multiset<string> > map_teste = indice_teste.teste_indice_invertido();

        multiset<string> real = {"testes/arquivos_teste/dificil","testes/arquivos_teste/dificil",
                                "testes/arquivos_teste/dificil","testes/arquivos_teste/dificil"};

        CHECK(map_teste["nasce"] == real);

        real = {"testes/arquivos_teste/dificil"};

        CHECK(map_teste["quando"] == real);
    }

    SUBCASE("InserePasta(string)") {
        indice.InserePasta("testes/arquivos_teste");

        REQUIRE(indice.num_arquivos() == 6);

        map<string,multiset<string> > map_teste = indice_teste.teste_indice_invertido();

        multiset<string> real = {"testes/arquivos_teste/dificil","testes/arquivos_teste/dificil",
                                "testes/arquivos_teste/dificil","testes/arquivos_teste/dificil"};

        CHECK(map_teste["nasce"] == real);

        real = {"testes/arquivos_teste/moraes","testes/arquivos_teste/moraes"};

        CHECK(map_teste["amor"] == real); 
    }
    
    SUBCASE("num_arquivos()") {
        indice.InserePasta("testes/arquivos_teste");

        CHECK(indice.num_arquivos() == 6);
    }

    SUBCASE("formaliza_palavra()"){
        CHECK("batata" == indice_teste.teste_formaliza_palavra("BaTaTa"));
        CHECK("submarinoamarelo" == indice_teste.teste_formaliza_palavra(",.!submarino-amarelo?"));
        CHECK("cuzcuz" == indice_teste.teste_formaliza_palavra("cU;>/zc~uz"));
    }

    SUBCASE("operator[]") {
        indice.InserePasta("testes/arquivos_teste");

        multiset<string> real = {"testes/arquivos_teste/dificil","testes/arquivos_teste/dificil",
                                "testes/arquivos_teste/dificil","testes/arquivos_teste/dificil"};
        CHECK(indice["nasce"] == real);
    }
}