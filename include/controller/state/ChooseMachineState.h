// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

class ChooseMachineState: public State {
private:
    const SearchStrategy *machine = nullptr;
public:
    explicit ChooseMachineState(TerminalGUI *term);
    State* run() override;

    void setMachine(const SearchStrategy *machine);
    const SearchStrategy *getMachine() const;
};
