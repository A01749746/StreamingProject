#ifndef VIDEO_H
#define VIDEO_H
#include <string>
using std::string;
#include <ostream>
using std::ostream;


class Video
{
    public:

        string ID;
        string nombre;
        double calificacion;
        int duracion;
        string fecha;

    public:
        Video(string id, string nom, string gen, double cali, int dura, string fe);
        Video();



    

};





#endif