#include "leitor.h"

std::multiset<std::string> palavras_arquivo(std::string nome_arquivo) {
    
    cout << nome_arquivo << endl;

    std::ifstream arquivo;
    arquivo.open(nome_arquivo);

    std::string palavra;
    std::multiset<std::string> conjunto_de_palavras;

    while(arquivo >> palavra) {
        palavra = formaliza_palavra(palavra);

        conjunto_de_palavras.insert(palavra);
    }

    return conjunto_de_palavras;
}

std::string formaliza_palavra(std::string palavra) {
    
    std::string nova_palavra;

    for(auto c : palavra) {
        c = tolower(c);
        if(!ispunct(c)) {
            nova_palavra.push_back(c);
        }
    }

    return nova_palavra;
}

std::vector<std::string> nomes_de_arquivos() {
    std::string path = "files";

    std::vector<std::string> arquivos;

    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        arquivos.push_back(entry.path());
    }

    return arquivos;
}