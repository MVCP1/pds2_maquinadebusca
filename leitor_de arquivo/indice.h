// Funções que leem arquivos da pasta "files",
// quebram o texto em palavras e retornam

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
namespace fs = filesystem;

vector<string> nomes_de_arquivos(string path);
// Retorna um vetor contendo os nomes de arquivos na
// pasta que está no caminho "path"

string formaliza_palavra(string palavra);
// Recebe uma palavra, tira suas pontuações 
// e transforma em minúcula

void insere_indice_invertido(map<string,multiset<string> > &indice, string nome_arquivo);
// Lê o arquivo "nome_arquivo" coloca as palavras 
// contidas nele no map "índice", usando as palavras como chave
// e os arquivos onde aparecem como elementos

map<string,multiset<string> > cria_indice_invertido(string path);
// Cria e retorna um indice invertio com os arquivos da pasta no caminho "path"