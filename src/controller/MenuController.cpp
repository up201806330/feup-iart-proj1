// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <iostream>
#include <sstream>
#include "controller/MenuController.h"

using namespace std;

MenuController::MenuController(const MenuModel &menuModel):_menuModel(menuModel){
}

void MenuController::run() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> selectedOption;
    if(ss.fail()) selectedOption = -1;
}

int MenuController::getSelectedOption() {
    return selectedOption;
}
