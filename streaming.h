#ifndef STREAMING_H
#define STREAMING_H
#include "catalogo.h"


class Streaming
{

    private:
        Catalogo catalogo;
        int opcion;

    public:

        Streaming();
        void comenzar(int op);
        int opciones();
        void info();



};



#endif 