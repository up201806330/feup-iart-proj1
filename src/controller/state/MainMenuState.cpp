// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <iostream>
#include "model/MainMenuModel.h"
#include "view/MainMenuView.h"
#include "controller/state/MainMenuState.h"
#include "controller/MenuController.h"

using namespace std;

MainMenuState::MainMenuState(TerminalGUI *term) : State(term) {
}

State *MainMenuState::run() {
    MainMenuModel mainMenuModel;
    MainMenuView mainMenuView(mainMenuModel);
    MenuController mainMenuController(mainMenuModel);

    cerr << "L20" << endl;

    int option = -1;
    do {
        getTerminal()->clear();
        mainMenuView.draw(*getTerminal());
        getTerminal()->display();
        cerr << "Drew main menu" << endl;
        mainMenuController.run();
        option = mainMenuController.getSelectedOption();
    } while(!(1 <= option && option <= int(mainMenuModel.getButtons().size())));

    cerr << "L32" << endl;

    State *ret;
    switch(option){
        case 1: ret = State::playHumanState; break;
        case 2: ret = nullptr; break;
        case 3: ret = nullptr; break;
        case 4: ret = nullptr; break;
        default: throw logic_error("");
    }
    return ret;
}
