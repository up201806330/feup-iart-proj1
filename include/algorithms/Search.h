// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"

class Search {
public:
    virtual void initialize(const GameboardModel &gameboard) = 0;
    virtual GameboardModel::Move next() = 0;
};
