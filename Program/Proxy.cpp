//
// Created by aleja on 21/05/2021.
//

#include "Proxy.h"

Proxy::Proxy() {
    this->enfermedadBuilder = new JsonBuilder<Enfermedad>;
    this->enfermedades = enfermedadBuilder->rewrite("Enfermedades.json");
    this->pacientes = new LinkedList<Paciente>;

    this->analisis = new Analisis(pacientes, enfermedades);
}

Proxy::~Proxy() {
    delete pacientes;
    delete enfermedades;

    delete enfermedadBuilder;

    delete analisis;
}

LinkedList<Paciente> *Proxy::getPacientes() const {
    return pacientes;
}

LinkedList<Enfermedad> *Proxy::getEnfermedades() const {
    return enfermedades;
}

Analisis *Proxy::getAnalisis() const {
    return analisis;
}

JsonBuilder<Enfermedad> *Proxy::getEnfermedadBuilder() const {
    return enfermedadBuilder;
}
