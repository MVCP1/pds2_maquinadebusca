#include "leitor.h"

using namespace std;
namespace fs = filesystem;

Leitor::Leitor(string pesquisa, set<string> existentes) {
	existentes_ = existentes;
    pesquisa_ = pesquisa;
	
	string lendo = "";
	
	for(int i = 0; i < pesquisa_.length(); i++){
		char c = pesquisa_[i];
		if(c != " " && i+1 != pesquisa_.length())){
			lendo.push_back(c);	
		}
		else{
			if(c != " " && i+1 == pesquisa_.length()){
				lendo.push_back(c);
			}
			if(existentes_.count() != 0){
				lendo = formaliza_palavra(lendo);
				palavras_.insert(lendo);
			}
			lendo = "";
		}
	}
}

multiset<string> Leitor::palavras() {
    return palavras_;
}

/*
void Leitor::InserePasta(string pasta) {
    vector<string> lista_de_arquivos = nomes_arquivos(pasta);

    for(auto nome_arquivo_atual : lista_de_arquivos) {
        InsereArquivo(nome_arquivo_atual);
    }
}

void Leitor::InsereArquivo(string nome_arquivo) {
    ifstream arquivo;
    arquivo.open(nome_arquivo);

    string palavra;

    while(arquivo >> palavra) {
        palavra = formaliza_palavra(palavra);

        palavras_.insert(nome_arquivo);
    }

    arquivo.close();
}
*/

string Leitor::formaliza_palavra(string palavra) {
    
    string nova_palavra;

    for(auto c : palavra) {
        c = tolower(c);
        if(!ispunct(c)) {
            nova_palavra.push_back(c);
        }
    }

    return nova_palavra;
}
