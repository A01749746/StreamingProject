#include <iostream>
#include "serie.h"
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>


Serie::Serie(){

}


Serie::Serie(string i, string nom, string gen){

    nombre = nom;
    id = i;
    genero = gen;

}

void Serie::agregar_episodio(Episodio *epi){

    episodios.push_back(epi);

}

void Serie::ver_lista(string seri){

    for (int i=0; i<=episodios.size();i++){

        if(nombre == seri){
            cout << " " << id << "|      " << nombre << "   |   " << episodios[i]->duracion << "  |   " << genero << " |   "
            << episodios[i]->calificacion << " |    " << episodios[i]->fecha << " |  " << episodios[i]->nombre << " |  " << episodios[i]->tempo() << " | " << episodios[i]->cap() << "  | " << episodios[i]->ID
            << endl;
        }

    }

}

void Serie::cambiar_cali(double cal){

    int num;
    int count = 1;
    
    for(int i =0 ; i < episodios.size(); i++){

        cout << count << ") " << episodios[i]->nombre << endl;
        count = count +1;

    }

    cout << "A cúal capítulo deseas cambiarle la calificación ? " << endl;
    cin >> num;

    num = num-1;

    episodios[num] ->cambiar_cali(cal);

}



void Serie::mostrar_nom(){

    for (int i =0 ; i < episodios.size(); i++){

        cout << " " << id << "|      " << nombre << "   |   " << episodios[i]->duracion << "  |   " << genero << " |   "
        << episodios[i]->calificacion << " |    " << episodios[i]->fecha << " |  " << episodios[i]->nombre << " |  " << episodios[i]->tempo() << " | " << episodios[i]->cap() << "  | " << episodios[i]->ID
        << endl;


    }


}

vector <string> Serie::mostrar_gen(){

    vector <string> separados;

    std::stringstream ss(genero);
    string token;

    while (std::getline(ss, token, '/')) {
        separados.push_back(token);
    }

    
    return separados;

}


void Serie::mostrar_porcali(double num){

    for(int i =0 ; i < episodios.size(); i++){

        if(episodios[i]->calificacion >= num){
        cout << " " << id << "|      " << nombre << "   |   " << episodios[i]->duracion << "  |   " << genero << " |   "
        << episodios[i]->calificacion << " |    " << episodios[i]->fecha << " |  " << episodios[i]->nombre << " |  " << episodios[i]->tempo() << " | " << episodios[i]->cap() << "  | " << episodios[i]->ID
        << endl;
        }

    }


}

string Serie::nom(){

    return nombre;

}

double Serie::mostrarcali(){

    return 10;

}
