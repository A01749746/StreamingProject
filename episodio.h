#ifndef EPISODIO_H
#define EPISODIO_H
#include "video.h"
#include "interfaz.h"


class Episodio : public Video
{

    private:
        int temporada;
        int capitulo;
    
    public:

        Episodio();
        Episodio(string id, string nom, double cali, int dura, string fe, int temp, int n);
        void cambiar_cali(double cali);
        int tempo();
        int cap();

};


#endif 