// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "model/MainMenuModel.h"
#include "view/MainMenuView.h"
#include "controller/state/MainMenuState.h"

MainMenuState::MainMenuState(TerminalGUI *term) : State(term) {
}

State *MainMenuState::run() {
    MainMenuModel mainMenuModel;

    MainMenuView mainMenuView(mainMenuModel);
    mainMenuView.draw(*getTerminal());

    getTerminal()->display();

    return nullptr;
}
