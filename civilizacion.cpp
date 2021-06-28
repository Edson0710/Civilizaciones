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

void Civilizacion::encabezadosBarcos(){
    cout << left;
    cout << setw(4) << "ID";
    cout << setw(6) << "FUEL";
    cout << setw(6) << "VEL";
    cout << setw(6) << "ARMOR";
    cout << setw(6) << "GRRS" << endl;
}

void Civilizacion::encabezadosGuerreros(){
    cout << left;
    cout << setw(4) << "ID";
    cout << setw(6) << "SALD";
    cout << setw(6) << "FRZA";
    cout << setw(6) << "ESCD";
    cout << setw(6) << "TIPO" << endl;
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

void Civilizacion::agregarBarco(Barco *b){
     puerto.push_back(b);
}

void Civilizacion::capturarBarco(){
    size_t id;
    double combustible;
    Barco *b = new Barco();

    cout << "Id: ";
    cin >> id;
    b -> setId(id);

    cout << "Combustible: ";
    cin >> combustible;
    b -> setCombustible(combustible);

    agregarBarco(b);
}

void Civilizacion::mostrarBarcos(){
    encabezadosBarcos();
    for(auto const &e : puerto){
        cout << *e << endl;
    }
}

void Civilizacion::capturarGuerrero(Barco &b){
    size_t id, salud, tipo;
    float fuerza, escudo;
    Guerrero g;
    cout << "Id: ";
    cin >> id;
    g.setId(id);
    cout << "Salud: ";
    cin >> salud;
    g.setSalud(salud);
    cout << "Fuerza: ";
    cin >> fuerza;
    g.setFuerza(fuerza);
    cout << "Escudo: ";
    cin >> escudo;
    g.setEscudo(escudo);
    cout << "1.lancero\t2.arquero\t3.paladin\t4.caballero\nTipo: ";
    cin >> tipo;
    if(tipo == 1){g.setTipo("lancero");}
    else if(tipo == 2){g.setTipo("arquero");}
    else if(tipo == 3){g.setTipo("paladin");}
    else if(tipo == 4){g.setTipo("caballero");}
    else{cout<<"Opcion no valida, no se agrega."; getch(); return;}
    b.agregarGuerrero(g);
}

void Civilizacion::eliminarGuerrero(Barco &b){
    b.eliminarGuerrero();
}

void Civilizacion::ultimoGuerrero(Barco &b){
    encabezadosGuerreros();
    cout << b.tope();
}

void Civilizacion::mostrarGuerreros(Barco &b){
    encabezadosGuerreros();
    b.mostrar();
}

void Civilizacion::buscarBarco(size_t id){
    int opc;
    auto it = puerto.begin();
    for(it; it != puerto.end(); it++){
        Barco &b = **it;
        if(id == b.getId()){
            encabezadosBarcos();
            cout << b;
            cout << endl;
            cout << "1) Agregar guerrero" << endl
                 << "2) Eliminar guerrero" << endl
                 << "3) Mostrar ultimo guerrero" << endl
                 << "4) Mostrar guerreros" << endl
                 << "Opcion: ";
            cin >> opc; cin.ignore();
            if(opc == 1){
                capturarGuerrero(b);
            }
            else if(opc == 2){
                if(!b.vacia()){
                    eliminarGuerrero(b);
                    cout << "Guerrero eliminado" << endl;
                }
                else{
                    cout << "No hay elementos en la pila" << endl;
                }
            }
            else if(opc == 3){
                if(!b.vacia()){
                    ultimoGuerrero(b);
                }
                else{
                    cout << "No hay elementos en la pila" << endl;
                }
            }
            else if(opc == 4){
                mostrarGuerreros(b);
            }
            else{
                cout << "Opcion no valida" << endl;
            }
            break;
        }
    }
    if(it == puerto.end()){
        cout << "No se ha encontrado el barco" << endl;
    }
}

void Civilizacion::eliminarBarcoId(size_t id){
    puerto.remove_if([id](Barco* b){
        if(b->getId() == id){
            delete b;
            cout << "Barco eliminado" << endl;
            return true;
        }
        else{
            return false;
        }
    });
}

void Civilizacion::eliminarBarcoCombustible(float combustible){
    puerto.remove_if([combustible](Barco* b){
        if(b->getCombustible() < combustible){
            delete b;
            cout << "Barco eliminado" << endl;
            return true;
        }
        else{
            return false;
        }
    });
}

void Civilizacion::menuBarcos(){
    int opc;
        do{
        system("cls");
            cout << "Menu Barcos " << endl
                << "1) Agregar Barco" << endl
                << "2) Mostrar Barcos" << endl
                << "3) Buscar Barcos" << endl
                << "4) Eliminar por id" << endl
                << "5) Eliminar por combustible" << endl
                << "0) salir" << endl
                << "Opcion: ";
            cin >> opc; cin.ignore();
            switch(opc){
                case 1:
                    capturarBarco();
                    getch();
                    break;
                case 2:
                    mostrarBarcos();
                    getch();
                    break;
                case 3:{
                    size_t id;
                    cout << "Id del barco a buscar: ";
                    cin >> id;
                    buscarBarco(id);
                    getch();
                    break;
                case 4:{
                    size_t id;
                    cout << "Id del barco a eliminar: ";
                    cin >> id;
                    eliminarBarcoId(id);
                    getch();
                    break;
                }
                case 5:{
                    float combustible;
                    cout << "Eliminar barcos con combustible menor a: ";
                    cin >> combustible;
                    eliminarBarcoCombustible(combustible);
                    getch();
                    break;
                }
                }
            }
    }while(opc != 0);
}

void Civilizacion::menu(){
    int opc;
    getch();
    do{
        system("cls");
        cout << "Menu de " << getNombre() << ": " << endl
            << "1) Agregar aldeano" << endl
            << "2) Eliminar aldeano" << endl
            << "3) Clasificar aldeanos" << endl
            << "4) Buscar aldeano" << endl
            << "5) Modificar aldeano" << endl
            << "6) Mostrar aldeanos" << endl
            << "7) Administrar barcos" << endl
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
            case 7:
                menuBarcos();
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

