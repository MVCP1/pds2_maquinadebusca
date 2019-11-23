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

        // Retorna nomes_arquivos_
        vector<string> nomes_arquivos();

        // Retorna um set com todas as palavras chaves do map
        set<string> todas_palavras();

    private:
        int num_arquivos_;
        map<string,multiset<string> > indice_invertido_;
        set<string> todas_palavras_;
        vector<string> nomes_arquivos_;

        // Insere em nomes_arquivos_ os nomes de arquivos da
        // pasta que está no caminho "path"
        void InsereNomesArquivos(string path);
        
        // Lê o arquivo "nome_arquivo" coloca as palavras
        // contidas nele no map "índice", usando as palavras como chave
        // e os arquivos onde aparecem como elementos
        void InsereArquivo(string nome_arquivo);

        // Recebe uma palavra, tira suas pontuações
        // e transforma em minúcula
        string formaliza_palavra(string palavra);

        friend class IndiceTeste;
};

#endif // INDICE_H
