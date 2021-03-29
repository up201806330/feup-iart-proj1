// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief Main menu.
 */
class MainMenuState: public State {
public:
    /**
     * @brief Construct a new MainMenuState object.
     * 
     * @param term Terminal to print to
     */
    explicit MainMenuState(TerminalGUI *term);
    State* run() override;
};
