// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "Heuristic.h"

/**
 * @brief An admissible heuristic.
 *
 * In the context of pathfinding algorithms, an heuristic is said to be admissible iff it never overestimates the cost
 * of reaching the goal state (or one of many goal states); i.e., it always returns a value less than or equal to the
 * least cost to reach the goal. It can be considered an *optimistic* estimate.
 *
 * Let f(t) be the number of contiguous, same-color pieces at the bottom of tube t; if a tube has pieces with colors
 * [0,0,0,1,2,0,1] (left is bottom, right is top), f = 3 because there are 3 contiguous pieces of color 0 at the bottom
 * of that tube, and piece #4 is a different color so it does not count.
 *
 * This heuristic uses two factors to estimate the distance to a goal:
 * 1. For each tube t, f(t) is added (these will have to be removed)
 * 2. If N tubes have the same color at the bottom, we will at least have to move all pieces in the N-1 tubes with the smallest f(t) values.
 */
class AdmissibleHeuristic: public Heuristic {
public:
    heuristic_t operator()(const GameboardModel &g) const override;
};
