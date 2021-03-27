// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"
#include "Heuristics.h"

#include <deque>
#include <unordered_set>

class BestFirstSearch : public SearchStrategy {
private:
    Heuristics::heuristic_t h;
    std::deque<GameboardModel::Move> solution;
    std::unordered_set<GameboardModel> visited;
public:
    explicit BestFirstSearch(Heuristics::heuristic_t heuristic);
    bool dfs(const GameboardModel& gameBoard);

    void initialize(const GameboardModel &gameboardModel) override;
    GameboardModel::Move next() override;
};
