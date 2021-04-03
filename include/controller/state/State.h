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
class ChooseFactorState;
class ChooseHeuristicStrategyState;
class RandomizeForHumanState;
class RandomizeForMachineState;
class AboutState;

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
    virtual ~State();

    static MainMenuState                     *mainMenuState                    ; ///< @brief Main menu state instance
    static PlayHumanState                    *playHumanState                   ; ///< @brief Play human state instance
    static ChooseStrategyState               *chooseMachineState               ; ///< @brief Choose strategy state instance
    static PlayMachineState                  *playMachineState                 ; ///< @brief Play machine state instance
    static ChooseHeuristicState              *chooseHeuristicState             ; ///< @brief Choose heuristic state instance
    static ChooseHorizonState                *chooseHorizonState               ; ///< @brief Choose horizon state instance
    static ChooseBaseHeuristicState          *chooseBaseHeuristicState         ; ///< @brief Choose base heuristic state instance
    static ChooseFiniteHorizonHeuristicState *chooseFiniteHorizonHeuristicState; ///< @brief Choose finite horizon heuristic state instance
    static ChooseFactorState                 *chooseFactorState                ; ///< @brief Choose factor for non-admissible heuristic
    static ChooseHeuristicStrategyState      *chooseHeuristicMachineState      ; ///< @brief Choose heuristic strategy state instance
    static RandomizeForHumanState            *randomizeForHumanState           ; ///< @brief Choose parameters to randomize puzzle
    static RandomizeForMachineState          *randomizeForMachineState         ; ///< @brief Choose parameters to randomize puzzle
    static AboutState                        *aboutState                       ; ///< @brief About screen state instance

    /**
     * @brief Initialize all states with the terminal that must be used to print stuff.
     *
     * @param terminal  Terminal to build all states
     */
    static void initializeStates(TerminalGUI *terminal);
    /**
     * @brief Delete all states created using State::initializeStates(TerminalGUI *).
     */
    static void deleteStates();
};

#include "MainMenuState.h"
#include "PlayHumanState.h"
#include "ChooseStrategyState.h"
#include "PlayMachineState.h"
#include "ChooseHeuristicState.h"
#include "ChooseHorizonState.h"
#include "ChooseBaseHeuristicState.h"
#include "ChooseFiniteHorizonHeuristicState.h"
#include "ChooseFactorState.h"
#include "ChooseHeuristicStrategyState.h"
#include "RandomizeForHumanState.h"
#include "RandomizeForMachineState.h"
#include "AboutState.h"
