// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

class ChooseStrategyState: public State {
private:
    SearchStrategy *strategy = nullptr;
public:
    explicit ChooseStrategyState(TerminalGUI *term);

    void setSearchStrategy(SearchStrategy *search);
    SearchStrategy *getSearchStrategy() const;

    State* run() override;
};
