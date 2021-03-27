// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "algorithm/SearchStrategy.h"
#include "Heuristics.h"

#include <unordered_set>

class AstarSearch: public SearchStrategy {
private:
    Heuristics::heuristic_t h;
    std::deque<GameboardModel::Move> solution;
    std::unordered_set<GameboardModel> visited;
public:
    explicit AstarSearch(Heuristics::heuristic_t heuristic);
    bool dfs(const GameboardModel& gameBoard);

    void initialize(const GameboardModel &gameboard) override;
    GameboardModel::Move next() override;
};
