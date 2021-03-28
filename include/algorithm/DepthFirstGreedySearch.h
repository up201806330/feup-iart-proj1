// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"
#include "algorithm/heuristics/Heuristic.h"

#include <deque>
#include <unordered_set>

class DepthFirstGreedySearch : public SearchStrategy {
private:
    const Heuristic *h;
    std::deque<GameboardModel::Move> solution;
    std::unordered_set<GameboardModel> visited;
public:
    explicit DepthFirstGreedySearch(const Heuristic *heuristic);
    bool dfs(const GameboardModel& gameBoard);

    void initialize(const GameboardModel &gameboardModel) override;
    GameboardModel::Move next() override;
};
