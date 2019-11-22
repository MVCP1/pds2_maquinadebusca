//
// Created by emanuel on 22/11/19.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "normas.h"
#include "doctest.h"

using namespace std;


class RankTeste{
public:
    vector <pair <string, double> > rank(Rank& r){
        return r.rank_;
    }
};

TEST_CASE("Norma") {

    NormaTeste norma_teste;
    IndiceInvertido indice;

    indice.InserePasta("testes/rank_teste");
    Norma normas(indice);

    SUBCASE("operator[]"){

        CHECK(0.71 == normas["testes/rank_teste/D1"]);
        CHECK(0.71 == normas["testes/rank_teste/D2"]);
        CHECK(0.71 == normas["testes/rank_teste/D3"]);
    }
}

