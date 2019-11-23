#include "leitor_pesquisa.h"

using namespace std;
namespace fs = filesystem;

LeitorPesquisa::LeitorPesquisa() {
    vector<string> palavras_;
}

multiset<string> LeitorPesquisa::Pesquisa(IndiceInvertido &indice) {
    string pesquisa = entrada();

    return frequencias(indice, pesquisa);
}

multiset<string> LeitorPesquisa::frequencias(IndiceInvertido &indice, string pesquisa) {
    string lendo = "";
	
	for(int i = 0; i <= int(pesquisa.length()); i++){
        char c = pesquisa[i];
		
		if(c == ' ' or i == int(pesquisa.length())){
			lendo = formaliza_palavra(lendo);

			if(indice[lendo].size() != 0){
				palavras_.insert(lendo);
			}
			lendo = "";
		}
        else {
			lendo.push_back(c);
		}

	}
    return palavras_;
}

string LeitorPesquisa::entrada() {
    string entrada;
    cout << "Digite sua pesquisa: ";
    cin.ignore();
    getline(cin, entrada);

    return entrada;
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
