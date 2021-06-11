#include "civilizacion.h"
#include <conio.h>

Civilizacion::Civilizacion(){}

Civilizacion::Civilizacion(const string &nombre, int ubicacion_x, int ubicacion_y, int puntuacion){
    this -> nombre = nombre;
    this -> ubicacion_x = ubicacion_x;
    this -> ubicacion_y = ubicacion_y;
    this -> puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v){
    nombre = v;
}
string Civilizacion::getNombre(){
    return nombre;
}

void Civilizacion::setUbicacionX(int v){
    ubicacion_x = v;
}
int Civilizacion::getUbicacionX(){
    return ubicacion_x;
}

void Civilizacion::setUbicacionY(int v){
    ubicacion_y = v;
}
int Civilizacion::getUbicacionY(){
    return ubicacion_y;
}

void Civilizacion::setPuntuacion(int v){
    puntuacion = v;
}
int Civilizacion::getPuntuacion(){
    return puntuacion;
}

void Civilizacion::agregarInicio(const Aldeano &a){
    aldeanos.push_front(a);
    puntuacion += 100;
}

void Civilizacion::agregarFinal(const Aldeano &a){
    aldeanos.push_back(a);
    puntuacion += 100;
}

void Civilizacion::eliminarNombre(const string &nombre){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarSalud(int salud){
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
}

void Civilizacion::mostrar(){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

bool comparador(const Aldeano &a){
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad(){
    aldeanos.remove_if(comparador);
}


void Civilizacion::menu(){
    int opc;
    getch();
    do{
        system("cls");
        cout << "Aldeanos de " << getNombre() << ": " << endl
            << "1) Agregar aldeano" << endl
            << "2) Eliminar aldeano" << endl
            << "6) Mostrar" << endl
            << "0) salir" << endl
            << "Opcion: ";
        cin >> opc; cin.ignore();
        switch(opc){
            case 1:{
                int op;
                Aldeano a;
                cin >> a;
                cout << "1) Agregar al inicio" << endl
                     << "2) Agregar al final" << endl
                     << "Opcion: ";
                cin >> op;
                if(op == 1){
                    agregarInicio(a);
                }
                else if(op == 2){
                    agregarFinal(a);
                }
                else{
                    cout << "Opcion no validad. No se agrego." << endl;
                }
                getch();
                break;
            }
            case 2:{
                int op;
                cout << "1) Eliminar por nombre" << endl
                     << "2) Eliminar por salud" << endl
                     << "3) Eliminar edad mayor igual 60" << endl
                     << "Opcion: ";
                cin >> op; cin.ignore();
                if(op == 1){
                    string bnombre;
                    cout << "Nombre: ";
                    getline(cin, bnombre);
                    eliminarNombre(bnombre);
                }
                else if(op == 2){
                    int bsalud;
                    cout << "Salud: ";
                    cin >> bsalud; cin.ignore();
                    eliminarSalud(bsalud);
                }
                else if(op == 3){
                    eliminarEdad();
                }
                else{
                    cout << "Opcion no valida." << endl;
                }
                getch();
                break;
            }
            case 6:
                mostrar();
                getch();
                break;
        }
    }while(opc != 0);
}