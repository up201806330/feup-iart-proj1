// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

class ChooseHeuristicStrategyState: public State {
private:
    const Heuristic *h = nullptr;
public:
    explicit ChooseHeuristicStrategyState(TerminalGUI *term);

    void setSearchStrategy(SearchStrategy *search);
    SearchStrategy *getSearchStrategy() const;

    State* run() override;

    ~ChooseHeuristicStrategyState() override;
};
