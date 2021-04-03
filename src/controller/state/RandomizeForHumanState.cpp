// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <algorithm/heuristics/NonAdmissibleHeuristic.h>
#include "algorithm/heuristics/AdmissibleHeuristic.h"
#include "algorithm/DepthFirstSearch.h"
#include "controller/state/ChooseFactorState.h"

using namespace std;
using coord_t = TerminalGUI::coord_t;
using pos_t   = TerminalGUI::pos_t;

RandomizeForHumanState::RandomizeForHumanState(TerminalGUI *term) : State(term) {
}

void RandomizeForHumanState::setGameboard(GameboardModel gameboardModel) {
    this->g = gameboardModel;
}

GameboardModel RandomizeForHumanState::getGameboard() const {
    return g;
}

State *RandomizeForHumanState::run() {
    getTerminal()->setCorner(-getTerminal()->getSize()/2);
    string s = "Insert gameboard parameters: <nTubes> <tubeH> <nColors> <seed>";

    bool isInvalid = false;
    GameboardModel gameboardModel;
    stringstream ss;
    do {
        getTerminal()->clear();
        getTerminal()->drawString(pos_t(-coord_t(s.size())/2, 0), s);
        getTerminal()->display();
        size_t nTubes, tubeH, nColors; unsigned seed;
        string line;
        getline(cin, line);
        ss = stringstream(line);
        ss >> nTubes >> tubeH >> nColors >> seed;
        if (ss.fail()) continue;
        try {
            gameboardModel = GameboardModel(nTubes, tubeH);
            gameboardModel.fillRandom(nColors, seed);
        }
        catch (const exception &e){
            isInvalid = true;
        }
    } while(isInvalid || cin.fail() || ss.fail());

    this->setGameboard(gameboardModel);
    return State::playHumanState;
}

RandomizeForHumanState::~RandomizeForHumanState() = default;
