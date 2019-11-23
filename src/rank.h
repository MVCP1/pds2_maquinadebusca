// Recebe a pesquisa tratada e retorna os documentos
// em ordem de importância

#ifndef RANK_H
#define RANK_H

#include "coordenadas.h"
#include "normas.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Calcula a similaridade de um arquivo com uma query
double similaridade(string arquivo, multiset<string>& query, IndiceInvertido& indice, Norma&normas);


// Ordena o rank pelas similaridades
bool ord(pair<string, double > a, pair<string, double > );

class Rank {
    public:
        // Cria Rank a partir da query
        Rank(multiset <string> &query, IndiceInvertido& indice, Norma& normas);

        // Imprime os primeiros k arquivos
        void imprimir(int k);

    private:
        // Rank dos arquivos em ordem decrescente de similaridade
        vector <pair <string, double> > rank_;

        friend class RankTeste;
};

#endif //RANKING_H
