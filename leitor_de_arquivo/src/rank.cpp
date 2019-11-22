//
// Created by emanuel on 22/11/19.
//

#include "rank.h"

using namespace std;


double similaridade(string arquivo, multiset<string>& query, IndiceInvertido& indice, Norma& norma_arquivo){
    double produto_interno = 0, norma_pesquisa = 0, w_doc, w_q;
    int freq;

    for(auto palavra : query){
        freq = query.count(palavra);

        Coordenadas cord(palavra, indice);

        w_doc = cord.valor(arquivo);
        w_q = cord.importancia()*freq;

        produto_interno += w_doc*w_q;
        norma_pesquisa += w_q*w_q;
    }

	produto_interno = sqrt(produto_interno);
	norma_pesquisa = sqrt(norma_pesquisa);

    if(soma_num==0) return 0;

    return produto_interno / (norma_arquivo[arquivo]*norma_pesquisa);
}


bool ord(pair<string, double > a, pair<string, double > b){
    return a.second > b.second;
}


Rank::Rank(multiset <string> &query, IndiceInvertido& indice, Norma& normas) {
    for (auto arquivo : indice.nomes_arquivos())
        rank_.push_back(make_pair(arquivo, similaridade(arquivo, query, indice, normas)));

    sort(rank_.begin(), rank_.end(), ord);
}


void Rank::imprimir(int k) {
    for(int i=0; i<min((int) rank_.size(), k); i++)
        cout << rank_[i].first << endl;
}
