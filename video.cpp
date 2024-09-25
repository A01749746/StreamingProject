#include <iostream>
#include "video.h"
using std::endl;
using std::cout;

Video::Video(){

}

Video::Video(string id, string nom, string gen, double cali, int dura, string fe){

    ID = id;
    nombre = nom;
    calificacion = cali;
    duracion = dura;
    fecha = fe;

}


