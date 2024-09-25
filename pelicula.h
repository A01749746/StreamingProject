#ifndef PELICULA_H
#define PELICULA_H
#include "video.h"
#include "interfaz.h"


class Pelicula : public Video , public Interfaz
{
    private:
        string genero; 


    public:

        Pelicula();
        Pelicula(string id, string nom, string gen, double cali, int dura, string fe);
        void cambiar_cali(double cal);
        double mostrarcali();
        void mostrar_nom() ;
        vector <string> mostrar_gen() ;
        void  mostrar_porcali (double num);
        string nom();
        


    

};


#endif 