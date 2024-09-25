#include <iostream>
#include "episodio.h"
using std::cout;
using std::endl;


Episodio::Episodio(){

}

Episodio::Episodio(string id, string nom, double cali, int dura, string fe, int temp, int n){

    ID = id;
    nombre = nom;
    calificacion = cali;
    duracion = dura;
    fecha =  fe;
    temporada = temp;
    capitulo = n;

}

void Episodio::cambiar_cali(double num){

    calificacion = num;

}

int Episodio::tempo(){

    return temporada;
}

int Episodio::cap(){

    return capitulo;
}
