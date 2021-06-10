#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
using namespace std;

class Civilizacion{
    private:
        string nombre;
        int ubicacion_x;
        int ubicacion_y;
        int puntuacion;
    public:
        Civilizacion();
        Civilizacion(const string &nombre, int ubicacion_x, int ubicacion_y, int puntuacion);

        void setNombre(const string &v);
        string getNombre();
        void setUbicacionX(int v);
        int getUbicacionX();
        void setUbicacionY(int v);
        int getUbicacionY();
        void setPuntuacion(int v);
        int getPuntuacion();

        friend ostream& operator<<(ostream &out, const Civilizacion &c){
            out << left;
            out << setw(20) << c.nombre;
            out << setw(6) << c.ubicacion_x;
            out << setw(6) << c.ubicacion_y;
            out << setw(6) << c.puntuacion << endl;
            return out;
        }

        friend istream& operator>>(istream &in, Civilizacion &c){
            cout << "Nombre: ";
            getline(cin, c.nombre);
            cout << "Ubicacion en X: ";
            cin >> c.ubicacion_x;
            cout << "Ubicacion en Y: ";
            cin >> c.ubicacion_y;
            cout << "Puntuacion: ";
            cin >> c.puntuacion;
            return in;
        }

        bool operator==(const Civilizacion& c){
        return nombre == c.nombre;
        }

        bool operator==(const Civilizacion& c) const{
            return nombre == c.nombre;
        }

        bool operator<(const Civilizacion& c){
            return nombre < c.nombre;
        }

        bool operator<(const Civilizacion& c) const{
            return nombre < c.nombre;
        }
};

#endif