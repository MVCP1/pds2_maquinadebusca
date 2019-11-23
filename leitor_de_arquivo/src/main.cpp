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

    multiset <string> pesquisa = leitor.Pesquisa(indice);

    Rank rank(pesquisa, indice, norma);
    rank.imprimir(10);
    
    return 0;
}
