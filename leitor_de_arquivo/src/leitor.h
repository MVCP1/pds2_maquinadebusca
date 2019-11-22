// Funções que leem arquivos da pasta "files",
// quebram o texto em palavras e retornam

#ifndef LEITOR_H
#define LEITOR_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Leitor{
    public: 
		// Recebe uma string da pesquisa feita e um set de todas as palavras existentes nos documentos
        Leitor(string pesquisa, set<string> existentes);
		
		/*
        // Insere os arquivos de pasta no índice invertido
        void InserePasta(string pasta);
		*/
		
        // Retorna um multiset de todas as palavras da pesquisa (que também existem nos documentos) tratadas
        multiset<string> palavras();

    private:

        multiset<string> palavras_;  // Multiset de todas as palavras da pesquisa (que também existem nos documentos) tratadas
		
		set<string> existentes_; // Set de todas as palavras existentes nos documentos
        
		string pesquisa_; // String da pesquisa feita
		/*
        // Lê o arquivo "nome_arquivo" coloca as palavras
        // contidas nele no map "índice", usando as palavras como chave
        // e os arquivos onde aparecem como elementos
        void InsereArquivo(string nome_arquivo);
		*/
		
		
        // Recebe uma palavra, tira suas pontuações
        // e transforma em minúcula
        string formaliza_palavra(string palavra);

        friend class LeitorTeste;
};

#endif // LEITOR_H