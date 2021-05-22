//
// Created by aleja on 21/05/2021.
//

#ifndef LINKEDLIST_PACIENTE_H
#define LINKEDLIST_PACIENTE_H

#include "sstream"
using namespace std;

class Paciente {
private:
    string nombre;
    string id;
    string secuencia;

public:

    virtual ~Paciente();
    Paciente(string, string, string);
    string getNombre();
    string getId();
    void setId(string);
    void setNombre(string);
    string toString();
    string getSecuencia() ;
    void setSecuencia(string);

};


#endif //LINKEDLIST_PACIENTE_H
