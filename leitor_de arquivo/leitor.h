// Funções que leem arquivos da pasta "files",
// quebram o texto em palavras e retornam

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;
namespace fs = std::filesystem;

vector<string> nomes_de_arquivos();
// Retorna um vetor contendo os nomes de arquivos na
// pasta "files"

multiset<string> palavras_arquivo(string nome_arquivo);
// Lê o arquivo "nome_arquivo" e retorna um multiset 
// contendo suas palavras formalizadas

string formaliza_palavra(string palavra);
// Recebe uma palavra, tira suas pontuações 
// e transforma em minúcula
