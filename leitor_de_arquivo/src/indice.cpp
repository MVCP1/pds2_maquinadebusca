#include "indice.h"

using namespace std;
namespace fs = filesystem;

IndiceInvertido::IndiceInvertido() {
    map<string,multiset<string> > indice_;
    num_arquivos_ = 0;
    vector<string> nomes_arquivos_(0);
}

int IndiceInvertido::num_arquivos() {
    return num_arquivos_;
}

multiset<string> IndiceInvertido::operator[](string palavra) {
    return indice_[palavra];
}

void IndiceInvertido::InserePasta(string pasta) {
    InsereNomesArquivos(pasta);
    vector<string> lista_de_arquivos = nomes_arquivos();

    for(auto nome_arquivo_atual : lista_de_arquivos) {
        InsereArquivo(nome_arquivo_atual);
        num_arquivos_++;
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

void IndiceInvertido::InsereNomesArquivos(string path) {

    for (const auto & entry : fs::directory_iterator(path)) {
        nomes_arquivos_.push_back(entry.path());
    }
}

vector<string> IndiceInvertido::nomes_arquivos() {
    return nomes_arquivos_;
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
