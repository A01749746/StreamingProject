#ifndef CATALOGO_H
#define CATALOGO_H
#include "video.h"
#include <vector>
#include <string>
using std::string;
using std::vector;
#include "pelicula.h"
#include "serie.h"
#include "interfaz.h"


class Catalogo
{
    private:

        vector<Interfaz*> contenido;

    public:

        Catalogo();
        void leer_archivo();
        void completo();
        void mostrar_peliculas();
        void mostrar_series();
        void mostrar_episodios(string seri);
        void por_calificacion(double cali);
        void por_genero(string gen);
        void cambiar_cali(string nom, double num);



};



#endif