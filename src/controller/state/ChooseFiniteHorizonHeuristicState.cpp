// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <algorithm/heuristics/FiniteHorizonHeuristic.h>
#include "controller/state/ChooseFiniteHorizonHeuristicState.h"

#include "controller/MenuController.h"
#include "view/MenuView.h"

using namespace std;

ChooseFiniteHorizonHeuristicState::ChooseFiniteHorizonHeuristicState(TerminalGUI *term) : State(term) {
}

void ChooseFiniteHorizonHeuristicState::setHeuristic(const Heuristic *heuristic) {
    State::chooseHeuristicState->setHeuristic(heuristic);
}

const Heuristic *ChooseFiniteHorizonHeuristicState::getHeuristic() const {
    return State::chooseHeuristicState->getHeuristic();
}

State *ChooseFiniteHorizonHeuristicState::run() {
    MenuModel menuModel;
    menuModel.addButton(1, "1. Finite horizon heuristic");
    menuModel.addButton(0, "0. Back");

    MenuView menuView(menuModel);

    MenuController menuController(menuModel);

    int option;
    do {
        getTerminal()->clear();
        menuView.draw(*getTerminal());
        getTerminal()->display();
        menuController.run();
        option = menuController.getSelectedOption();
    } while(!menuModel.hasButtonWithId(option));

    const Heuristic *baseHeuristic = State::chooseBaseHeuristicState->getBaseHeuristic();
    size_t horizon = State::chooseHorizonState->getHorizon();
    switch(option){
        case 1: this->setHeuristic(new FiniteHorizonHeuristic(baseHeuristic, horizon)); return State::chooseHeuristicMachineState;
        case 0: return State::chooseMachineState;
        default: throw logic_error("");
    }
}
