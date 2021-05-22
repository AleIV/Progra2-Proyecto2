//
// Created by aleja on 22/04/2021.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

template<class T>
class node {
public:
    node(T* , node<T> *);
    virtual ~node();

    virtual void setData(T*);
    virtual T * getData() const;
    virtual void setNext(node<T>*);
    virtual node<T> * getNext() const;

private:
    T * data;
    node<T> * next;
};

template<class T>
node<T>::node(T* data, node<T> * next) : data(data), next(next){
    //same as this->data = data;
}

template<class T>
node<T>::~node(){
    delete data;
}

template<class T>
void node<T>::setData(T* data){
    this->data = data;
}

template<class T>
T * node<T>::getData() const{
    return data;
}

template<class T>
void node<T>::setNext(node<T>* next){
    this->next = next;
}

template<class T>
node<T> * node<T>::getNext() const{
    return next;
}


#endif //LINKEDLIST_NODE_H