// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"
#include "algorithm/heuristics/Heuristic.h"

#include <unordered_set>
#include <list>

class GreedySearch : public SearchStrategy {
private:
    const Heuristic *h = nullptr;
    std::list<GameboardModel::Move> solution;
public:
    explicit GreedySearch(const Heuristic *heuristic);
    void initialize(const GameboardModel &gameboardModel) override;
    GameboardModel::Move next() override;
    ~GreedySearch() override;
};
