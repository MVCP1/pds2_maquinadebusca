#include "leitor.h"

namespace fs = std::filesystem;
using namespace std;

multiset<string> palavras_arquivo(string nome_arquivo) {
    
    cout << nome_arquivo << endl;

    ifstream arquivo;
    arquivo.open(nome_arquivo);

    string palavra;
    multiset<string> conjunto_de_palavras;

    while(arquivo >> palavra) {
        palavra = formaliza_palavra(palavra);

        conjunto_de_palavras.insert(palavra);
    }

    return conjunto_de_palavras;
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

vector<string> nomes_de_arquivos() {
    string path = "files";

    vector<string> arquivos;

    for (const auto & entry : fs::directory_iterator(path)) {
        arquivos.push_back(entry.path());
    }

    return arquivos;
}