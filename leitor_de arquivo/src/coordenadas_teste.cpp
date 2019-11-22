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
#include "indice.h"

using namespace std;

class CoordenadasTeste{
    public:
        string palavra(Coordenadas c) {
            return c.palavra_;
        }

        multiset<string> docs(Coordenadas c) {
            return c.docs_;
        }

        double totalDocs(Coordenadas c) {
            return c.totalDocs_;
        }

        double docsSemRepetir(Coordenadas c) {
            return c.docsSemRepetir_;
        }
};

TEST_SUITE("COORDENADAS") {  
	TEST_CASE("USANDO AQUIVOS em coordenadas_teste") {
		
		CoordenadasTeste teste_c;
		
		IndiceInvertido indice();
		indice.InserePasta("coordenadas_teste");
		Coordenadas batata("batata", indice);
		Coordenadas cenoura("cenoura", indice);
		Coordenadas laranja("laranja", indice);
		
		
		SUBCASE("palavra()"){
			CHECK("batata" == teste_c.palavra(batata);
			CHECK("cenoura" == teste_c.palavra(cenoura);
			CHECK("laranja" == teste_c.palavra(laranja);
		}
		
		SUBCASE("frequencia()"){
			CHECK(3 == teste_c.docs(batata).count("doc1"));
			CHECK(2 == teste_c.docs(batata).count("doc2"));
			CHECK(1 == teste_c.docs(batata).count("doc3"));
			CHECK(0 == teste_c.docs(batata).count("doc4"));

			CHECK(1 == teste_c.docs(cenoura).count("doc1"));
			CHECK(1 == teste_c.docs(cenoura).count("doc2"));
			CHECK(3 == teste_c.docs(cenoura).count("doc3"));
			CHECK(1 == teste_c.docs(cenoura).count("doc4"));

			CHECK(1 == teste_c.docs(laranja).count("doc1"));
			CHECK(0 == teste_c.docs(laranja).count("doc2"));
			CHECK(0 == teste_c.docs(laranja).count("doc3"));
			CHECK(3 == teste_c.docs(laranja).count("doc4"));
		}
		
		SUBCASE("importancia()"){
			
			CHECK(4.0 == teste_c.totalDocs(batata));
			CHECK(4.0 == teste_c.totalDocs(cenouta));
			CHECK(4.0 == teste_c.totalDocs(laranja));
			
			CHECK(3.0 == teste_c.docsSemRepetir(batata));
			CHECK(4.0 == teste_c.docsSemRepetir(cenouta));
			CHECK(2.0 == teste_c.docsSemRepetir(laranja));
			
			CHECK(log(4.0/3.0) == batata.importancia());
			CHECK(log(4.0/4.0) == cenoura.importancia());
			CHECK(log(4.0/2.0) == laranja.importancia());
		}
	}
}