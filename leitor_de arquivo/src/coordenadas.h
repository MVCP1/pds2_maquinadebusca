
#include <math.h>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Coordenadas{
    public:
        // Cria Coordenadas a partir de um �ndice invertido inserido
        // PR� CONDI��O: A PALAVRA DEVE EXISTIR NO �NDICE
        Coordenadas(string palavra, map<string,multiset<string> > indice, vector<string> nomes_de_arquivos);

        // Retorna a palavra que corresponde a essas coordenadas
        string  palavra();

        // Retorna a frequ�ncia da palavra num doc
        double frequencia(string doc);

        // Retorna a import�ncia da palavra na cole��o
        double importancia();

    private:
        string palavra_; // Palavra a que as coordenadas se referem

        multiset<string> docs_; // Documentos em que a palavra est� presente (com repeti��o)

        double totalDocs_; // Total de documentos existentes

        double docsSemRepetir_; // Quantidade de ocumentos diferentes em que a palavra est� presente
};
