// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

#include "algorithm/heuristics/Heuristic.h"

/**
 * @brief Choose heuristic function.
 */
class ChooseHeuristicState: public State {
private:
    const Heuristic *h = nullptr;
public:
    explicit ChooseHeuristicState(TerminalGUI *term);

    /**
     * @brief Set heuristic function.
     *
     * @param heuristic     Heuristic
     */
    void setHeuristic(const Heuristic *heuristic);
    /**
     * @brief Get heuristic function.
     *
     * @return Heuristic
     */
    const Heuristic *getHeuristic() const;

    State* run() override;
};
