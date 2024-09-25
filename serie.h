#ifndef SERIE_H
#define SERIE_H
#include "episodio.h"
#include "interfaz.h"
#include <vector>
#include <string>
using std::string;
using std::vector;


class Serie : public Interfaz
{

    private:
        vector<Episodio*> episodios;
        string id;
        string nombre;
        string genero; //serie


    public:
        Serie();
        Serie(string i, string nom, string gen);
        void agregar_episodio(Episodio *epi);
        void ver_lista(string seri);
        void cambiar_cali(double cal);
        void mostrar_nom() ;
        vector <string> mostrar_gen() ;
        void  mostrar_porcali (double num);
        string nom();
        double mostrarcali();







};


#endif