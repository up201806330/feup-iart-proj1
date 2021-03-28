// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/heuristics/AdmissibleHeuristic.h"
#include "algorithm/DepthFirstSearch.h"
#include "algorithm/DepthFirstGreedySearch.h"
#include "algorithm/GreedySearch.h"
#include "algorithm/IterativeDeepeningSearch.h"
#include "controller/state/ChooseMachineState.h"

#include "controller/MenuController.h"
#include "view/MenuView.h"
#include "model/MenuModel.h"
#include "algorithm/AstarSearch.h"

using namespace std;

ChooseMachineState::ChooseMachineState(TerminalGUI *term) : State(term) {
}

void ChooseMachineState::setMachine(const SearchStrategy *searchStrategy) {
    this->machine = searchStrategy;
}

const SearchStrategy *ChooseMachineState::getMachine() const{
    return machine;
}

State *ChooseMachineState::run() {
    MenuModel menuModel;
    menuModel.addButton(1, "1. Depth first search");
//    menuModel.addButton(2, "2. Breadth first search");
    menuModel.addButton(4, "3. Iterative deepening depth first search");
    menuModel.addButton(3, "4. Informed search methods (+)");
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
        case 1: State::playMachineState->setSearchStrategy(new DepthFirstSearch()); return State::playMachineState;
//        case 2: State::playMachineState->setSearchStrategy(new BreadthFirstSearch()); return State::playMachineState;
        case 3: State::playMachineState->setSearchStrategy(new IterativeDeepeningSearch()); return State::playMachineState;
        case 4: return State::chooseHeuristicState;
        case 0: return State::mainMenuState;
        default: throw logic_error("");
    }
}
