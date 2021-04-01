// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"

#include <bits/stdc++.h>
#include <deque>
#include <map>

/**
 * @brief Iterative deepening depth-first search.
 *
 * Iterative deepening DFS is a method used mostly when the depth of the solution is not known. It consists of, at each
 * iteration, performing DFS of nodes at depth at most d, check if a solution was found, and if not increment d, and
 * repeat until a solution is found.
 *
 * If there is a solution, it is guaranteed to be optimal.
 *
 * It is better than DFS if the optimal path length is considerably smaller than the number of possible states, and if
 * the branching factor is not too large.
 */
class IterativeDeepeningSearch : public SearchStrategy {
private:
    std::deque<GameboardModel::Move> solution;
    std::map<GameboardModel, size_t> visited;
    size_t maxDepth;

    bool dfs(const GameboardModel& gameBoard, size_t depth);
public:
    void initialize(const GameboardModel &gameboardModel) override;
    GameboardModel::Move next() override;
};
