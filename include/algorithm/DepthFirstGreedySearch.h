// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"
#include "algorithm/heuristics/Heuristic.h"

#include <deque>
#include <unordered_set>

/**
 * @brief Depth first search, expand best neighbours first.
 *
 * A regular DFS expands neighbors of a state randomly. Actually, in most cases, it expands neighbors by the order they
 * come up, which for most situations is assumed as random when lacking information relating the quality of the neighbor
 * with the order they come up at in the adjacency list; in our case, moves to reach adjacent states are sorted by the
 * tubes they refer to, and tube ordering does not bear any particular information).
 *
 * This class performs DFS, but instead of expanding adjacent states randomly, it first expands those states which are
 * deemed *better* according to a heuristic. This means that, when expanding the path, this algorithm first chooses the
 * state it thinks will lead to a solution faster, and if a certain branch is found not to lead to a solution the
 * algorithm backtracks until it finds the second-best path to expand, and so on until it finds a path leading to a
 * solution, or until all states have been explored and no solution was found.
 */
class DepthFirstGreedySearch : public SearchStrategy {
private:
    const Heuristic *h = nullptr;
    std::deque<GameboardModel::Move> solution;
    std::unordered_set<GameboardModel> visited;

    bool dfs(const GameboardModel& gameBoard);
public:
    /**
     * @brief Construct DFS greedy strategy from heuristic.
     *
     * The heuristic is used to rank states.
     *
     * @param heuristic     Heuristic
     */
    explicit DepthFirstGreedySearch(const Heuristic *heuristic);

    void initialize(const GameboardModel &gameboardModel) override;
    GameboardModel::Move next() override;
};
