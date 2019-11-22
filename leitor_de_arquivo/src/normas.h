//
// Created by emanuel on 22/11/19.
//

#ifndef NORMAS_H
#define NORMAS_H

#include "coordenadas.h"
#include <map>

using namespace std;


// Calcula a similaridade de um arquivo com uma query
double norma(string arquivo, map <string, multiset<string>>& indice);


class Norma {
    public:
        Norma(IndiceInvertido &indice);

		double operator[](string arquivo);

    private:
    
        map <string, double>  norma_;

        friend class NormaTeste;
};

#endif //NORMAS_H
