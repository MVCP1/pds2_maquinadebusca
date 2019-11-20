#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "coordenadas.h"

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

#include "doctest.h"

using namespace std;

string palavra;
map<string,multiset<string> > indice;
vector<string> nomes_de_arquivos;


TEST_CASE("palavra") {
    vector<string> nomes_de_arquivos = {"doc1","doc2","doc3","doc4"};

    map<string,multiset<string> > indice;
    multiset<string> batata_correta = {"doc1",
                            "doc1",
                            "doc1",
                            "doc2",
                            "doc2",
                            "doc3"};
    indice["batata"] = batata_correta;
    multiset<string> cenoura_correta = {"doc1",
                            "doc2",
                            "doc3",
                            "doc3",
                            "doc3",
                            "doc4"};
    indice["cenoura"] = cenoura_correta;
    multiset<string> laranja_correta = {"doc1",
                            "doc4",
                            "doc4",
                            "doc4"};
    indice["laranja"] = laranja_correta;


    Coordenadas batata("batata", indice, nomes_de_arquivos);
    Coordenadas cenoura("cenoura", indice, nomes_de_arquivos);
    Coordenadas laranja("laranja", indice, nomes_de_arquivos);

    CHECK("batata" == batata.palavra());
    CHECK("cenoura" == cenoura.palavra());
    CHECK("laranja" == laranja.palavra());
}

TEST_CASE("Frequencia") {
    vector<string> nomes_de_arquivos = {"doc1","doc2","doc3","doc4"};

    map<string,multiset<string> > indice;
    multiset<string> batata_correta = {"doc1",
                            "doc1",
                            "doc1",
                            "doc2",
                            "doc2",
                            "doc3"};
    indice["batata"] = batata_correta;
    multiset<string> cenoura_correta = {"doc1",
                            "doc2",
                            "doc3",
                            "doc3",
                            "doc3",
                            "doc4"};
    indice["cenoura"] = cenoura_correta;
    multiset<string> laranja_correta = {"doc1",
                            "doc4",
                            "doc4",
                            "doc4"};
    indice["laranja"] = laranja_correta;


    Coordenadas batata("batata", indice, nomes_de_arquivos);
    Coordenadas cenoura("cenoura", indice, nomes_de_arquivos);
    Coordenadas laranja("laranja", indice, nomes_de_arquivos);

    CHECK(3 == batata.frequencia("doc1"));
    CHECK(2 == batata.frequencia("doc2"));
    CHECK(1 == batata.frequencia("doc3"));
    CHECK(0 == batata.frequencia("doc4"));

    CHECK(1 == cenoura.frequencia("doc1"));
    CHECK(1 == cenoura.frequencia("doc2"));
    CHECK(3 == cenoura.frequencia("doc3"));
    CHECK(1 == cenoura.frequencia("doc4"));

    CHECK(1 == laranja.frequencia("doc1"));
    CHECK(0 == laranja.frequencia("doc2"));
    CHECK(0 == laranja.frequencia("doc3"));
    CHECK(3 == laranja.frequencia("doc4"));
}

TEST_CASE("Importancia") {
    vector<string> nomes_de_arquivos = {"doc1","doc2","doc3","doc4"};

    map<string,multiset<string> > indice;
    multiset<string> batata_correta = {"doc1",
                            "doc1",
                            "doc1",
                            "doc2",
                            "doc2",
                            "doc3"};
    indice["batata"] = batata_correta;
    multiset<string> cenoura_correta = {"doc1",
                            "doc2",
                            "doc3",
                            "doc3",
                            "doc3",
                            "doc4"};
    indice["cenoura"] = cenoura_correta;
    multiset<string> laranja_correta = {"doc1",
                            "doc4",
                            "doc4",
                            "doc4"};
    indice["laranja"] = laranja_correta;


    Coordenadas batata("batata", indice, nomes_de_arquivos);
    Coordenadas cenoura("cenoura", indice, nomes_de_arquivos);
    Coordenadas laranja("laranja", indice, nomes_de_arquivos);

    CHECK(log(4.0/3.0) == batata.importancia());
    CHECK(log(4.0/4.0) == cenoura.importancia());
    CHECK(log(4.0/2.0) == laranja.importancia());
}
