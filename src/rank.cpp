#include "rank.h"

using namespace std;

double similaridade(string arquivo, multiset<string>& query, IndiceInvertido& indice, Norma& norma_arquivo){
    double produto_interno = 0, norma_pesquisa = 0, w_doc, w_q;
    int freq;
    
    set<string> new_set;
    for(auto palavra : query) new_set.insert(palavra);

    for(auto palavra : new_set){
        freq = query.count(palavra);

        Coordenadas cord(palavra, indice);
        w_doc = cord.valor(arquivo);
        w_q = cord.importancia()*freq;

        produto_interno += w_doc*w_q;
        norma_pesquisa += w_q*w_q;
    }
	norma_pesquisa = sqrt(norma_pesquisa);

    if(produto_interno==0) return 0;

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
    int num;
    string s, abrir, cmd = "gedit ";

    cout << 1 << "\t" << rank_[0].first << " ";

    for(int i=1; i<min((int) rank_.size(), k); i++){
        if(rank_[i].second != rank_[i-1].second)
            cout << endl << i+1 << "\t";
            
        cout  << rank_[i].first << " ";
    }
    cout << endl;
    cout << endl << "Gostaria de abrir algum arquivo? (s/n): ";
    cin >> abrir;

    if(abrir == "s"){
        cout << "Qual dos arquivos? (1 ... k): ";
        cin >> num;

        if(num > min((int) rank_.size(), k)) num = min((int) rank_.size(), k);
        cmd += rank_[num-1].first;
        system(cmd.c_str());
    }

    rank_.clear();
}   
