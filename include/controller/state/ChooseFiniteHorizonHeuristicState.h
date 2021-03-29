// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

class ChooseFiniteHorizonHeuristicState: public State {
private:
    const Heuristic *h = nullptr;
public:
    explicit ChooseFiniteHorizonHeuristicState(TerminalGUI *term);

    void setHeuristic(const Heuristic *heuristic);
    const Heuristic *getHeuristic() const;

    State* run() override;
};
