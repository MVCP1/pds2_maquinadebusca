// Funções que leem arquivos da pasta "files",
// quebram o texto em palavras e retornam

#ifndef INDICE_H
#define INDICE_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class IndiceInvertido{
    public: 
        IndiceInvertido();

        // Insere os arquivos de pasta no índice invertido
        void InserePasta(string pasta);

        // Retorna o número de documentos lidos no índice
        int num_arquivos();

        // Retorna um multiset de documentos onde palavra aparece
        multiset<string> operator[](string palavra);

    private:

        int num_arquivos_;
        map<string,multiset<string> > indice_;
        
        // Lê o arquivo "nome_arquivo" coloca as palavras
        // contidas nele no map "índice", usando as palavras como chave
        // e os arquivos onde aparecem como elementos
        void InsereArquivo(string nome_arquivo);

        // Recebe uma palavra, tira suas pontuações
        // e transforma em minúcula
        string formaliza_palavra(string palavra);

        // Retorna um vetor contendo os nomes de arquivos na
        // pasta que está no caminho "path"
        vector<string> nomes_arquivos(string path);

        friend class IndiceTeste;

        friend class Rank;
};

#endif // INDICE_H