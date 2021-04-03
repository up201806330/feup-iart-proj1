// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief For finite horizon algorithms, choose the horizon.
 */
class ChooseFactorState: public State {
private:
    double f = 1.0;
public:
    /**
     * @brief Construct a new ChooseHorizonState object.
     * 
     * @param term Terminal to print to
     */
    explicit ChooseFactorState(TerminalGUI *term);

    /**
     * @brief Set horizon
     * @param horizon  Horizon
     */
    void setFactor(double factor);
    /**
     * @brief Get horizon
     *
     * @return Horizon
     */
    double getFactor() const;

    State* run() override;

    ~ChooseFactorState() override;
};
