// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "algorithm/SearchStrategy.h"
#include "view/gui/TerminalGUI.h"

class MainMenuState;
class PlayHumanState;
class ChooseStrategyState;
class PlayMachineState;
class ChooseHeuristicState;
class ChooseHorizonState;
class ChooseBaseHeuristicState;
class ChooseFiniteHorizonHeuristicState;
class ChooseHeuristicStrategyState;

class State {
private:
    TerminalGUI *terminal;
public:
    explicit State(TerminalGUI *term);
    TerminalGUI* getTerminal();
    virtual State* run() = 0;

    static MainMenuState                     *mainMenuState                    ;
    static PlayHumanState                    *playHumanState                   ;
    static ChooseStrategyState                *chooseMachineState               ;
    static PlayMachineState                  *playMachineState                 ;
    static ChooseHeuristicState              *chooseHeuristicState             ;
    static ChooseHorizonState                *chooseHorizonState               ;
    static ChooseBaseHeuristicState          *chooseBaseHeuristicState         ;
    static ChooseFiniteHorizonHeuristicState *chooseFiniteHorizonHeuristicState;
    static ChooseHeuristicStrategyState       *chooseHeuristicMachineState      ;
    static void initializeStates(TerminalGUI *terminal);
};

#include "MainMenuState.h"
#include "PlayHumanState.h"
#include "ChooseStrategyState.h"
#include "PlayMachineState.h"
#include "ChooseHeuristicState.h"
#include "ChooseHorizonState.h"
#include "ChooseBaseHeuristicState.h"
#include "ChooseFiniteHorizonHeuristicState.h"
#include "ChooseHeuristicStrategyState.h"
