// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief Human play
 */
class PlayHumanState: public State {
public:
    /**
     * @brief Construct a new PlayHumanState object.
     * 
     * @param term Terminal to print to
     */
    explicit PlayHumanState(TerminalGUI *term);
    State* run() override;
    ~PlayHumanState() override;
};
