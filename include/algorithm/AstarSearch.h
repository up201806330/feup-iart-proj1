// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "algorithm/SearchStrategy.h"
#include "algorithm/heuristics/Heuristic.h"

#include <unordered_set>

class AstarSearch: public SearchStrategy {
private:
    const Heuristic *h;
    std::deque<GameboardModel::Move> solution;
public:
    explicit AstarSearch(const Heuristic *heuristic);
    void initialize(const GameboardModel &gameboard) override;
    GameboardModel::Move next() override;
    ~AstarSearch() override;
};
