// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <algorithm/heuristics/NonAdmissibleHeuristic.h>
#include "algorithm/heuristics/AdmissibleHeuristic.h"
#include "algorithm/DepthFirstSearch.h"
#include "controller/state/ChooseFactorState.h"

using namespace std;
using coord_t = TerminalGUI::coord_t;
using pos_t   = TerminalGUI::pos_t;

RandomizeForMachineState::RandomizeForMachineState(TerminalGUI *term) : State(term) {
}

void RandomizeForMachineState::setGameboard(GameboardModel gameboardModel) {
    this->g = gameboardModel;
}

GameboardModel RandomizeForMachineState::getGameboard() const {
    return g;
}

State *RandomizeForMachineState::run() {
    getTerminal()->setCorner(-getTerminal()->getSize()/2);
    string s = "Insert gameboard parameters: <nTubes> <tubeH> <nColors> <seed>";

    bool isInvalid = false;
    GameboardModel gameboardModel;
    do {
        getTerminal()->clear();
        getTerminal()->drawString(pos_t(-coord_t(s.size())/2, 0), s);
        getTerminal()->display();
        size_t nTubes, tubeH, nColors; unsigned seed;
        cin >> nTubes >> tubeH >> nColors >> seed;
        if (cin.fail()) continue;
        try {
            gameboardModel = GameboardModel(nTubes, tubeH);
            gameboardModel.fillRandom(nColors, seed);
        }
        catch (const exception &e){
            isInvalid = true;
        }
    } while(isInvalid || cin.fail());

    this->setGameboard(gameboardModel);
    return State::chooseMachineState;
}

RandomizeForMachineState::~RandomizeForMachineState() = default;
