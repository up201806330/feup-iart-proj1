// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"

class Heuristic {
public:
    typedef double heuristic_t;
    constexpr static const heuristic_t INF = 1000000000000.0;
    virtual heuristic_t operator()(const GameboardModel &g) const = 0;
    virtual ~Heuristic();
};
