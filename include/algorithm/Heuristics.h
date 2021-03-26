// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"

class Heuristics {
public:
    static double h1(const GameboardModel &gameboard);
};
