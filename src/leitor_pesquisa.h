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

        // Retorna um multiset com as palavras da query no formato correto
        multiset<string> Pesquisa(IndiceInvertido &indice);

    private:
        // Multiset de todas as palavras da pesquisa (que também existem nos documentos) tratadas
        multiset<string> palavras_; 

        // Recebe uma string digitada pelo usuário
        string entrada();
        
        // Recebe uma string da pesquisa feita e retorna um multiset da com as palavras e suas frequências
        multiset<string> frequencias(IndiceInvertido &indice, string pesquisa);
		
        // Recebe uma palavra, tira suas pontuações
        // e transforma em minúscula
        string formaliza_palavra(string palavra);

        friend class LeitorPesquisaTeste;
};

#endif // LEITOR_PESQUISA_H