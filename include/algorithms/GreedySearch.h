// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "Search.h"

class GreedySearch: public Search {
private:
    GameboardModel gameboard;
public:
    virtual void initialize(const GameboardModel &gameboardModel);
    virtual GameboardModel::Move next();
};
