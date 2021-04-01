// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"

/**
 * @brief Heuristic class.
 *
 * Provides an interface for an heuristic, which is a function that ranks states by order of preference.
 * A state is preferred when compared to another if it is closer to a solution (or if it is *perceived* to be closer to
 * a solution). States (or gameboards) are ranked using the score returned by operator(), and a state A is preferred
 * over state B iff the score for A is smaller than for B.
 *
 * The result of operator() tends to be an estimate of the number of moves left to reach any solution, although it is
 * not mandatory to have this interpretation (hence why it returns a value of type heuristic_t, which is a
 * floating-point number.
 */
class Heuristic {
public:
    /**
     * @brief Type of heuristic results.
     */
    typedef double heuristic_t;
    /**
     * @brief Infinity, defined as the neutral element of most heuristic evaluations.
     */
    constexpr static const heuristic_t INF = 1000000000000.0;
    /**
     * @brief Evaluate a state/gameboard.
     *
     * @param g     Gameboard to be evaluated
     * @return      Score of that gameboard
     */
    virtual heuristic_t operator()(const GameboardModel &g) const = 0;
    /**
     * @brief Destructor.
     */
    virtual ~Heuristic();
};
