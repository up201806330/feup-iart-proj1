// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "Heuristic.h"

class AdmissibleHeuristic: public Heuristic {
public:
    heuristic_t operator()(const GameboardModel &g) const override;
};
