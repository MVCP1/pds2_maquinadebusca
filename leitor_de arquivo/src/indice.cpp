#include "indice.h"

using namespace std;
namespace fs = filesystem;

IndiceInvertido::IndiceInvertido() {
    map<string,multiset<string> > indice_;
    numDocs_ = 0;
}

int IndiceInvertido::numArquivos() {
    return numDocs_;
}

multiset<string> IndiceInvertido::operator[](string palavra) {
    return indice_[palavra];
}

void IndiceInvertido::InserePasta(string pasta) {
    vector<string> lista_de_arquivos = nomes_arquivos(pasta);

    for(auto nome_arquivo_atual : lista_de_arquivos) {
        InsereArquivo(nome_arquivo_atual);
        numDocs_++;
    }
}

void IndiceInvertido::InsereArquivo(string nome_arquivo) {
    ifstream arquivo;
    arquivo.open(nome_arquivo);

    string palavra;

    while(arquivo >> palavra) {
        palavra = formaliza_palavra(palavra);

        indice_[palavra].insert(nome_arquivo);
    }

    arquivo.close();
}

vector<string> IndiceInvertido::nomes_arquivos(string path) {

    vector<string> arquivos;

    for (const auto & entry : fs::directory_iterator(path)) {
        arquivos.push_back(entry.path());
    }

    return arquivos;
}

string IndiceInvertido::formaliza_palavra(string palavra) {
    
    string nova_palavra;

    for(auto c : palavra) {
        c = tolower(c);
        if(!ispunct(c)) {
            nova_palavra.push_back(c);
        }
    }

    return nova_palavra;
}
