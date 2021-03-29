// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

class ChooseBaseHeuristicState: public State {
private:
    const Heuristic *h = nullptr;
public:
    explicit ChooseBaseHeuristicState(TerminalGUI *term);

    void setBaseHeuristic(const Heuristic *heuristic);
    const Heuristic *getBaseHeuristic() const;

    State* run() override;

    ~ChooseBaseHeuristicState() override;
};
