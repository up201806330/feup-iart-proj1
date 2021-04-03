// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "model/MainMenuModel.h"
#include "view/MainMenuView.h"
#include "controller/state/RandomizeForMachineState.h"
#include "controller/MenuController.h"

using namespace std;

RandomizeForMachineState::RandomizeForMachineState(TerminalGUI *term) : State(term) {}

State *RandomizeForMachineState::run() {
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

    return State::playMachineState;
}

RandomizeForMachineState::~RandomizeForMachineState() = default;
