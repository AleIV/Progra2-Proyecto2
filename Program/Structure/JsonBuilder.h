//
// Created by aleja on 28/04/2021.
//

#ifndef LINKEDLIST_JSONBUILDER_H
#define LINKEDLIST_JSONBUILDER_H

#include <iostream>
#include "LinkedList.h"
#include "../../dist/json/json.h"
#include "fstream"

using namespace std;

template<class T>
class JsonBuilder {

public:

    JsonBuilder();
    virtual ~JsonBuilder();

    //list to write, .json txt file
    void write(LinkedList<T>*,string);
    LinkedList<T>* rewrite(string);

};

template<class T>
JsonBuilder<T>::JsonBuilder() {

}

template<class T>
JsonBuilder<T>::~JsonBuilder() {

}

template<class T>
void JsonBuilder<T>::write(LinkedList<T>* listToWrite, string fileName) {
    ofstream output(fileName);

    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None"; //Set Estilo de comentarios
    builder["indentation"] = "      "; //Set para la tabulación
    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    Json::Value list(Json::arrayValue);

    T * P = nullptr;
    Iterator<T> * iter = listToWrite->getIterator();
    while(iter->hasNext()){
        P = iter->getTarget();

        Json::Value object = P->getAsJsonObject();
        list.append(object);
    }

    writer->write(list, &output);
    output.close();

}

template<class T>
LinkedList<T>* JsonBuilder<T>::rewrite(string fileName) {
    ifstream input(fileName);

    LinkedList<T>* list = new LinkedList<T>;

    Json::Value jsonList;
    Json::Reader reader;
    reader.parse(input, jsonList);

    for (int i = 0; i < jsonList.size(); ++i) {

        T* object = new T(jsonList[i]);
        list->add(object);

    }
    input.close();
    return list;
}


#endif //LINKEDLIST_JSONBUILDER_H
