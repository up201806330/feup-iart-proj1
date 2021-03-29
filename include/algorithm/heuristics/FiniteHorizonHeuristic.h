// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "Heuristic.h"

/**
 * @brief Finite horizon heuristic.
 *
 * This heuristic uses a finite horizon to better estimate the distance from a state to any goal state. It computes all
 * states that are at a certain distance from the provided state using a depth-first search (if the provided gameboard
 * G has a possible move m, and that move m is reversible, then G is one of the states evaluated as having a distance of
 * 2 to the initial state).
 *
 * It then uses another heuristic (the *base* heuristic) to evaluate those final states; ideally the base heuristic
 * should be simple/fast to calculate, and should not be a finite horizon heuristic on its own. For each leaf gameboard
 * (gameboards that are `horizon` moves away from the original gameboard), the score is calculated using the base
 * heuristic, and the distance from the original state to those leaf states (which is `horizon`) is added. Then we take
 * the minimum of all those possible states.
 */
class FiniteHorizonHeuristic: public Heuristic {
private:
    const Heuristic *h = nullptr;
    size_t depth;
public:
    /**
     * @brief Construct finite horizon heuristic from a base heuristic and the horizon (depth) of the search.
     *
     * @param baseHeuristic Base heuristic
     * @param horizon       Horizon (depth)
     */
    explicit FiniteHorizonHeuristic(const Heuristic *baseHeuristic, size_t horizon);
    heuristic_t operator()(const GameboardModel &gameboard) const override;
};
