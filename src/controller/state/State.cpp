// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "controller/state/State.h"
#include "controller/state/MainMenuState.h"
#include "controller/state/PlayHumanState.h"
#include "controller/state/ChooseMachineState.h"
#include "controller/state/PlayMachineState.h"
#include "algorithm/Heuristics.h"
#include "algorithm/DepthFirstSearch.h"

MainMenuState      *State::mainMenuState      = nullptr;
PlayHumanState     *State::playHumanState     = nullptr;
ChooseMachineState *State::chooseMachineState = nullptr;
PlayMachineState   *State::playMachineState   = nullptr;

State::State(TerminalGUI *term): terminal(term) {
}

TerminalGUI *State::getTerminal() {
    return terminal;
}

void State::initializeStates(TerminalGUI *terminal) {
    mainMenuState      = new MainMenuState(terminal);
    playHumanState     = new PlayHumanState(terminal);
    chooseMachineState = new ChooseMachineState(terminal);
    playMachineState   = new PlayMachineState(terminal);
}
