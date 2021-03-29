// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief Given you have chosen to use finite horizon heuristics, choose one of the available finite horizon statistics.
 */
class ChooseFiniteHorizonHeuristicState: public State {
private:
    const Heuristic *h = nullptr;
public:
    /**
     * @brief Construct a new ChooseFiniteHorizonHeuristicState object.
     * 
     * @param term Terminal to print to
     */
    explicit ChooseFiniteHorizonHeuristicState(TerminalGUI *term);

    /**
     * @brief Set heuristic.
     *
     * Forwards the heuristic ChooseHeuristicState::setHeuristic.
     *
     * @param heuristic
     */
    void setHeuristic(const Heuristic *heuristic);
    /**
     * @brief Get heuristic.
     *
     * Requests the heuristic from ChooseHeuristicState::getHeuristic.
     *
     * @return  Heuristic
     */
    const Heuristic *getHeuristic() const;

    State* run() override;

    ~ChooseFiniteHorizonHeuristicState() override;
};
