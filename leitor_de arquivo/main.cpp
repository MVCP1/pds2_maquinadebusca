#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "leitor.h"

using namespace std;

int main() {

    vector<string> lista_de_arquivos = nomes_de_arquivos();

    multiset<string> palavras;
 
    for(auto s : lista_de_arquivos) {
        
        palavras = palavras_arquivo(s);
        
        cout << "Tamanho arquivo: " << palavras.size() << endl;
        cout << "Palavras: ";
        for(auto r : palavras) {
            cout << r << " ";
        }
    }

    return 0;
}