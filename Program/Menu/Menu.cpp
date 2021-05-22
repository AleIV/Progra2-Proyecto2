//
// Created by aleja on 21/05/2021.
//

#include "Menu.h"

Menu::Menu() {}

Menu::~Menu() {

}

void Menu::MenuPrincipal() {
    cout << "Press 1" << "\n";
    int digit;
    cin >> digit;

    if(digit == 1){
        proxy->getAnalisis()->analisis1();
    }
}