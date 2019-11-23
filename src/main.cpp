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
    string s = "s";

    system("cls|clear");

    cout << "Gostaria de fazer uma pesquisa? (s/n): ";
    cin >> s;
    if(s != "s") return 0;

    multiset <string> pesquisa = leitor.Pesquisa(indice);

    Rank rank(pesquisa, indice, norma);
    rank.imprimir(10);
    
    return 0;
}
