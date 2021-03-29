// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/heuristics/AdmissibleHeuristic.h"
#include "controller/state/ChooseBaseHeuristicState.h"

#include "controller/MenuController.h"
#include "view/MenuView.h"

using namespace std;

ChooseBaseHeuristicState::ChooseBaseHeuristicState(TerminalGUI *term) : State(term) {
}

void ChooseBaseHeuristicState::setBaseHeuristic(const Heuristic *baseHeuristic) {
    this->h = baseHeuristic;
}

const Heuristic *ChooseBaseHeuristicState::getBaseHeuristic() const {
    return h;
}

State *ChooseBaseHeuristicState::run() {
    MenuModel menuModel;
    menuModel.addButton(1, "1. Admissible heuristic");
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
        case 1: this->setBaseHeuristic(new AdmissibleHeuristic()); return State::chooseFiniteHorizonHeuristicState;
        case 0: return State::chooseHeuristicState;
        default: throw logic_error("");
    }
}
