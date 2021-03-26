// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

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

    int option;
    do {
        getTerminal()->clear();
        mainMenuView.draw(*getTerminal());
        getTerminal()->display();
        mainMenuController.run();
        option = mainMenuController.getSelectedOption();
    } while(!(1 <= option && option <= int(mainMenuModel.getButtons().size())));

    State *ret;
    switch(option){
        case 1: ret = State::playHumanState  ; break;
        case 2: ret = State::playMachineState; break;
        case 3:
        case 4: ret = nullptr; break;
        default: throw logic_error("");
    }
    return ret;
}
