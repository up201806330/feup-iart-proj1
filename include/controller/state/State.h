// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "algorithm/SearchStrategy.h"
#include "view/gui/TerminalGUI.h"

class MainMenuState;
class PlayHumanState;
class ChooseMachineState;
class PlayMachineState;

class State {
private:
    TerminalGUI *terminal;
public:
    explicit State(TerminalGUI *term);
    TerminalGUI* getTerminal();
    virtual State* run() = 0;

    static MainMenuState *mainMenuState;
    static PlayHumanState *playHumanState;
    static ChooseMachineState *chooseMachineState;
    static PlayMachineState *playMachineState;
    static void initializeStates(TerminalGUI *terminal);
};

#include "MainMenuState.h"
#include "PlayHumanState.h"
#include "ChooseMachineState.h"
#include "PlayMachineState.h"
