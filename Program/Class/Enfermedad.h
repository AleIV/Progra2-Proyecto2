//
// Created by aleja on 21/05/2021.
//

#ifndef LINKEDLIST_ENFERMEDAD_H
#define LINKEDLIST_ENFERMEDAD_H

#include "../Structure/JsonBuilder.h"

class Enfermedad {
private:
    string nombre;
    string secuencia;

public:
    virtual ~Enfermedad();
    Enfermedad(string, string);
    string getNombre() ;
    string getSecuencia() ;
    void setSecuencia(string);
    void setNombre(string);
    string toString();

    Enfermedad(Json::Value);
    Json::Value getAsJsonObject();
};


#endif //LINKEDLIST_ENFERMEDAD_H
