// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief For finite horizon algorithms, choose the horizon.
 */
class RandomizeForMachineState: public State {
private:
    GameboardModel g;
public:
    /**
     * @brief Construct a new ChooseHorizonState object.
     * 
     * @param term Terminal to print to
     */
    explicit RandomizeForMachineState(TerminalGUI *term);

    /**
     * @brief Set horizon
     * @param horizon  Horizon
     */
    void setGameboard(GameboardModel gameboardModel);
    /**
     * @brief Get horizon
     *
     * @return Horizon
     */
    GameboardModel getGameboard() const;

    State* run() override;

    ~RandomizeForMachineState() override;
};
