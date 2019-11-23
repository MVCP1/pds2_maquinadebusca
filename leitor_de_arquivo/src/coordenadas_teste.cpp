#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "indice.h"
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

class CoordenadasTeste{
    public:
        static string palavra(Coordenadas c) {
            return c.palavra_;
        }

        static multiset<string> docs(Coordenadas c) {
            return c.docs_;
        }

        static double totalDocs(Coordenadas c) {
            return c.totalDocs_;
        }

        static double docsSemRepetir(Coordenadas c) {
            return c.docsSemRepetir_;
        }
};

TEST_SUITE("COORDENADAS") {  
	TEST_CASE("USANDO AQUIVOS em testes/coordenadas_teste") {
		
		CoordenadasTeste teste_c;
		
		IndiceInvertido indice;

		indice.InserePasta("testes/coordenadas_teste");
		Coordenadas batata("batata", indice);
		Coordenadas cenoura("cenoura", indice);
		Coordenadas laranja("laranja", indice);
		
		
		SUBCASE("palavra()") {
			CHECK("batata" == teste_c.palavra(batata));
			CHECK("cenoura" == teste_c.palavra(cenoura));
			CHECK("laranja" == teste_c.palavra(laranja));
		}
		
		SUBCASE("frequencia(string)"){
			CHECK(3.0 == teste_c.docs(batata).count("testes/coordenadas_teste/doc1"));
			CHECK(2.0 == teste_c.docs(batata).count("testes/coordenadas_teste/doc2"));
			CHECK(1.0 == teste_c.docs(batata).count("testes/coordenadas_teste/doc3"));
			CHECK(0.0 == teste_c.docs(batata).count("testes/coordenadas_teste/doc4"));

			CHECK(1.0 == teste_c.docs(cenoura).count("testes/coordenadas_teste/doc1"));
			CHECK(1.0 == teste_c.docs(cenoura).count("testes/coordenadas_teste/doc2"));
			CHECK(3.0 == teste_c.docs(cenoura).count("testes/coordenadas_teste/doc3"));
			CHECK(1.0 == teste_c.docs(cenoura).count("testes/coordenadas_teste/doc4"));

			CHECK(1.0 == teste_c.docs(laranja).count("testes/coordenadas_teste/doc1"));
			CHECK(0.0 == teste_c.docs(laranja).count("testes/coordenadas_teste/doc2"));
			CHECK(0.0 == teste_c.docs(laranja).count("testes/coordenadas_teste/doc3"));
			CHECK(3.0 == teste_c.docs(laranja).count("testes/coordenadas_teste/doc4"));
		}
		
		SUBCASE("importancia()"){
			
			CHECK(4.0 == teste_c.totalDocs(batata));
			CHECK(4.0 == teste_c.totalDocs(cenoura));
			CHECK(4.0 == teste_c.totalDocs(laranja));
			
			CHECK(3.0 == teste_c.docsSemRepetir(batata));
			CHECK(4.0 == teste_c.docsSemRepetir(cenoura));
			CHECK(2.0 == teste_c.docsSemRepetir(laranja));
			
			CHECK(log(4.0/3.0) == batata.importancia());
			CHECK(log(4.0/4.0) == cenoura.importancia());
			CHECK(log(4.0/2.0) == laranja.importancia());
		}
		
		SUBCASE("valor(string)"){
			
			CHECK(log(4.0/3.0)*3.0 == batata.valor("testes/coordenadas_teste/doc1"));
			CHECK(log(4.0/3.0)*2.0 == batata.valor("testes/coordenadas_teste/doc2"));
			CHECK(log(4.0/3.0)*1.0 == batata.valor("testes/coordenadas_teste/doc3"));
			CHECK(log(4.0/3.0)*0.0 == batata.valor("testes/coordenadas_teste/doc4"));

			CHECK(log(4.0/4.0)*1.0 == cenoura.valor("testes/coordenadas_teste/doc1"));
			CHECK(log(4.0/4.0)*1.0 == cenoura.valor("testes/coordenadas_teste/doc2"));
			CHECK(log(4.0/4.0)*3.0 == cenoura.valor("testes/coordenadas_teste/doc3"));
			CHECK(log(4.0/4.0)*1.0 == cenoura.valor("testes/coordenadas_teste/doc4"));

			CHECK(log(4.0/2.0)*1.0 == laranja.valor("testes/coordenadas_teste/doc1"));
			CHECK(log(4.0/2.0)*0.0 == laranja.valor("testes/coordenadas_teste/doc2"));
			CHECK(log(4.0/2.0)*0.0 == laranja.valor("testes/coordenadas_teste/doc3"));
			CHECK(log(4.0/2.0)*3.0 == laranja.valor("testes/coordenadas_teste/doc4"));
			
		}
	}
}