#include "indice.h"

vector<string> nomes_de_arquivos(string path) {

    vector<string> arquivos;

    for (const auto & entry : fs::directory_iterator(path)) {
        arquivos.push_back(entry.path());
    }

    return arquivos;
}

string formaliza_palavra(string palavra) {
    
    string nova_palavra;

    for(auto c : palavra) {
        c = tolower(c);
        if(!ispunct(c)) {
            nova_palavra.push_back(c);
        }
    }

    return nova_palavra;
}

void insere_indice_invertido(map<string,multiset<string> > &indice, string nome_arquivo) {
    
    ifstream arquivo;
    arquivo.open(nome_arquivo);

    string palavra;

    while(arquivo >> palavra) {
        
        palavra = formaliza_palavra(palavra);

        indice[palavra].insert(nome_arquivo);
    }

    return;
}

map<string,multiset<string> > cria_indice_invertido(string path) {

    vector<string> lista_de_arquivos = nomes_de_arquivos(path);

    map<string, multiset<string> > indice_invertido;

    for(auto nome_arquivo_atual : lista_de_arquivos) {
        insere_indice_invertido(indice_invertido, nome_arquivo_atual);
    }

    return indice_invertido;
}