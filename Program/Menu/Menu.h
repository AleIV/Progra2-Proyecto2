//
// Created by aleja on 21/05/2021.
//

#ifndef LINKEDLIST_MENU_H
#define LINKEDLIST_MENU_H
#include "../Proxy.h"

class Menu {
private:
    Proxy * proxy = new Proxy();
public:
    Menu();

    virtual ~Menu();

    void MenuPrincipal();
};


#endif //LINKEDLIST_MENU_H
