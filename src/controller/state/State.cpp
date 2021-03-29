// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3


#include "controller/state/State.h"
#include "controller/state/MainMenuState.h"
#include "controller/state/PlayHumanState.h"
#include "controller/state/ChooseStrategyState.h"
#include "controller/state/ChooseHeuristicState.h"
#include "controller/state/ChooseHorizonState.h"
#include "controller/state/ChooseBaseHeuristicState.h"
#include "controller/state/ChooseFiniteHorizonHeuristicState.h"
#include "controller/state/ChooseHeuristicStrategyState.h"
#include "controller/state/PlayMachineState.h"

MainMenuState                     *State::mainMenuState                     = nullptr;
PlayHumanState                    *State::playHumanState                    = nullptr;
ChooseStrategyState               *State::chooseMachineState                = nullptr;
PlayMachineState                  *State::playMachineState                  = nullptr;
ChooseHeuristicState              *State::chooseHeuristicState              = nullptr;
ChooseHorizonState                *State::chooseHorizonState                = nullptr;
ChooseBaseHeuristicState          *State::chooseBaseHeuristicState          = nullptr;
ChooseFiniteHorizonHeuristicState *State::chooseFiniteHorizonHeuristicState = nullptr;
ChooseHeuristicStrategyState      *State::chooseHeuristicMachineState       = nullptr;

State::State(TerminalGUI *term): terminal(term) {
}

TerminalGUI *State::getTerminal() {
    return terminal;
}

State::~State() {
}

void State::initializeStates(TerminalGUI *terminal) {
    mainMenuState                     = new MainMenuState(terminal);
    playHumanState                    = new PlayHumanState(terminal);
    chooseMachineState                = new ChooseStrategyState(terminal);
    playMachineState                  = new PlayMachineState(terminal);
    chooseHeuristicState              = new ChooseHeuristicState(terminal);
    chooseHorizonState                = new ChooseHorizonState(terminal);
    chooseBaseHeuristicState          = new ChooseBaseHeuristicState(terminal);
    chooseFiniteHorizonHeuristicState = new ChooseFiniteHorizonHeuristicState(terminal);
    chooseHeuristicMachineState       = new ChooseHeuristicStrategyState(terminal);
}

void State::deleteStates() {
    delete mainMenuState;
    delete playHumanState;
    delete chooseMachineState;
    delete playMachineState;
    delete chooseHeuristicState;
    delete chooseHorizonState;
    delete chooseBaseHeuristicState;
    delete chooseFiniteHorizonHeuristicState;
    delete chooseHeuristicMachineState;
}
