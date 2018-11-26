#ifndef ORGANIZACION_H
#define ORGANIZACION_H
#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Organizacion
{
    public:
        Organizacion();
        Organizacion(string);

        void agregar();
        void listar();
	    void listar2();
        void listar3();
        void eliminar(string);
        void inicio();
        void setNombre(string);
        string getNombre();

    protected:

    private:
        string nombre;
};
#endif // ORGANIZACION_H
