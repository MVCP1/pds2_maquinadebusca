#include <iostream>
#include <cstdlib>
#include "indice.h"
#include "coordenadas.h"
#include "rank.h"
#include "leitor_pesquisa.h"
#include "normas.h"

using namespace std;

int main() {
    IndiceInvertido indice;
    indice.InserePasta("arquivos");
    Norma norma(indice);
    LeitorPesquisa leitor;
    string continuar = "s";

    system("cls|clear");

    cout << "Gostaria de fazer uma pesquisa? (s/n): ";
    cin >> continuar;

    while(continuar != "n") {
        multiset <string> pesquisa = leitor.Pesquisa(indice);

        Rank rank(pesquisa, indice, norma);
        rank.imprimir(10);

        cout << endl << "Gostaria de pesquisar mais uma vez? (s/n): ";
        cin >> continuar;
    }
    
    return 0;
}
