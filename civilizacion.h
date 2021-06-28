#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "aldeano.h"
#include "barco.h"
#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
using namespace std;

class Civilizacion{
    private:
        string nombre;
        int ubicacion_x;
        int ubicacion_y;
        int puntuacion;
        list<Aldeano> aldeanos;
        list<Barco*> puerto;
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

        //  Aldeanos
        void menu();
        void encabezados();
        void encabezadosBarcos();
        void encabezadosGuerreros();
        void agregarInicio(const Aldeano &a);
        void agregarFinal(const Aldeano &a);
        void eliminarNombre(const string &nombre);
        void eliminarSalud(int salud);
        void eliminarEdad();
        void ordenarNombre();
        void ordenarEdad();
        void ordenarSalud();
        void buscar(const string &nombre);
        void modificar(const string &nombre);
        void mostrar();

        //  Respaldo
        void respaldar_aldeanos();
        void recuperar_aldeanos();

        //  Barcos
        void menuBarcos();
        void agregarBarco(Barco *b);
        void capturarBarco();
        void mostrarBarcos();
        void buscarBarco(size_t id);
        void eliminarBarcoId(size_t id);
        void eliminarBarcoCombustible(float combustible);
        void capturarGuerrero(Barco &b);
        void eliminarGuerrero(Barco &b);
        void ultimoGuerrero(Barco &b);
        void mostrarGuerreros(Barco &b);

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