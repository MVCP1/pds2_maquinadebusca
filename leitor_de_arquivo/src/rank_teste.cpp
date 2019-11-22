//
// Created by emanuel on 22/11/19.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "rank.h"
#include "doctest.h"

using namespace std;


class RankTeste{
    public:
        vector <pair <string, int> > rank(Rank& r){
            return r.rank_;
        }
};


TEST_CASE("Rank") {

    RankTeste rank_teste;
    IndiceInvertido indice;

    indice.InserePasta("testes/coordenadas_teste");
    multiset<string> query;
    query.insert("batata");

    SUBCASE("similaridade(string, multiset<string>, IndiceInvertido)"){

        CHECK(0.0 != similaridade("testes/coordenadas_teste/doc1", query, indice));
        CHECK(0.0 != similaridade("testes/coordenadas_teste/doc2", query, indice));
        CHECK(0.0 != similaridade("testes/coordenadas_teste/doc3", query, indice));
        CHECK(0.0 != similaridade("testes/coordenadas_teste/doc4", query, indice));
    }
}
