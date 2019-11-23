// Calcula a norma do vetor dos documentos

#ifndef NORMAS_H
#define NORMAS_H

#include "coordenadas.h"
#include "indice.h"
#include <map>
#include <string>

using namespace std;

class Norma{
    public:
        Norma(IndiceInvertido &indice);

		double operator[](string arquivo);

    private:

        map<string, double>  norma_;

        friend class NormaTeste;
};

#endif //NORMAS_H
