//
// Created by aleja on 21/05/2021.
//

#ifndef LINKEDLIST_ANALISIS_H
#define LINKEDLIST_ANALISIS_H
#include "Structure/JsonBuilder.h"
#include "Class/Paciente.h"
#include "Class/Enfermedad.h"

class Analisis {
private:
    LinkedList<Paciente>* pacientes;
    LinkedList<Enfermedad>* enfermedades;

public:
    virtual ~Analisis();
    Analisis(LinkedList<Paciente>*, LinkedList<Enfermedad>*);

    void analisis1();
    void analisis2();
    void analisis3();

};


#endif //LINKEDLIST_ANALISIS_H
