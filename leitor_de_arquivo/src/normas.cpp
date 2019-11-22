//
// Created by emanuel on 22/11/19.
//

#include "normas.h"

using namespace std;

double norma(string arquivo){
	
}


class Norma {
	Norma::Norma(IndiceInvertido& indice){
		double val;
		for (auto palavra : indice.todas_palavras){
			Coordenada cord(palavra, indice);
			val = cord.valor();	
			
			for(auto documento : indice[palavra]){
				if(norma_.count(documento) > 0)
					norma_[documento] += cord.valor() * cord.valor();
				else
					norma_[documento] = cord.valor() * cord.valor();
			}
		}
	
		for(auto documento : norma_)
			norma_[documento] = sqrt(norma_[documento]);
	}

	double Norma::operator[](string documento){
		return norma_[documento];
	}

    private:
    
        map <string, double>  norma_;

        friend class NormaTeste;
};

#endif //NORMAS_H
