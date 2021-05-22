//
// Created by aleja on 21/05/2021.
//

#include "Analisis.h"

Analisis::Analisis(LinkedList<Paciente>* pacientes, LinkedList<Enfermedad>* enfermedades) {
    this->pacientes = pacientes;
    this->enfermedades = enfermedades;
}

Analisis::~Analisis() {

}

void Analisis::analisis1() {

    LinkedList<Paciente>* pacientes = this->pacientes;
    LinkedList<Enfermedad>* enfermedades = this->enfermedades;

    pacientes->add(new Paciente("VALERIA", "123", "TCGGCGTATAGCTAACTTGCAGGGACGGCTGGGCCCACGTTGCAACTCCTAGATGGCTGGCATCCTCTGAGGTTTGCACTCTAACGTGTCACCGTACTCGATAATCACGTCCTACACCCCCGCTTAGAAGGATAATCTCTAACGGACAAACAGGTGTCACATCATAAAATGTTCGGAAAGACAACTGTGCGATGTAGATGATTGGAACGTCGTTCCGAGCAAGGTTTTTACTAATACCCACCGTTACCCATCGCGAAGCTAGCGTTTGACATGATGTTGTCACTACCTAACCACATGCTGATGTTATCAGTCCAAGTCTGCTGGGCCAGCTCTCCAACAATAAGGCTTTAGATTTACTTCCCTCGCCCCAGTAAGGCTTCGCGGGGGAGCGACGTAGTCC"));
    pacientes->add(new Paciente("ALE", "321", "GACGTGAGAACGACCGCTTCGCGGAATTACCGGCATTGTGAGCTCGGCAGCCCGGACATCCCTCGTACGTCACAGGTGAGTACCATACCCTGTCACCCGGGGGTCTTGAATGTCAAGTAAGGGTGTTGGACTATGCCTGCAACCTGCCTGTCGTCTTAACTAGAGTCATGCCCGCTGTCACTTAGTCCGACGTTCTAACCTTGGCCGGCTTCGATTTCAATTTCACCGGTCGGTAGCATGCTTCCGCTACCGCAAAGCTCACCGAATGTTATTTCGCGGATATGACTTCACGGTACAGCTGGTTTCCGGCGATGCTTAGTTCCCTGGAAAACTACAAAGTTATATAAGTGCACTTCGGCCAGAATACGTAGCTTATAGAAACCTATTTGGTTCTAAGTGA"));
    pacientes->add(new Paciente("GABRIELASO", "345", "AAACCGCAGGTCCCCACATTGTCTGAACTAGTCTAGGCGGAATGATCACGTGTTTGGCAAGTACTTCATGAGTCCGCTTTCAGAAGAATCGAGCACCGAGCGCTCAGGTCAAAAAGGCACCGGACATAGCCCGCACACTGCCAACGACTTAGCGGATGGCCTAGTCGCGTGACCGGTGTGGGTGGCATACTCCCACTGCTGCGGTTCGGATCTACCCTCCCGCATTAACACACGAGAGTAACGTGTGTAGTGGTAAATCACCCCAGATAGGAAGTCCGGTCTGCTGGCAGTTCACTACCTTTCCTCCAATGTTTGATTCTCGGGGCTCTATCCAGAACGACCCATCACCTGTGTGTTACAGAGAGTTCTAGCAGAAACGACGGGGTGGCACGACTTTGGG"));

    stringstream s;
    Paciente * P;

    Iterator<Paciente> * iter1 = pacientes->getIterator();
    while(iter1->hasNext()){
        P = iter1->getTarget();
        s << "PACIENTE: "<< P->getNombre() << " ID: " << P->getId() << "\n";
        s << "Susceptibilidad a las enfermedades:" << "\n";

        string find = P->getSecuencia();

        Enfermedad * E;

        Iterator<Enfermedad> * iter2 = enfermedades->getIterator();
        while(iter2->hasNext()){
            E = iter2->getTarget();

            string search = E->getSecuencia();

            if (find.find(search) != std::string::npos)

                s << "- " << E->getNombre() << "\n";

        }
        delete iter2;
        s << "\n";


    }
    delete iter1;

    cout << s.str();
}

void Analisis::analisis2() {
    stringstream s;
    Paciente * P;

    Iterator<Paciente> * iter1 = pacientes->getIterator();
    while(iter1->hasNext()){
        P = iter1->getTarget();
        s << endl<<"PACIENTE: "<< P->getNombre() << " ID: " << P->getId() << "\n";

        int G = 0;
        int C = 0;
        int T = 0;
        int A = 0;

        char* char_arr;
        string secuencia = P->getSecuencia();
        char_arr = &secuencia[0];

        for(int i = 0; char_arr[i] ; i++){
            char item = char_arr[i];

            if(item == 'G'){
                G++;
            }else if(item == 'C'){
                C++;
            }else if(item == 'T'){
                T++;
            }else if(item == 'A'){
                A++;
            }

        }

        float total = (G+C+T+A);

        s << "G: "<< (100/total) *G <<"%"<<endl;
        s << "C: "<< (100/total) *C <<"%"<<endl;
        s << "T: "<< (100/total) *T <<"%"<<endl;
        s << "A: "<< (100/total) *A <<"%"<<endl;
        s << "\n";

    }
    delete iter1;

    cout << s.str();
}

/*
void Analisis::analisis3() {
    JsonBuilder<PacienteAnalisis> *builder = new JsonBuilder<PacienteAnalisis>;

    Lista<PacienteAnalisis> *list = new Lista<PacienteAnalisis>;

    Pacientes *p;
    Iterador<Pacientes> *iter = pacientes->getIterador();
    while (iter->hasNext()) {

        stringstream s;

        p = iter->getObjetivo();

        string find = p->getSecuenciaAdn();

        Enfermedad *E;
        int count = 0;

        Iterador<Enfermedad> *iter = enfermedades->getIterador();
        while (iter->hasNext()) {
            E = iter->getObjetivo();

            string search = E->getSecuencia();

            if (find.find(search) != std::string::npos) {
                s << "- " << E->getNombre() << "\n";
                count++;
            }
        }
        cout << "aa";
        if (count >= 2) {

            if (count == 2) {
                cout << "p2";
                list->agregar(new PacienteAnalisis(p, 40, count, s.str()));

            } else {
                cout << "p3";
                list->agregar(new PacienteAnalisis(p, 70, count, s.str()));
            }
        }
        cout << "CERO\n";
        delete iter;

        if (!list->vacio()) {

            builder->write(list, "Analisis3.json");
        }

    }
}*/