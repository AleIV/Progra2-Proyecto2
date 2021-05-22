//
// Created by aleja on 21/05/2021.
//

#ifndef LINKEDLIST_PROXY_H
#define LINKEDLIST_PROXY_H
#include "Structure/JsonBuilder.h"
#include "Class/Paciente.h"
#include "Class/Enfermedad.h"
#include "Analisis.h"

class Proxy {

private:
    LinkedList<Paciente>* pacientes;
    LinkedList<Enfermedad>* enfermedades;

    JsonBuilder<Enfermedad>* enfermedadBuilder;

    Analisis* analisis;

public:
    Proxy();
    virtual ~Proxy();

    LinkedList<Paciente> *getPacientes() const;
    LinkedList<Enfermedad> *getEnfermedades() const;

    Analisis *getAnalisis() const;
    JsonBuilder<Enfermedad> *getEnfermedadBuilder() const;
};


#endif //LINKEDLIST_PROXY_H
