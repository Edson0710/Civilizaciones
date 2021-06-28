#include "guerrero.h"

Guerrero::Guerrero(){}

void Guerrero::setId(size_t id){
    this -> id = id;
}

size_t Guerrero::getId(){
    return id;
}

void Guerrero::setSalud(size_t salud){
    this -> salud = salud;
}

size_t Guerrero::getSalud(){
    return salud;
}

void Guerrero::setFuerza(float fuerza){
    this -> fuerza = fuerza;
}

float Guerrero::getFuerza(){
    return fuerza;
}

void Guerrero::setEscudo(float escudo){
    this -> escudo = escudo;
}

float Guerrero::getEscudo(){
    return escudo;
}

void Guerrero::setTipo(const string &tipo){
    this -> tipo = tipo;
}

string Guerrero::getTipo(){
    return tipo;
}