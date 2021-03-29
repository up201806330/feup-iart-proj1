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

/**
 * @brief State.
 *
 * Is used to control the state of the game, namely the organization of menus.
 */
class State {
private:
    TerminalGUI *terminal;
public:
    /**
     * @brief Construct state with terminal.
     *
     * @param term Terminal
     */
    explicit State(TerminalGUI *term);
    /**
     * @brief Get terminal the state was built with.
     *
     * @return
     */
    TerminalGUI* getTerminal();
    /**
     * @brief Run state.
     *
     * Returns the next state, or nullptr to instruct the program to terminate.
     *
     * @return  Next state
     */
    virtual State* run() = 0;

    static MainMenuState                     *mainMenuState                    ;
    static PlayHumanState                    *playHumanState                   ;
    static ChooseStrategyState               *chooseMachineState               ;
    static PlayMachineState                  *playMachineState                 ;
    static ChooseHeuristicState              *chooseHeuristicState             ;
    static ChooseHorizonState                *chooseHorizonState               ;
    static ChooseBaseHeuristicState          *chooseBaseHeuristicState         ;
    static ChooseFiniteHorizonHeuristicState *chooseFiniteHorizonHeuristicState;
    static ChooseHeuristicStrategyState      *chooseHeuristicMachineState      ;

    /**
     * @brief Initialize all states with the terminal that must be used to print stuff.
     *
     * @param terminal  Terminal to build all states
     */
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
