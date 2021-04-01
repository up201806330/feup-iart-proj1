// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "controller/state/ChooseStrategyState.h"

#include "algorithm/DepthFirstSearch.h"
#include "algorithm/BreadthFirstSearch.h"
#include "algorithm/IterativeDeepeningSearch.h"
#include "controller/MenuController.h"
#include "view/MenuView.h"

using namespace std;

ChooseStrategyState::ChooseStrategyState(TerminalGUI *term) : State(term) {
}

void ChooseStrategyState::setSearchStrategy(SearchStrategy *search) {
    delete this->strategy;
    this->strategy = search;
}

SearchStrategy *ChooseStrategyState::getSearchStrategy() const{
    return strategy;
}

State *ChooseStrategyState::run() {
    MenuModel menuModel;
    menuModel.addButton(1, "1. Depth first search");
    menuModel.addButton(2, "2. Breadth first search");
    menuModel.addButton(3, "3. Iterative deepening depth first search");
    menuModel.addButton(4, "4. Informed search methods (+)");
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
        case 1: this->setSearchStrategy(new DepthFirstSearch()); return State::playMachineState;
        case 2: this->setSearchStrategy(new BreadthFirstSearch()); return State::playMachineState;
        case 3: this->setSearchStrategy(new IterativeDeepeningSearch()); return State::playMachineState;
        case 4: return State::chooseHeuristicState;
        case 0: return State::mainMenuState;
        default: throw logic_error("");
    }
}

ChooseStrategyState::~ChooseStrategyState() = default;
