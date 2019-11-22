#include "leitor_pesquisa.h"

using namespace std;
namespace fs = filesystem;

LeitorPesquisa::LeitorPesquisa(string pesquisa, IndiceInvertido &indice) {
    pesquisa_ = pesquisa;
	
	string lendo = "";
	
	for(int i = 0; i < int(pesquisa_.length()); i++){
        char c = pesquisa_[i];
		
        if(c != ' ' && i+1 != int(pesquisa_.length())){
			lendo.push_back(c);
		}

		else{
			lendo = formaliza_palavra(lendo);

			if(indice[lendo].size() != 0){
				palavras_.insert(lendo);
			}
			lendo = "";
		}
	}
}

multiset<string> LeitorPesquisa::palavras() {
    return palavras_;
}

string LeitorPesquisa::formaliza_palavra(string palavra) {
    
    string nova_palavra;

    for(auto c : palavra) {
        c = tolower(c);
        if(!ispunct(c)) {
            nova_palavra.push_back(c);
        }
    }

    return nova_palavra;
}
