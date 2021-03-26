// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "algorithm/Search.h"

#include <queue>
#include <unordered_set>

class GreedySearch: public Search {
public:
    typedef double (*heuristic_t)(const GameboardModel);
private:
    heuristic_t h;
    GameboardModel gameboard;
    std::queue<GameboardModel::Move> moves;
    std::unordered_set<GameboardModel> visited;
public:
    GreedySearch(heuristic_t heuristic);
    virtual void initialize(const GameboardModel &gameboardModel);
    virtual GameboardModel::Move next();
};
