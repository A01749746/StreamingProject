#include <iostream>
#include "catalogo.h"
#include "pelicula.h"
#include "episodio.h"
#include "serie.h"
#include <fstream>
#include <sstream>
using std::ifstream;
using namespace std;
using std::cout;
using std::endl;
using std::cin;
#include <stdexcept> 




Catalogo::Catalogo(){

}

void Catalogo::leer_archivo() {
    ifstream catalogo;
    catalogo.open("/Users/betolimon/desktop/integrador-A01749746-1/BasePeliculas.csv");

    if (!catalogo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string line;
    while (getline(catalogo, line)) {
        stringstream token(line);
        string id;
        string nombre;
        string duracion;
        string genero;
        string calificacion;
        string fecha;
        string nom_epi;
        string temp;
        string cap;
        string id_epi;

        getline(token, id, ',');
        getline(token, nombre, ',');
        getline(token, duracion, ',');
        getline(token, genero, ',');
        getline(token, calificacion, ',');
        getline(token, fecha, ',');
        getline(token, id_epi, ',');
        getline(token, nom_epi, ',');
        getline(token, temp, ',');
        getline(token, cap, ',');

        try {
            if (id_epi == "") {
                Pelicula *p = new Pelicula(id, nombre, genero, stod(calificacion), stoi(duracion), fecha);
                contenido.push_back(p);
            } else {

                Episodio *e = new Episodio(id_epi, nom_epi, stod(calificacion), stoi(duracion), fecha, stoi(temp), stoi(cap));
                bool x = false;
                for (int i = 0; i < contenido.size(); i++) {
                    
                    if (auto serie = dynamic_cast<Serie*>(contenido[i])) {
                        if (contenido[i]->nom() == nombre) {
                            serie->agregar_episodio(e);
                            x = true;
                        } 
                    }
                }

                if (x == false){
                    
                    Serie *s = new Serie(id, nombre, genero);
                    s->agregar_episodio(e);
                    contenido.push_back(s);
                        
                }
            }
        } catch (...) {
            cout << "Error atrapado  " << endl;
        }
    }
}



void Catalogo::completo(){

    for (int i =0; i< contenido.size(); i++) {
        contenido[i]->mostrar_nom();
    }
}

void Catalogo::mostrar_peliculas(){

    for (int i = 0; i< contenido.size();i++){
        if (auto pelicula = dynamic_cast<Pelicula*>(contenido[i])) {
            pelicula->mostrar_nom();
        }

    }
}

void Catalogo::mostrar_series(){

    for (int i = 0; i< contenido.size();i++){
        if (auto serie = dynamic_cast<Serie*>(contenido[i])) {
            serie->mostrar_nom();
        }
    }

}

void Catalogo::mostrar_episodios(string seri){

    for (int i = 0; i< contenido.size();i++){
        if (auto serie = dynamic_cast<Serie*>(contenido[i])) {
            serie->ver_lista(seri);
        }
    }

}

void Catalogo::por_calificacion(double cali){

    if ((cali> 10)or(cali<0)){
        string s = "Favor de ingresar un numero del 0 al 10 ";
        throw(s);
    }


    for (int i = 0; i< contenido.size();i++){
        if (auto pelicula = dynamic_cast<Pelicula*>(contenido[i])) {
            if(pelicula->calificacion >= cali){
                pelicula->mostrar_nom();
            }
        }
        else if (auto serie = dynamic_cast<Serie*>(contenido[i])){
            serie->mostrar_porcali(cali);
        }

    }

}

void Catalogo::por_genero(string gen){

    if (gen != "Aventura" && gen != "Accion" && gen != "Drama" && gen != "Fantasy" && gen != "Romance" && gen != "Sci-Fi" && gen != "Suspenso" && gen != "Familiar" && gen != "Musical" && gen != "Guerra" && gen != "Romance" && gen != "Misterio" && gen != "Crimen" && gen != "Western" && gen != "Comedia" && gen != "Terror" && gen != "Biografia" && gen != "Animacion") {
        string s = "Genero invalido " + gen;
        throw(s);
    }

    for (int i =0; i< contenido.size(); i++) {

        for (int i = 0 ; contenido[i]->mostrar_gen().size(); i++){

            if(contenido[i]->mostrar_gen()[i] == gen){
                contenido[i]->mostrar_nom();

            }

        }

    }

}

void Catalogo::cambiar_cali(string nom, double num){
    
    if ((num> 10)or(num<0)){
        string s = "Favor de ingresar un numero del 0 al 10 ";
        throw(s);
    }

    bool x = false;

    for (int i = 0; i< contenido.size();i++){   
        if (contenido[i]->nom() == nom)
        x = true;
    }

    if (x == false){
        string y= "Ingresa correctamente el nombre ";
        throw(y);
    }

    for (int i = 0; i< contenido.size();i++){
        if (contenido[i]->nom() == nom){
            contenido[i]->cambiar_cali(num);
        }

    }

    cout << "Calificacion actualizada" << endl;


}