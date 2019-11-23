
#include "coordenadas.h"

Coordenadas::Coordenadas(string palavra, IndiceInvertido& indice){
    palavra_ = palavra;
    docs_ = indice[palavra];
    totalDocs_ = (double) indice.num_arquivos();

    set<string> new_set(docs_.begin(), docs_.end());
    docsSemRepetir_ = new_set.size();
}

string  Coordenadas::palavra(){
    return palavra_;
}

double Coordenadas::frequencia(string doc){
    return (double) docs_.count(doc);
}

double Coordenadas::importancia(){
    return log(totalDocs_/docsSemRepetir_);
}

double Coordenadas::valor(string doc){
    return docs_.count(doc)*log(totalDocs_/docsSemRepetir_);
}