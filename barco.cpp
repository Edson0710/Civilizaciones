#include "barco.h"

Barco::Barco(){
    velocidad = 0.0;
    armadura = 100.0;
}

void Barco::setId(size_t id){
    this -> id = id;
}

size_t Barco::getId(){
    return id;
}

void Barco::setCombustible(float combustible){
    this -> combustible = combustible;
}

float Barco::getCombustible(){
    return combustible;
}

void Barco::setVelocidad(float velocidad){
    this -> velocidad = velocidad;
}
float Barco::getVelocidad(){
    return velocidad;
}

void Barco::setArmadura(float armadura){
    this -> armadura = armadura;
}

float Barco::getArmadura(){
    return armadura;
}

//  Stack
void Barco::agregarGuerrero(Guerrero &g){
    pila.push(g);
}

void Barco::eliminarGuerrero(){
    pila.pop();
}

Guerrero Barco::tope(){
    return pila.top();
}

void Barco::mostrar(){
    stack<Guerrero> copia(pila);
    while(!copia.empty()){
        auto const &e = copia.top();
        cout << e << endl;
        copia.pop();
    }
}

bool Barco::vacia(){
    if(pila.empty()){
        return true;
    }
    else{
        return false;
    }
}