// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief Randomize parameters menu.
 */
class RandomizeForMachineState: public State {
public:
    /**
     * @brief Construct a new MainMenuState object.
     * 
     * @param term Terminal to print to
     */
    explicit RandomizeForMachineState(TerminalGUI *term);
    State* run() override;
    ~RandomizeForMachineState() override;
};
