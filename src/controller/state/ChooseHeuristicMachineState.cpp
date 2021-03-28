// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/heuristics/AdmissibleHeuristic.h"
#include "algorithm/DepthFirstSearch.h"
#include "algorithm/DepthFirstGreedySearch.h"
#include "algorithm/GreedySearch.h"
#include "controller/state/ChooseHeuristicMachineState.h"

#include "controller/MenuController.h"
#include "view/MenuView.h"
#include "algorithm/AstarSearch.h"

using namespace std;

ChooseHeuristicMachineState::ChooseHeuristicMachineState(TerminalGUI *term) : State(term) {
}

void ChooseHeuristicMachineState::setMachine(SearchStrategy *machine) {
    State::chooseMachineState->setMachine(machine);
}

SearchStrategy *ChooseHeuristicMachineState::getMachine() const {
    return State::chooseMachineState->getMachine();
}

State *ChooseHeuristicMachineState::run() {
    MenuModel menuModel;
    menuModel.addButton(1, "1. Depth first search, greedy first");
    menuModel.addButton(2, "2. Best-first search, greedy");
    menuModel.addButton(3, "3. Best-first search, A*");
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

    const Heuristic *heuristic = State::chooseHeuristicState->getHeuristic();
    switch(option){
        case 1: this->setMachine(new DepthFirstGreedySearch(heuristic)); return State::playMachineState;
        case 2: this->setMachine(new GreedySearch          (heuristic)); return State::playMachineState;
        case 3: this->setMachine(new AstarSearch           (heuristic)); return State::playMachineState;
        case 0: return State::chooseHeuristicState;
        default: throw logic_error("");
    }
}
