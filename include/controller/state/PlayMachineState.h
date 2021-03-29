// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "algorithm/SearchStrategy.h"
#include "State.h"

/**
 * @brief Machine (search strategy) play.
 */
class PlayMachineState: public State {
public:
    /**
     * @brief Construct a new PlayMachineState object.
     * 
     * @param term Terminal to print to
     */
    explicit PlayMachineState(TerminalGUI *term);
    State* run() override;
    ~PlayMachineState() override;
};
