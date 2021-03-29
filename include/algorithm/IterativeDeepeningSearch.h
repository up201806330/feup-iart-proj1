// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"

#include <bits/stdc++.h>
#include <deque>
#include <unordered_map>

class IterativeDeepeningSearch : public SearchStrategy {
private:
    std::deque<GameboardModel::Move> solution;
    std::unordered_map<GameboardModel, size_t> visited;
    size_t maxDepth;
public:
    bool dfs(const GameboardModel& gameBoard, size_t depth);

    void initialize(const GameboardModel &gameboardModel) override;
    GameboardModel::Move next() override;
};
