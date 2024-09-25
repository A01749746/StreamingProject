#include <iostream>
#include "streaming.h"
#include "pelicula.h"
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;


Streaming::Streaming(){

    catalogo.leer_archivo();


}

void Streaming::info(){

    cout << endl << endl;
    cout << " ID      |              Nombre              |   Duracion   | Genero | "
            "Calificación | Estreno  |    Nombre Episodio       | Temporada | Num. Episodio | ID Episodio"
         << endl;
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"
            "<><><><><><>"
         << endl;
}

void Streaming::comenzar(int op){


    if (op == 1){
        Streaming::info();
        catalogo.completo();
    }else if(op == 2){
        Streaming::info();
        catalogo.mostrar_peliculas();
    }else if(op == 3){
        Streaming::info();
        catalogo.mostrar_series();
    }else if(op == 4){
        
        while (true){
            double num;
            cout << "Ingresa la calificación deseada: " << endl;

            if (cin >> num){

                try {
                    Streaming::info();
                    catalogo.por_calificacion(num);
                    break;
                }
                catch(string &s){
                    cout << "Error " << s << endl;
                }
            }else{
                cout << "Porfavor ingresa un numero." << std::endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            }
        }
    } else if (op == 5) {
        string gen;
        bool valido = false;
        cout << "Ingresa el genero deseado: " << endl;
        cout << "Tenemos: Accion/Aventura/Drama/Fantasy/Romance/Sci-Fi/Suspenso/Familiar/Musical/Guerra/Romance/Misterio/Crimen/Western/Comedia/Terror/Biografia/Animacion/" << endl;
        while (!valido) {
            cin >> gen;
            try {
                Streaming::info();
                catalogo.por_genero(gen);
                valido = true;
            } catch (string& x) {
                cout << "Error " << x << endl;
                cout << "Vuelve a ingresar el genero: " << endl;
            }
    }

    }else if(op == 6){
        string tit;
        double cal;

        bool valido = false;
        while (!valido){

            cout << "Ingresa el título a cambiar: " << endl;
            cin >>tit;
            cout << "Ingresa la nueva calificación: ";
            cin >> cal;

            try{
                catalogo.cambiar_cali(tit, cal);
                valido=true;
            }
            catch(string &a){
                cout << "Error " << a << endl;
            }

        }

    }else if(op == 7){
        string seri;
        cout << "Ingresa la serie de la cúal gustas ver los capítulos: " << endl;
        cin >> seri;
        Streaming::info();
        catalogo.mostrar_episodios(seri);

    }else if (op >8){
        string s = "Porfavor ingresa un número del 1 al 7";
        throw(s);
    }else if (op <=0){
        string s = "Porfavor ingresa un número del 1 al 7";
        throw(s);
    }


}

int Streaming::opciones(){

    int num;

    cout << endl;
    cout << "Bienvenido a Netflix" << endl;
    cout << "Selecciona una de las siguientes opciones" << endl;
    cout << "1. Ver Catalogo completo" << endl;
    cout << "2. Ver peliculas " << endl;
    cout << "3. Ver series " << endl;
    cout << "4. Filtrar por calificacion" << endl;
    cout << "5. Filtrar por genero" << endl;
    cout << "6. Cambiar una calificacion" << endl;
    cout << "7. Ver episodios de una serie" << endl;
    cout << "8. Salir" << endl;


    while (true) {
        cout << "Ingresa un número: ";
        if (cin >> num) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; 
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Por favor ingresa un número." << endl;
        }
    }

    return num;
}
