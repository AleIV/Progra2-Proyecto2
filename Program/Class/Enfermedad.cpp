//
// Created by aleja on 21/05/2021.
//

#include "Enfermedad.h"

Enfermedad::~Enfermedad() {

}

Enfermedad::Enfermedad(string nombre, string secuencia) : nombre(nombre) , secuencia(secuencia){

}

string Enfermedad::getNombre()  {
    return nombre;
}

void Enfermedad::setNombre( string nombre) {
    Enfermedad::nombre = nombre;
}

string Enfermedad::getSecuencia()  {
    return secuencia;
}

void Enfermedad::setSecuencia( string secuencia) {
    Enfermedad::secuencia = secuencia;
}

string Enfermedad::toString() {
    stringstream s;
    s << "NOMBRE: " << getNombre() << "\n";
    s << "SECUENCIA: " << getSecuencia() << "\n";
    return s.str();
}

Json::Value Enfermedad::getAsJsonObject() {
    Json::Value object;
    object["nombre"] = getNombre();
    object["secuencia"]= getSecuencia();
    return object;
}

Enfermedad::Enfermedad (Json::Value object) {
    this->nombre = object["nombre"].asString();
    this->secuencia = object["secuencia"].asString();
}