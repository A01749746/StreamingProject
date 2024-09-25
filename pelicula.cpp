#include <iostream>
#include "pelicula.h"
using std::endl;
using std::cout;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>


Pelicula::Pelicula(){

}

Pelicula::Pelicula(string id, string nom, string gen, double cali, int dura, string fe){

    ID = id;
    nombre = nom;
    genero = gen;
    calificacion = cali;
    duracion = dura;
    fecha =  fe;

}

void Pelicula::cambiar_cali(double cal){

    calificacion = cal;

}



void Pelicula::mostrar_nom(){

    cout << " " << ID << "  |       " << nombre << "    |    " << duracion << "    |  " << genero << "  |  "
        << calificacion << " | " << fecha
        << endl;


}

vector <string> Pelicula::mostrar_gen(){

    vector <string> separados;

    std::stringstream ss(genero);
    string token;

    while (std::getline(ss, token, '/')) {
        separados.push_back(token);
    }
    
    return separados;
}

double Pelicula::mostrarcali(){

    return calificacion;

}

void Pelicula::mostrar_porcali(double num){

}

string Pelicula::nom(){

    return nombre;

}

