// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

class ChooseHorizonState: public State {
private:
    size_t depth = 0;
public:
    explicit ChooseHorizonState(TerminalGUI *term);

    void setHorizon(size_t horizon);
    size_t getHorizon() const;

    State* run() override;

    ~ChooseHorizonState() override;
};
