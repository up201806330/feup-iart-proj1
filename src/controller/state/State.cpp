// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3


#include "controller/state/State.h"
#include "controller/state/MainMenuState.h"
#include "controller/state/PlayHumanState.h"
#include "controller/state/ChooseMachineState.h"
#include "controller/state/ChooseHeuristicState.h"
#include "controller/state/ChooseHorizonState.h"
#include "controller/state/ChooseBaseHeuristicState.h"
#include "controller/state/ChooseFiniteHorizonHeuristicState.h"
#include "controller/state/ChooseHeuristicMachineState.h"
#include "controller/state/PlayMachineState.h"

MainMenuState                     *State::mainMenuState                     = nullptr;
PlayHumanState                    *State::playHumanState                    = nullptr;
ChooseMachineState                *State::chooseMachineState                = nullptr;
PlayMachineState                  *State::playMachineState                  = nullptr;
ChooseHeuristicState              *State::chooseHeuristicState              = nullptr;
ChooseHorizonState                *State::chooseHorizonState                = nullptr;
ChooseBaseHeuristicState          *State::chooseBaseHeuristicState          = nullptr;
ChooseFiniteHorizonHeuristicState *State::chooseFiniteHorizonHeuristicState = nullptr;
ChooseHeuristicMachineState       *State::chooseHeuristicMachineState       = nullptr;

State::State(TerminalGUI *term): terminal(term) {
}

TerminalGUI *State::getTerminal() {
    return terminal;
}

void State::initializeStates(TerminalGUI *terminal) {
    mainMenuState                     = new MainMenuState(terminal);
    playHumanState                    = new PlayHumanState(terminal);
    chooseMachineState                = new ChooseMachineState(terminal);
    playMachineState                  = new PlayMachineState(terminal);
    chooseHeuristicState              = new ChooseHeuristicState(terminal);
    chooseHorizonState                = new ChooseHorizonState(terminal);
    chooseBaseHeuristicState          = new ChooseBaseHeuristicState(terminal);
    chooseFiniteHorizonHeuristicState = new ChooseFiniteHorizonHeuristicState(terminal);
    chooseHeuristicMachineState       = new ChooseHeuristicMachineState(terminal);
}
