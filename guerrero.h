#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Guerrero{
    private:
        size_t id;
        size_t salud;
        float fuerza;
        float escudo;
        string tipo;
    public:
        Guerrero();
        void setId(size_t id);
        size_t getId();
        void setSalud(size_t salud);
        size_t getSalud();
        void setFuerza(float fuerza);
        float getFuerza();
        void setEscudo(float escudo);
        float getEscudo();
        void setTipo(const string &tipo);
        string getTipo();

        friend ostream& operator<<(ostream &out, const Guerrero &g){
            out << left;
            out << setw(4) << g.id;
            out << setw(6) << g.salud;
            out << setw(6) << g.fuerza;
            out << setw(6) << g.escudo;
            out << setw(10) << g.tipo;
            return out;
        }

};

#endif