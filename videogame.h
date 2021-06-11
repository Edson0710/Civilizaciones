#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>
#include <algorithm>

class Videogame{
    private:
        string nombre;
        vector<Civilizacion> civ;
    public:
        Videogame();
        void setNombre(const string &v);
        string getNombre();
        void agregarCivilizacion(const Civilizacion &c);
        void encabezados();
        void resumen();
        void insertar(const Civilizacion &c, size_t pos);
        void inicializar(const Civilizacion &c, size_t n);
        Civilizacion primera();
        Civilizacion ultima();
        void ordenarNombre();
        void ordenarUbicacionX();
        void ordenarUbicacionY();
        void ordenarPuntuacion();
        void eliminar(const Civilizacion &c);
        void buscar(const Civilizacion &c);
        void modificar(const Civilizacion &c);
        size_t total();

        friend Videogame& operator<<(Videogame &v, const Civilizacion &c){
        v.agregarCivilizacion(c);
        return v;
    }
};

#endif