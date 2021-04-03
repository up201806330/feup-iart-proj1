// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <algorithm/heuristics/NonAdmissibleHeuristic.h>
#include "algorithm/heuristics/AdmissibleHeuristic.h"
#include "algorithm/DepthFirstSearch.h"
#include "controller/state/ChooseFactorState.h"

using namespace std;
using coord_t = TerminalGUI::coord_t;
using pos_t   = TerminalGUI::pos_t;

ChooseFactorState::ChooseFactorState(TerminalGUI *term) : State(term) {
}

void ChooseFactorState::setFactor(double factor) {
    this->f = factor;
}

double ChooseFactorState::getFactor() const {
    return f;
}

State *ChooseFactorState::run() {
    getTerminal()->setCorner(-getTerminal()->getSize()/2);
    string s = "Choose the factor (must be a floating-point number larger than or equal to 1), or enter 0 to go back";

    double factor = 0.0;
    do {
        getTerminal()->clear();
        getTerminal()->drawString(pos_t(-coord_t(s.size())/2, 0), s);
        getTerminal()->display();
        cin >> factor;
    } while(cin.fail() || factor < 1.0);

    if(factor == 0.0) return State::chooseHeuristicState;

    this->setFactor(factor);
    State::chooseHeuristicState->setHeuristic(new NonAdmissibleHeuristic(new AdmissibleHeuristic(), this->getFactor()));
    return State::chooseBaseHeuristicState;
}

ChooseFactorState::~ChooseFactorState() = default;
