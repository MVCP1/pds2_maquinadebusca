#include "normas.h"

using namespace std;

Norma::Norma(IndiceInvertido &indice){
	double val;

	for (auto palavra : indice.todas_palavras()){
		Coordenadas cord(palavra, indice);

		set <string> new_set;	
		for(auto documento : indice[palavra]) new_set.insert(documento);

		for(auto documento : new_set){
			val = cord.valor(documento);	

			if(norma_.count(documento) > 0)
				norma_[documento] += (val * val);
			else
				norma_[documento] = (val * val);
		}
	}
	for(auto it : norma_){
		norma_[it.first] = sqrt(norma_[it.first]);
	}
}

double Norma::operator[](string doc){
	return norma_[doc];
}

