// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "view/RandomizeView.h"
#include "model/RandomizeModel.h"
#include "controller/state/RandomizeForHumanState.h"
#include "controller/RandomizeController.h"

using namespace std;

RandomizeForHumanState::RandomizeForHumanState(TerminalGUI *term) : State(term) {}

State *RandomizeForHumanState::run() {
    RandomizeModel randomizeModel;
    RandomizeView randomizeView(randomizeModel);
    RandomizeController randomizeController;

    vector<int> id;
    do {
        getTerminal()->clear();
        randomizeView.draw(*getTerminal());
        getTerminal()->display();
        randomizeController.run();
        id = randomizeController.getValues();
    } while(!randomizeModel.acceptValues());

    return State::playHumanState;
}

RandomizeForHumanState::~RandomizeForHumanState() = default;
