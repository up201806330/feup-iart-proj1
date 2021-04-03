// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "controller/state/State.h"

MainMenuState                     *State::mainMenuState                     = nullptr;
PlayHumanState                    *State::playHumanState                    = nullptr;
ChooseStrategyState               *State::chooseMachineState                = nullptr;
PlayMachineState                  *State::playMachineState                  = nullptr;
ChooseHeuristicState              *State::chooseHeuristicState              = nullptr;
ChooseHorizonState                *State::chooseHorizonState                = nullptr;
ChooseBaseHeuristicState          *State::chooseBaseHeuristicState          = nullptr;
ChooseFiniteHorizonHeuristicState *State::chooseFiniteHorizonHeuristicState = nullptr;
ChooseFactorState                 *State::chooseFactorState                 = nullptr;
ChooseHeuristicStrategyState      *State::chooseHeuristicMachineState       = nullptr;
RandomizeForHumanState            *State::randomizeForHumanState            = nullptr;
RandomizeForMachineState          *State::randomizeForMachineState          = nullptr;
AboutState                        *State::aboutState                        = nullptr;

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
    chooseFactorState                 = new ChooseFactorState(terminal);
    chooseHeuristicMachineState       = new ChooseHeuristicStrategyState(terminal);
    randomizeForHumanState            = new RandomizeForHumanState(terminal);
    randomizeForMachineState          = new RandomizeForMachineState(terminal);
    aboutState                        = new AboutState(terminal);
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
    delete chooseFactorState;
    delete chooseHeuristicMachineState;
    delete randomizeForHumanState;
    delete randomizeForMachineState;
    delete aboutState;
}
