#include "civilizacion.h"
#include <conio.h>

Civilizacion::Civilizacion(){
    puntuacion = 0;
    ubicacion_x = 0;
    ubicacion_y = 0;
}

Civilizacion::Civilizacion(const string &nombre, int ubicacion_x, int ubicacion_y, int puntuacion){
    this -> nombre = nombre;
    this -> ubicacion_x = ubicacion_x;
    this -> ubicacion_y = ubicacion_y;
    this -> puntuacion = puntuacion;
}

void Civilizacion::encabezados(){
    cout << left;
    cout << setw(20) << "NOMBRE";
    cout << setw(6) << "EDAD";
    cout << setw(6) << "SEXO";
    cout << setw(6) << "SALUD" << endl;
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
            cout << "Eliminado" << endl;
            break;
        }
    }
}

void Civilizacion::eliminarSalud(int salud){
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
    cout << "Eliminados" << endl;
}

void Civilizacion::mostrar(){
    encabezados();
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

bool comparador(const Aldeano &a){
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad(){
    aldeanos.remove_if(comparador);
    cout << "Eliminados" << endl;
}

void Civilizacion::ordenarNombre(){
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getNombre() < a2.getNombre();});
}

void Civilizacion::ordenarEdad(){
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() > a2.getEdad();});
}

void Civilizacion::ordenarSalud(){
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

void Civilizacion::buscar(const string &nombre){
    auto it = aldeanos.begin();
    for(it; it != aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()){
            encabezados();
            cout << *it;
            break;
        }
    }
    if(it == aldeanos.end()){
        cout << "No se ha encontrado el aldeano" << endl;
    }
}

void Civilizacion::modificar(const string &nombre){
    int opc, salud;
    string mnombre;
    char genero;
    size_t edad;
    auto it = aldeanos.begin();
    for(it; it != aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()){
            encabezados();
            cout << *it;
            cout << endl;
            cout << "1) Nombre" << endl
                 << "2) Edad" << endl
                 << "3) Genero" << endl
                 << "4) Salud" << endl
                 << "Modificar: ";
            cin >> opc; cin.ignore();
            if(opc == 1){
                cout << "nuevo Nombre: ";
                getline(cin, mnombre);
                a.setNombre(mnombre);
            }
            else if(opc == 2){
                cout << "nueva Edad: ";
                cin >> edad; cin.ignore();
                a.setEdad(edad);
            }
            else if(opc == 3){
                cout << "nuevo Genero: ";
                cin >> genero; cin.ignore();
                a.setGenero(genero);
            }
            else if(opc == 4){
                cout << "nueva Salud: ";
                cin >> salud; cin.ignore();
                a.setSalud(salud);
            }
            else{
                cout << "Opcion no valida" << endl;
            }
            break;
        }
    }
    if(it == aldeanos.end()){
        cout << "No se ha encontrado el aldeano" << endl;
    }
}


void Civilizacion::menu(){
    int opc;
    getch();
    do{
        system("cls");
        cout << "Aldeanos de " << getNombre() << ": " << endl
            << "1) Agregar aldeano" << endl
            << "2) Eliminar aldeano" << endl
            << "3) Clasificar aldeanos" << endl
            << "4) Buscar aldeano" << endl
            << "5) Modificar aldeano" << endl
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
            case 3:{
                int op;
                cout << "1) Por nombre" << endl
                     << "2) Por edad" << endl
                     << "3) Por salud" << endl
                     << "Opcion: ";
                cin >> op; cin.ignore();
                if(op == 1){
                    ordenarNombre();
                    cout << "Ordenado por nombre" << endl;
                }
                else if(op == 2){
                    ordenarEdad();
                    cout << "Ordenado por edad" << endl;
                }
                else if(op == 3){
                    ordenarSalud();
                    cout << "Ordenado por salud" << endl;
                }
                else{
                    cout << "Opcion no valida." << endl;
                }
                getch();
                break;
            }
            case 4:{
                string bnombre;
                cout << "Nombre: ";
                getline(cin, bnombre);
                buscar(bnombre);
                getch();
                break;
            } 
            case 5:{
                string bnombre;
                cout << "Nombre: ";
                getline(cin, bnombre);
                modificar(bnombre);
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

void Civilizacion::respaldar_aldeanos(){
    ofstream archivo("respaldos/" + getNombre() + ".txt", ios::out);

    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;
        archivo << a.getNombre() << endl;
        archivo << a.getEdad() << endl;
        archivo << a.getGenero() << endl;
        archivo << a.getSalud() << endl;
    }
    archivo.close();
}

void Civilizacion::recuperar_aldeanos(){
    ifstream archivo("respaldos/" + getNombre() + ".txt");
    if(archivo.is_open()){
        while (true){
            Aldeano a;
            string temp;
            int tempInt;
            getline(archivo, temp);  // Nombre
            a.setNombre(temp);
            if(archivo.eof()){
                break;
            }
            getline(archivo,temp);  // Edad
            tempInt = stoi(temp);
            a.setEdad(tempInt);
            getline(archivo, temp); // Genero
            a.setGenero(temp[0]);
            getline(archivo, temp); // Salud
            tempInt = stoi(temp);
            a.setSalud(tempInt);
            agregarFinal(a);
        }
        
    }
    archivo.close();
}

