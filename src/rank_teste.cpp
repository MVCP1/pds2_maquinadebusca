#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "rank.h"
#include "doctest.h"

using namespace std;


class RankTeste{
public:
    vector <pair <string, double> > rank(Rank& r){
        return r.rank_;
    }
};

TEST_CASE("Rank") {

    RankTeste rank_teste;
    IndiceInvertido indice;

    indice.InserePasta("testes/rank_teste");
    Norma normas(indice);
    multiset<string> query;

    query.insert("a");
    query.insert("a");
    query.insert("a");

    SUBCASE("similaridade(rank_test)"){

        CHECK(0.7 < similaridade("testes/rank_teste/D1", query, indice, normas));
        CHECK(0.35 < similaridade("testes/rank_teste/D2", query, indice, normas));
        CHECK(0.45 > similaridade("testes/rank_teste/D2", query, indice, normas));
        CHECK(1.0 == similaridade("testes/rank_teste/D3", query, indice, normas));
        CHECK(0.0 == similaridade("testes/rank_teste/D4", query, indice, normas));
    }

    SUBCASE("rank()"){
        Rank r(query, indice, normas);
        vector <pair <string, double> > rank = rank_teste.rank(r);

        CHECK("testes/rank_teste/D3" == rank[0].first);
        CHECK("testes/rank_teste/D1" == rank[1].first);
        CHECK("testes/rank_teste/D2" == rank[2].first);
        CHECK("testes/rank_teste/D4" == rank[3].first);
    }

    query.insert("b");

    SUBCASE("similaridade(rank_test)"){
        CHECK(0.0 < similaridade("testes/rank_teste/D4", query, indice, normas));
        CHECK(1.0 > similaridade("testes/rank_teste/D3", query, indice, normas));
    }    

    SUBCASE("ord(pair<string, double>)"){
        vector<pair<string, double> > v_ord;
        v_ord.push_back(make_pair("a", 2.0));
        v_ord.push_back(make_pair("b", 1.0));
        v_ord.push_back(make_pair("c", 3.0));

        sort(v_ord.begin(), v_ord.end(), ord);

        CHECK("c" == v_ord[0].first);
        CHECK("a" == v_ord[1].first);
        CHECK("b" == v_ord[2].first);

    }

}

