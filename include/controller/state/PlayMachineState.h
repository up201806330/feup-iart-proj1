// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "algorithm/Search.h"
#include "State.h"

class PlayMachineState: public State {
private:
    Search *search;
public:
    PlayMachineState(TerminalGUI *term, Search *search);
    State* run() override;
};
