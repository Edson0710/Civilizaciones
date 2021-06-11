#include "aldeano.h"

void Aldeano::setNombre(const string &nombre){
    this -> nombre = nombre;
}

string Aldeano::getNombre(){
    return nombre;
}

void Aldeano::setEdad(size_t edad){
    this -> edad = edad;
}

size_t Aldeano::getEdad() const{
    return edad;
}

void Aldeano::setGenero(char genero){
    this -> genero = genero;
}

char Aldeano::getGenero(){
    return genero;
}

void Aldeano::setSalud(int salud){
    this -> salud = salud;
}

int Aldeano::getSalud() const{
    return salud;
}