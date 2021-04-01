// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"
#include "algorithm/heuristics/Heuristic.h"

#include <set>
#include <list>

/**
 * @brief Best-first greedy search.
 *
 * Similar to A*: uses a priority queue and expands the node with least priority; but the priority is only the estimated
 * distance from that node to a solution, unlike A* where priority is the estimated total cost of a solution going
 * through that node.
 *
 * Does not guarantee the solution is optimal.
 */
class GreedySearch : public SearchStrategy {
private:
    const Heuristic *h = nullptr;
    std::list<GameboardModel::Move> solution;
public:
    /**
     * @brief Construct greedy search from heuristic.
     *
     * The heuristic is used to rank states.
     *
     * @param heuristic     Heuristic
     */
    explicit GreedySearch(const Heuristic *heuristic);
    void initialize(const GameboardModel &gameboardModel) override;
    GameboardModel::Move next() override;
    ~GreedySearch() override;
};
