// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"
#include "Heuristic.h"

#include <unordered_set>
#include <list>

class GreedySearch : public SearchStrategy {
private:
    Heuristic::heuristic_t h;
    std::list<GameboardModel::Move> solution;
public:
    explicit GreedySearch(Heuristic::heuristic_t heuristic);
    void initialize(const GameboardModel &gameboardModel) override;
    GameboardModel::Move next() override;
};
