//
// Created by aleja on 21/05/2021.
//

#include "Paciente.h"

Paciente::~Paciente() {

}

Paciente::Paciente(string nombre, string id, string secuencia) : nombre(nombre), id(id), secuencia(secuencia) {

}

string Paciente::getNombre()  {
    return nombre;
}

void Paciente::setNombre(string nombre) {
    Paciente::nombre = nombre;
}

string Paciente::getId()  {
    return id;
}

void Paciente::setId(string id) {
    id = id;
}

string Paciente::toString() {
    stringstream s;
    s << "NOMBRE: " << getNombre() << "\n";
    s << "ID: "<< getId() << "\n";
    s << "SECUENCIA: " << getSecuencia() << "\n";
    return s.str();
}


string Paciente::getSecuencia(){
    return secuencia;
}

void Paciente::setSecuencia(string secuencia) {
    secuencia = secuencia;
}
