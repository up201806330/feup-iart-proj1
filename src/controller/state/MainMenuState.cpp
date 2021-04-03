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

    int id;
    do {
        getTerminal()->clear();
        mainMenuView.draw(*getTerminal());
        getTerminal()->display();
        mainMenuController.run();
        id = mainMenuController.getSelectedOption();
    } while(!mainMenuModel.hasButtonWithId(id));

    State *ret;
    switch(id){
        case 1: ret = State::randomizeForHumanState; break;
        case 2: ret = State::randomizeForMachineState; break;
        case 3: ret = State::aboutState        ; break;
        case 0: ret = nullptr; break;
        default: throw logic_error("");
    }
    return ret;
}

MainMenuState::~MainMenuState() = default;
