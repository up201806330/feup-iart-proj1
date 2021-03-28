// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/heuristics/AdmissibleHeuristic.h"
#include "algorithm/DepthFirstSearch.h"
#include "controller/state/ChooseHorizonState.h"

using namespace std;
using coord_t = TerminalGUI::coord_t;
using pos_t   = TerminalGUI::pos_t;

ChooseHorizonState::ChooseHorizonState(TerminalGUI *term) : State(term) {
}

void ChooseHorizonState::setHorizon(size_t horizon) {
    this->depth = horizon;
}

size_t ChooseHorizonState::getHorizon() const {
    return depth;
}

State *ChooseHorizonState::run() {
    getTerminal()->setCorner(getTerminal()->getSize()/2);
    string s = "Choose the horizon (must be larger than or equal to 1), or enter 0 to go back";
    getTerminal()->drawString(pos_t(-coord_t(s.size())/2, 0), s);

    int horizon = 0;
    do {
        cin >> horizon;
    } while(cin.fail() || horizon < 1);

    if(horizon == 0) return State::chooseHeuristicState;

    this->setHorizon(static_cast<size_t>(horizon));
    return State::chooseBaseHeuristicState;
}
