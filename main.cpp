#include "videogame.h"
#include <conio.h>

int main(){
    int opc;
    Videogame v;
    do{
        system("cls");
        cout << "-- Usuario: " << v.getNombre() << " --" << endl;
        cout << "1) Nombre de usuario" << endl
             << "2) Agregar civilizacion" << endl
             << "3) Insertar civilizacion" << endl
             << "4) Crear civilizaciones" << endl
             << "5) Primera civilizacion" << endl
             << "6) Ultima civilizacion" << endl
             << "7) Ordenar" << endl
             << "8) Eliminar civilizacion" << endl
             << "9) Buscar" << endl
             << "10) Modificar" << endl
             << "11) Resumen" << endl
             << "12) Respaldar" << endl
             << "13) Recuperar" << endl
             << "0) Salir" << endl
             << "Opcion: ";
        cin >> opc; cin.ignore();
        switch (opc){
            case 1:{
                string nombre;
                cout << "Nombre del usuario: ";
                getline(cin, nombre);
                v.setNombre(nombre);
                getch();
                break;
            }
            case 2:{
                Civilizacion c;
                cin >> c;
                cin.ignore();
                v.agregarCivilizacion(c);
                getch();
                break;
            }
            case 3:{
                Civilizacion c;
                size_t pos;
                cin >> c;
                cout << "Posicion: ";
                cin >> pos; cin.ignore();
                if(pos > v.total()){
                    cout << "Posicion no valida" << endl;
                }
                else if(pos == v.total()){
                    v.agregarCivilizacion(c);
                }
                else{
                    v.insertar(c, pos);
                }
                getch();
                break;
            }
            case 4:{
                Civilizacion c;
                size_t n;
                cin >> c;
                cout << "Cantidad: ";
                cin >> n; cin.ignore();
                v.inicializar(c, n);
                getch();
                break;
            }
            case 5:{
                Civilizacion c;
                if(v.total() > 0){
                    v.encabezados();
                    c = v.primera();
                    cout << c;
                }
                else{
                    cout << "No hay civilizaciones." << endl;
                }
                getch();
                break;
            }
            case 6:{
                Civilizacion c;
                if(v.total() > 0){
                    v.encabezados();
                    c = v.ultima();
                    cout << c;
                }
                else{
                    cout << "No hay civilizaciones." << endl;
                }
                getch();
                break;
            }
            case 7:{
                int opc2;
                cout << "Ordenar por:" << endl 
                     << "1) Nombre" << endl
                     << "2) Ubicacion X" << endl
                     << "3) Ubicacion Y" << endl
                     << "4) Puntuacion" << endl
                     << "0) Volver" << endl
                     << "Opcion: ";
                cin >> opc2;
                switch(opc2){
                    case 1:
                        v.ordenarNombre();
                        break;
                    case 2:
                        v.ordenarUbicacionX();
                        break;
                    case 3:
                        v.ordenarUbicacionY();
                        break;
                    case 4:
                        v.ordenarPuntuacion();
                        break;
                    case 0:
                        break;
                    default:
                    cout << "Opcion no valida." << endl;
                        break;
                }
                getch();
                break;
            }
            case 8:{
                Civilizacion c;
                cin >> c; cin.ignore();
                v.eliminar(c);
                getch();
                break;
            }
            case 9:{
                Civilizacion c, *ptr;
                cin >> c; cin.ignore();
                v.buscar(c);
                getch();
                break;
            }
            case 10:{
                Civilizacion c;
                cin >> c; cin.ignore();
                v.modificar(c);
                getch();
                break;
            }
            case 11:
                v.resumen();
                getch();
                break;
            case 12:
                v.respaldar();
                cout << "Respaldo exitoso" << endl;
                getch();
                break;
            case 13:
                v.recuperar();
                cout << "Recuperacion exitosa" << endl;
                getch();
                break;
            case 0:
                break;
            default:
                cout << "Opcion no valida." << endl;
                getch();
                break;
        }
    }while(opc != 0);
    return 0;
}