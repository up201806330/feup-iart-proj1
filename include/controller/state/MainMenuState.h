// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

class MainMenuState: public State {
public:
    MainMenuState(TerminalGUI *term);
    virtual State* run();
};
