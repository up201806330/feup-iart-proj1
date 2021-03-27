// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "controller/state/State.h"
#include "controller/state/MainMenuState.h"
#include "controller/state/PlayHumanState.h"
#include "controller/state/PlayMachineState.h"
#include "algorithm/GreedySearch.h"
#include "algorithm/Heuristics.h"

State *State::mainMenuState    = nullptr;
State *State::playHumanState   = nullptr;
State *State::playMachineState = nullptr;

State::State(TerminalGUI *term): terminal(term) {
}

TerminalGUI *State::getTerminal() {
    return terminal;
}

void State::initializeStates(TerminalGUI *terminal) {
    mainMenuState  = new MainMenuState(terminal);
    playHumanState = new PlayHumanState(terminal);

    Search *search = new GreedySearch(Heuristics::h1);
    playMachineState = new PlayMachineState(terminal, search);
}
