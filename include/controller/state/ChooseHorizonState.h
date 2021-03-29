// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief For finite horizon algorithms, choose the horizon.
 */
class ChooseHorizonState: public State {
private:
    size_t depth = 0;
public:
    explicit ChooseHorizonState(TerminalGUI *term);

    /**
     * @brief Set horizon
     * @param horizon  Horizon
     */
    void setHorizon(size_t horizon);
    /**
     * @brief Get horizon
     *
     * @return Horizon
     */
    size_t getHorizon() const;

    State* run() override;
};
