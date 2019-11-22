//
// Created by emanuel on 22/11/19.
//

#include "rank.h"

using namespace std;


double similaridade(string arquivo, multiset<string>& query, IndiceInvertido& indice){
    double soma_num = 0, soma_indice = 0, soma_querry = 0, w_doc, w_q;
    int freq;

    for(auto palavra : query){
        freq = query.count(palavra);

        Coordenadas cord(palavra, indice);

        w_doc = cord.valor(arquivo);

        w_q = cord.importancia()*freq;

        soma_num += w_doc*w_q;
        soma_indice += w_doc*w_doc;
        soma_querry += w_q*w_q;
    }

    if(soma_num==0) return 0;

    return soma_num / (sqrt(soma_indice)*sqrt(soma_querry));
}


bool ord(pair<string, double > a, pair<string, double > b){
    return a.second > b.second;
}


Rank::Rank(multiset <string> &query, IndiceInvertido& indice) {
    for (auto arquivo : indice.nomes_arquivos())
        rank_.push_back(make_pair(arquivo, similaridade(arquivo, query, indice)));

    sort(rank_.begin(), rank_.end(), ord);
}


void Rank::imprimir(int k) {
    for(int i=0; i<min((int) rank_.size(), k); i++)
        cout << rank_[i].first << endl;
}
