// Funções que leem arquivos da pasta "files",
// quebram o texto em palavras e retornam

#ifndef LEITOR_PESQUISA_H
#define LEITOR_PESQUISA_H

#include "indice.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class LeitorPesquisa{
    public: 
        LeitorPesquisa();
        
        // Recebe uma string da pesquisa feita e retorna um multiset da com as palavras e suas frequências
        multiset<string> pesquisa(IndiceInvertido &indice);

    private:

        // Multiset de todas as palavras da pesquisa (que também existem nos documentos) tratadas
        multiset<string> palavras_; 
		
        // Recebe uma palavra, tira suas pontuações
        // e transforma em minúcula
        string formaliza_palavra(string palavra);

        friend class LeitorTeste;
};

#endif // LEITOR_PESQUISA_H