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
		// Recebe uma string da pesquisa feita e um set de todas as palavras existentes nos documentos
        LeitorPesquisa(string pesquisa, IndiceInvertido &indice);
		
        // Retorna um multiset de todas as palavras da pesquisa (que também existem nos documentos) tratadas
        multiset<string> palavras();

    private:

        multiset<string> palavras_;  // Multiset de todas as palavras da pesquisa (que também existem nos documentos) tratadas
        
		string pesquisa_; // String da pesquisa feita
		
        // Recebe uma palavra, tira suas pontuações
        // e transforma em minúcula
        string formaliza_palavra(string palavra);

        friend class LeitorTeste;
};

#endif // LEITOR_PESQUISA_H