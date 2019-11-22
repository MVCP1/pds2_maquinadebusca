//
// Created by emanuel on 22/11/19.
//

#include "normas.h"
using namespace std;

Norma::Norma(IndiceInvertido& indice){

	double val;
	for (auto palavra : indice.todas_palavras()){
		Coordenadas cord(palavra, indice);
		val = cord.valor(palavra);	
		
		for(auto documento : indice[palavra]){
			if(norma_.count(documento) > 0)
				norma_[documento] += val * val;
			else
				norma_[documento] = val * val;
		}
	}

	for(auto documento : norma_){
		norma_[documento.first] = sqrt(norma_[documento.first]);
	}
}

double Norma::operator[](string documento){
	return norma_[documento];
}

