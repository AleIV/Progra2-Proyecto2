//
// Created by aleja on 22/04/2021.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include "Iterator.h"

template<class T>

class LinkedList {

private:
    node<T> * first = nullptr;
    node<T> * last = nullptr;

public:
    LinkedList();
    virtual ~LinkedList();

    void add(T*);
    bool remove(T*);
    bool remove(int i);
    T* get(int i);
    int size();
    bool isEmpty();
    void clear();

    Iterator<T> * getIterator();

};

template<class T>
LinkedList<T>::LinkedList() {
    first = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
    node<T> * f = first;
    node<T> * aux;
    while(f != nullptr){
        aux = f->getNext();
        delete f;
        f = aux;
    }
    first = nullptr;
}

template<class T>
void LinkedList<T>::clear() {
    node<T> * current = first;
    first = nullptr;
    while(current != nullptr){
        node<T>* next = current->getNext();
        delete current;
        current = next;
    }
}

template<class T>
bool LinkedList<T>::remove(int index) {
     return remove(get(index));
}

template<class T>
bool LinkedList<T>::remove(T* data) {
    node<T> *temp = first;
    node<T> *previous;

    if (temp == nullptr) {
        return false;

    }else if (temp->getData() == data) {
        first = temp->getNext();
        temp = nullptr;
        delete temp;
        return true;

    }else {
        while (temp != nullptr) {
            previous = temp;
            temp = temp->getNext();

            if (temp == nullptr){
                return false;

            }else if(temp->getData() == data){
                previous->setNext(temp->getNext());
                temp = nullptr;
                delete temp;
                return true;
            }
        }
    }
}

template<class T>
T* LinkedList<T>::get(int index) {
    node<T> * current = first;

    int count = 0;
    while (current != nullptr)
    {
        if (count == index)
        {
            return current->getData();
        }

        count++;
        current = current->getNext();
    }

    return nullptr;
}

template<class T>
void LinkedList<T>::add(T * data) {

    node<T> * newNode = new node<T>(data, nullptr);

    if (first == nullptr)
    {
        first = newNode;
        last = first;
    }
    else
    {
        last->setNext(newNode);
        last = last->getNext();
    }

}

template<class T>
bool LinkedList<T>::isEmpty() {
    return first == nullptr;
}

template<class T>
int LinkedList<T>::size() {

    if(isEmpty()) return 0;

    Iterator<T> * iter = getIterator();
    int count = 0;
    while(iter->hasNext()){
        iter->getTarget();
        count++;
    }

    return count;
}

template<class T>
Iterator<T> * LinkedList<T>::getIterator() {
    return new Iterator<T>(first);
}

#endif //LINKEDLIST_LINKEDLIST_H
