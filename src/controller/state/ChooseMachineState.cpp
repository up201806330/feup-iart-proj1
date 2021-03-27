// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <algorithm/GreedySearch.h>
#include "algorithm/Heuristics.h"
#include "algorithm/GreedySearch.h"
#include "algorithm/DepthFirstSearch.h"
#include "algorithm/IterativeDeepeningSearch.h"
#include "controller/state/ChooseMachineState.h"

#include "controller/MenuController.h"
#include "view/MenuView.h"
#include "model/MenuModel.h"
#include "algorithm/AstarSearch.h"

using namespace std;

ChooseMachineState::ChooseMachineState(TerminalGUI *term) : State(term) {
}

State *ChooseMachineState::run() {
    MenuModel menuModel;
    menuModel.addButton(1, "1. Depth first search");
    menuModel.addButton(3, "3. Iterative deepening depth first search");
    menuModel.addButton(4, "4. Best-first search, greedy");
    menuModel.addButton(4, "5. Best-first search, A*");
    menuModel.addButton(0, "0. Back");

    MenuView menuView(menuModel);

    MenuController menuController(menuModel);

    int option = 0;
    do {
        getTerminal()->clear();
        menuView.draw(*getTerminal());
        getTerminal()->display();
        menuController.run();
        option = menuController.getSelectedOption();
    } while(!menuModel.hasButtonWithId(option));

    if(option == 0) return State::mainMenuState;

    switch(option){
        case 1: State::playMachineState->setSearchStrategy(new DepthFirstSearch()); break;
        case 3: State::playMachineState->setSearchStrategy(new IterativeDeepeningSearch()); break;
        case 4: State::playMachineState->setSearchStrategy(new GreedySearch(Heuristics::h1)); break;
        case 5: State::playMachineState->setSearchStrategy(new AstarSearch(Heuristics::h1)); break;
        default: throw logic_error("");
    }
    return State::playMachineState;
}
