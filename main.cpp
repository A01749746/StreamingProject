#include <iostream>
#include "streaming.h"
#include "pelicula.h"
#include "serie.h"
#include "video.h"
using std::cout;
using std::endl;
using std::cin;

int main (){


    Streaming streaming;

    while (true ){

        int i = streaming.opciones();

        if (i == 8){
            break;
        }


        try{
            streaming.comenzar(i);
        }
        catch(string &x){
            cout << "Error " << x << endl;

        }

    }
    


    


}