
#include "coordenadas.h"

Coordenadas::Coordenadas(string palavra, map<string,multiset<string> > indice, vector<string> nomes_de_arquivos){
    palavra_ = palavra;
    docs_ = indice[palavra];
    totalDocs_ = nomes_de_arquivos.size();

    set<string> new_set(docs_.begin(), docs_.end());
    docsSemRepetir_ = new_set.size();
}

string  Coordenadas::palavra(){
    return palavra_;
}

double Coordenadas::frequencia(string doc){
    return docs_.count(doc);
}

double Coordenadas::importancia(){
    return log(totalDocs_/docsSemRepetir_);
}
