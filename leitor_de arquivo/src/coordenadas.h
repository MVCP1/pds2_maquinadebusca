
#include "indice.h"

#include <math.h>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Coordenadas{
    public:
        // Cria Coordenadas a partir de um índice invertido inserido
        // PRÉ CONDIÇÃO: A PALAVRA DEVE EXISTIR NO ÍNDICE
        Coordenadas(string palavra, IndiceInvertido &indice);

        // Retorna a palavra que corresponde a essas coordenadas
        string  palavra();

        // Retorna a frequência da palavra num doc
        double frequencia(string doc);

        // Retorna a importância da palavra na coleção
        double importancia();

    private:
        string palavra_; // Palavra a que as coordenadas se referem

        multiset<string> docs_; // Documentos em que a palavra está presente (com repetição)

        double totalDocs_; // Total de documentos existentes

        double docsSemRepetir_; // Quantidade de ocumentos diferentes em que a palavra está presente
		
		friend class CoordenadasTeste;
};
