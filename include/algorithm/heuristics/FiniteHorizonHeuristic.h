// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "Heuristic.h"

class FiniteHorizonHeuristic: public Heuristic {
private:
    const Heuristic *h = nullptr;
    size_t depth;
public:
    explicit FiniteHorizonHeuristic(const Heuristic *heuristic, size_t horizon);
    heuristic_t operator()(const GameboardModel &gameboard) const override;
};
