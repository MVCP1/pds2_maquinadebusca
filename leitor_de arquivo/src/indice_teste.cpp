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
            teste_indice_ptr = indice_ptr;
        }

        void TesteInserePasta(string pasta) {
            return teste_indice_ptr->InserePasta(pasta);
        }

        void TesteInsereArquivo(string nome_arquivo) {
            return teste_indice_ptr->InsereArquivo(nome_arquivo);
        }

        string teste_formaliza_palavra(string palavra) {
            return teste_indice_ptr->formaliza_palavra(palavra);
        }

        vector<string> teste_nomes_arquivos(string path) {
            return teste_indice_ptr->nomes_arquivos(path);
        }

        map<string,multiset<string> > testa_indice() {
            return teste_indice_ptr->indice_;
        }

        int teste_num_arquivos() {
            return teste_indice_ptr->numDocs_;
        }

    private:
        IndiceInvertido *teste_indice_ptr;
};

TEST_CASE("Leitor índice Invertido") {
    IndiceInvertido indice;
    IndiceTeste indice_teste(&indice);

    indice_teste.TesteInserePasta("arquivos_teste");

    SUBCASE("Nomes arquivos") {
        vector<string> nomes;
        nomes = indice_teste.teste_nomes_arquivos("arquivos_teste");

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

    SUBCASE("Letras maiúsculas") {
        CHECK("batata" == indice_teste.teste_formaliza_palavra("BaTaTa"));
    }

    SUBCASE("Pontuacao") {
        CHECK("submarinoamarelo" == indice_teste.teste_formaliza_palavra(",.!submarino-amarelo?"));
    }
}

TEST_CASE("Índice invertido") {
    SUBCASE("Tamanho") {
        IndiceInvertido indice_;
        indice_.InserePasta("arquivos_teste");

        CHECK(indice_.numArquivos() == 6);
    }
    
    SUBCASE("Dicionário") {
        IndiceInvertido indice;
        IndiceTeste indice_teste(&indice); 
        
        indice_teste.TesteInserePasta("arquivos_teste");

        REQUIRE(indice_teste.teste_num_arquivos() == 6);

        map<string,multiset<string> > teste = indice_teste.testa_indice();

        multiset<string> real = {"arquivos_teste/dificil","arquivos_teste/dificil",
                                "arquivos_teste/dificil","arquivos_teste/dificil"};

        CHECK(teste["nasce"] == real);
    }

    SUBCASE("Acesso") {
        IndiceInvertido indice;
        indice.InserePasta("arquivos_teste");

        multiset<string> real = {"arquivos_teste/dificil","arquivos_teste/dificil",
                                "arquivos_teste/dificil","arquivos_teste/dificil"};

        CHECK(indice["nasce"] == real);
    }
}