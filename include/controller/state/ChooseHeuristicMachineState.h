// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

class ChooseHeuristicMachineState: public State {
private:
    const Heuristic *h = nullptr;
public:
    explicit ChooseHeuristicMachineState(TerminalGUI *term);

    void setMachine(const SearchStrategy *machine);
    const SearchStrategy *getMachine() const;

    State* run() override;
};
