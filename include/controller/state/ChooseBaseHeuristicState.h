// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief For a finite horizon heuristic, choose the base heuristic to be used.
 */
class ChooseBaseHeuristicState: public State {
private:
    const Heuristic *h = nullptr;
public:
    explicit ChooseBaseHeuristicState(TerminalGUI *term);

    /**
     * @brief Set base heuristic.
     *
     * @param baseHeuristic Base heuristic
     */
    void setBaseHeuristic(const Heuristic *baseHeuristic);
    /**
     * @brief Get base heuristic.
     *
     * @return Base heuristic
     */
    const Heuristic *getBaseHeuristic() const;

    State* run() override;
};
