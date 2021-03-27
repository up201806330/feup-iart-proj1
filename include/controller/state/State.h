// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/TerminalGUI.h"

class State {
private:
    TerminalGUI *terminal;
public:
    explicit State(TerminalGUI *term);
    TerminalGUI* getTerminal();
    virtual State* run() = 0;

    static State *mainMenuState;
    static State *playHumanState;
    static State *playMachineState;
    static void initializeStates(TerminalGUI *terminal);
};
