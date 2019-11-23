#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "normas.h"
#include "doctest.h"

using namespace std;

class NormaTeste{
    public:
        static map<string, double> teste_normas(Norma &n){
            return n.norma_;
        }
};

TEST_CASE("Norma") {

    IndiceInvertido indice;

    indice.InserePasta("testes/rank_teste");
    Norma normas(indice);
    NormaTeste teste;
    map<string, double> m = teste.teste_normas(normas);

    SUBCASE("normas"){
        CHECK(1.0 < normas["testes/rank_teste/D1"]);
        CHECK(1.0 < normas["testes/rank_teste/D2"]);
        CHECK(0.6 > normas["testes/rank_teste/D3"]);
        CHECK(0.5 < normas["testes/rank_teste/D3"]);
        CHECK(1.45 > normas["testes/rank_teste/D4"]);
        CHECK(1.30 < normas["testes/rank_teste/D4"]);
    }
}

