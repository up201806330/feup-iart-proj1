// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "controller/state/State.h"
#include "controller/state/MainMenuState.h"

State *State::mainMenuState = nullptr;

State::State(TerminalGUI *term): terminal(term) {
}

TerminalGUI *State::getTerminal() {
    return terminal;
}

void State::initializeStates(TerminalGUI *terminal) {
    mainMenuState = new MainMenuState(terminal);
}
