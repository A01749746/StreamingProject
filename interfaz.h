#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>
using std::string;
#include <vector>
using std::vector;


class Interfaz{


    public: 
        void virtual cambiar_cali(double cal) = 0;
        void virtual mostrar_nom() = 0;
        vector <string> virtual mostrar_gen() =0;
        void virtual mostrar_porcali (double num) = 0;
        string virtual nom() = 0;
        double virtual mostrarcali() =0;
        

        

};



#endif