#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>

#include "indice.h"

using namespace std;

int main() {

    map<string, multiset<string> > indice_invertido;

    string nome_da_pasta;
    cout << "Digite o nome da pasta em que deseja pesquisar: ";
    cin >> nome_da_pasta;

    indice_invertido = cria_indice_invertido(nome_da_pasta);

    /*for(map<string,multiset<string>>::iterator it = indice_invertido.begin(); it != indice_invertido.end(); it++) {
        
        string palavra = it->first;
        
        cout << "A palavra \""<< palavra << "\" aparece nos arquivos: " << endl;

        for(auto docs : indice_invertido[palavra]) {
            cout << docs << " ";
        }
        cout << endl << endl;
    }*/

    return 0;
}