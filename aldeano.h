#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Aldeano{
    private:
        string nombre;
        size_t edad;
        char genero;
        int salud;
    public:
        Aldeano(){}
        void setNombre(const string &nombre);
        string getNombre();
        void setEdad(size_t edad);
        size_t getEdad() const;
        void setGenero(char genero);
        char getGenero();
        void setSalud(int salud);
        int getSalud() const;

        friend ostream& operator<<(ostream &out, const Aldeano &a){
            out << left;
            out << setw(10) << a.nombre;
            out << setw(4) << a.edad;
            out << setw(4) << a.genero;
            out << setw(4) << a.salud;
            return out;
        }

        friend istream& operator>>(istream &in, Aldeano &a){
            cout << "Nombre: ";
            getline(cin, a.nombre);
            cout << "Edad: ";
            cin >> a.edad;
            cout << "Genero: ";
            cin >> a.genero;
            cout << "Salud: ";
            cin >> a.salud;
            return in;
        }

};


#endif