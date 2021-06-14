#include "videogame.h"

Videogame::Videogame(){
    nombre = "Sin usuario";
}

void Videogame::setNombre(const string &v){
    nombre = v;
}
string Videogame::getNombre(){
    return nombre;
}

void Videogame::agregarCivilizacion(const Civilizacion &c){
    civ.push_back(c);
}

void Videogame::encabezados(){
    cout << left;
    cout << setw(20) << "NOMBRE";
    cout << setw(6) << "UBI_X";
    cout << setw(6) << "UBI_Y";
    cout << setw(6) << "PTS" << endl;
}

void Videogame::resumen(){
    encabezados();
    for(size_t i = 0; i < civ.size(); i++){
        Civilizacion &c = civ[i];
        cout << c;
    }
}

void Videogame::insertar(const Civilizacion &c, size_t pos){
    civ.insert(civ.begin()+pos, c);
}

void Videogame::inicializar(const Civilizacion &c, size_t n){
    civ = vector<Civilizacion>(n, c);
}

Civilizacion Videogame::primera(){
    return civ.front();
}

Civilizacion Videogame::ultima(){
    return civ.back();
}

void Videogame::ordenarNombre(){
    sort(civ.begin(), civ.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getNombre() < c2.getNombre();});
}

void Videogame::ordenarUbicacionX(){
    sort(civ.begin(), civ.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionX() < c2.getUbicacionX();});
}

void Videogame::ordenarUbicacionY(){
    sort(civ.begin(), civ.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionY() < c2.getUbicacionY();});
}

void Videogame::ordenarPuntuacion(){
    sort(civ.begin(), civ.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

void Videogame::buscar(const Civilizacion &c){
    auto it = find(civ.begin(), civ.end(), c);
    if (it != civ.end()){
        encabezados();
        cout << *it;
        Civilizacion &c = *it;
        c.menu();
    }
    else{
        cout << "No encontrado." << endl;
    }
}

void Videogame::eliminar(const Civilizacion &c){
    auto it = find(civ.begin(), civ.end(), c);
    if(it != civ.end()){
        int index = it - civ.begin();
        civ.erase(civ.begin()+index);
        cout << "Eliminado con exito" << endl;
    } 
    else{
        cout << "No encontrado." << endl;
    }
}

void Videogame::modificar(const Civilizacion &c){
    int opc, ubicacion_x, ubicacion_y, puntuacion;
    string nombre;
    auto it = find(civ.begin(), civ.end(), c);
    if(it != civ.end()){
        int index = it - civ.begin();
        encabezados();
        cout << civ[index];
        cout << "1) Nombre" << endl
             << "2) Ubicacion X" << endl
             << "3) Ubicacion Y" << endl
             << "4) Puntuacion" << endl
             << "Modificar: ";
        cin >> opc; cin.ignore();
        if(opc == 1){
            cout << "nuevo Nombre: ";
            getline(cin, nombre);
            civ[index].setNombre(nombre);
        }
        else if(opc == 2){
            cout << "nueva Ubicacion X: ";
            cin >> ubicacion_x; cin.ignore();
            civ[index].setUbicacionX(ubicacion_x);
        }
        else if(opc == 3){
            cout << "nueva Ubicacion Y: ";
            cin >> ubicacion_y; cin.ignore();
            civ[index].setUbicacionY(ubicacion_y);
        }
        else if(opc == 4){
            cout << "nueva Puntuacion: ";
            cin >> puntuacion; cin.ignore();
            civ[index].setPuntuacion(puntuacion);
        }
        else{
            cout << "Opcion no valida" << endl;
        }
    } 
    else{
        cout << "No encontrado." << endl;
    }
}

size_t Videogame::total(){
    return civ.size();
}

void Videogame::respaldar()
{   
    ofstream archivo("respaldos/civilizaciones.txt", ios::out);

    for (int i = 0; i < civ.size(); ++i) {
        Civilizacion &c = civ[i];
        archivo << c.getNombre() << endl;
        c.respaldar_aldeanos();
    }
    archivo.close();
}

void Videogame::recuperar(){
    ifstream archivo("respaldos/civilizaciones.txt");
    if(archivo.is_open()){
        while (true){
            Civilizacion c;
            string temp;
            getline(archivo, temp); 
            if(archivo.eof()){
                break;
            }
            c.setNombre(temp);
            c.recuperar_aldeanos();
            agregarCivilizacion(c);
        }
        
    }
    archivo.close();
}