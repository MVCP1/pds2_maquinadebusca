#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "leitor_pesquisa.h"

#include "doctest.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <set>
/*
using namespace std;

class LeitorTeste {
    public:
        IndiceTeste(IndiceInvertido *indice_ptr) {
            teste_indice_ptr_ = indice_ptr;
        }

        void teste_insere_arquivo(string nome_arquivo) {
            teste_indice_ptr_->InsereArquivo(nome_arquivo);
        }

        string teste_formaliza_palavra(string palavra) {
            return teste_indice_ptr_->formaliza_palavra(palavra);
        }

        vector<string> teste_nomes_arquivos(string path) {
            return teste_indice_ptr_->nomes_arquivos(path);
        }

        map<string,multiset<string> > teste_indice() {
            return teste_indice_ptr_->indice_;
        }

    private:
        IndiceInvertido *teste_indice_ptr_;
};

TEST_CASE("Leitor Índice Invertido") {
    LeitorTeste l_teste;
    IndiceTeste indice_teste(&indice);

    SUBCASE("nomes_arquivos()") {
        indice.InserePasta("arquivos_teste");
        vector<string> nomes = indice_teste.teste_nomes_arquivos("arquivos_teste");

        set<string> nomes_reais = {"arquivos_teste/bilac",
                                    "arquivos_teste/dias",
                                    "arquivos_teste/drummond",
                                    "arquivos_teste/flor",
                                    "arquivos_teste/moraes",
                                    "arquivos_teste/dificil"};

        REQUIRE(nomes.size() == nomes_reais.size());

        for(auto s : nomes) {
            CHECK(nomes_reais.count(s));
        }
    }

    SUBCASE("InsereArquivo(string)") {
        indice_teste.teste_insere_arquivo("arquivos_teste/dificil");
        map<string,multiset<string> > map_teste = indice_teste.teste_indice();

        multiset<string> real = {"arquivos_teste/dificil","arquivos_teste/dificil",
                                "arquivos_teste/dificil","arquivos_teste/dificil"};

        CHECK(map_teste["nasce"] == real);

        real = {"arquivos_teste/dificil"};

        CHECK(map_teste["quando"] == real);
    }

    SUBCASE("InserePasta(string)") {
        indice.InserePasta("arquivos_teste");

        REQUIRE(indice.num_arquivos() == 6);

        map<string,multiset<string> > map_teste = indice_teste.teste_indice();

        multiset<string> real = {"arquivos_teste/dificil","arquivos_teste/dificil",
                                "arquivos_teste/dificil","arquivos_teste/dificil"};

        CHECK(map_teste["nasce"] == real);

        real = {"arquivos_teste/moraes","arquivos_teste/moraes"};

        CHECK(map_teste["amor"] == real); 
    }
    
    SUBCASE("num_arquivos()") {
        indice.InserePasta("arquivos_teste");

        CHECK(indice.num_arquivos() == 6);
    }

    SUBCASE("formaliza_palavra()"){
        CHECK("batata" == indice_teste.teste_formaliza_palavra("BaTaTa"));
        CHECK("submarinoamarelo" == indice_teste.teste_formaliza_palavra(",.!submarino-amarelo?"));
        CHECK("cuzcuz" == indice_teste.teste_formaliza_palavra("cU;>/zc~uz"));
    }

    SUBCASE("operator[]") {
        indice.InserePasta("arquivos_teste");

        multiset<string> real = {"arquivos_teste/dificil","arquivos_teste/dificil",
                                "arquivos_teste/dificil","arquivos_teste/dificil"};

        CHECK(indice["nasce"] == real);
    }
}
*/