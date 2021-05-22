//
// Created by aleja on 23/04/2021.
//

#ifndef LINKEDLIST_ITERATOR_H
#define LINKEDLIST_ITERATOR_H
#include "node.h"

template<class T>
class Iterator {

private:
    node<T> * target;

public:
    Iterator(node<T>*);
    virtual ~Iterator();
    T* getTarget();
    bool hasNext();

};

template<class T>
Iterator<T>::Iterator(node<T> *target){
    this->target = target;
}

template<class T>
Iterator<T>::~Iterator(){

}

template<class T>
T * Iterator<T>::getTarget() {
    T* e;
    if(hasNext()){
        e = target->getData();
        target = target->getNext();
        return e;
    }
    return nullptr;
}

template<class T>
bool Iterator<T>::hasNext() {
    return (target != nullptr);
}


#endif //LINKEDLIST_ITERATOR_H
