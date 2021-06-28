#ifndef BARCO_H
#define BARCO_H

#include "guerrero.h"
#include <stack>
#include <iomanip>

class Barco{
    private:
        size_t id;
        float combustible;
        float velocidad;
        float armadura;
        stack<Guerrero> pila;
    public:
        Barco();
        void setId(size_t id);
        size_t getId();
        void setCombustible(float combustible);
        float getCombustible();
        void setVelocidad(float velocidad);
        float getVelocidad();
        void setArmadura(float armadura);
        float getArmadura();
        //  Stack
        void agregarGuerrero(Guerrero &g);
        void eliminarGuerrero();
        Guerrero tope();
        void mostrar();
        bool vacia();

        friend ostream& operator<<(ostream &out, const Barco &b){
            out << left;
            out << setw(4) << b.id;
            out << setw(6) << b.combustible;
            out << setw(6) << b.velocidad;
            out << setw(6) << b.armadura;
            out << setw(6) << b.pila.size();
            return out;
        }
};

#endif