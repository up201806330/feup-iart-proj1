// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithms/GreedySearch.h"

void GreedySearch::initialize(const GameboardModel &gameboardModel){
    gameboard = gameboardModel;
}

GameboardModel::Move GreedySearch::next() {
    return GameboardModel::Move(0, 0);
}
