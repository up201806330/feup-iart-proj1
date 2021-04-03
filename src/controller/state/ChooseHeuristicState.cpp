// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/heuristics/AdmissibleHeuristic.h"
#include "controller/state/ChooseHeuristicState.h"

#include "controller/MenuController.h"
#include "view/MenuView.h"

using namespace std;

ChooseHeuristicState::ChooseHeuristicState(TerminalGUI *term) : State(term) {
}

void ChooseHeuristicState::setHeuristic(const Heuristic *heuristic) {
    this->h = heuristic;
}

const Heuristic *ChooseHeuristicState::getHeuristic() const {
    return h;
}

State *ChooseHeuristicState::run() {
    MenuModel menuModel;
    menuModel.addButton(1, "1. Admissible heuristic");
    menuModel.addButton(2, "2. Finite horizon heuristics (+)");
    menuModel.addButton(2, "3. Non-admissible heuristics (+)");
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

    switch(option){
        case 1: this->setHeuristic(new AdmissibleHeuristic()); return State::chooseHeuristicMachineState;
        case 2: return State::chooseHorizonState;
        case 3: return State::chooseFactorState;
        case 0: return State::chooseMachineState;
        default: throw logic_error("");
    }
}

ChooseHeuristicState::~ChooseHeuristicState() = default;
