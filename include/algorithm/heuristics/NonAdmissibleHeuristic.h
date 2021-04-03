// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "Heuristic.h"

/**
 * @brief A non-admissible heuristic.
 *
 * For a description of an admissible heuristic, @see AdmissibleHeuristic.
 *
 * Uses any heuristic, and multiplies its value by a constant, presumably making it non-admissible.
 */
class NonAdmissibleHeuristic: public Heuristic {
private:
    const Heuristic *h;
    const double f;
public:
    NonAdmissibleHeuristic(const Heuristic *heuristic, double factor);
    heuristic_t operator()(const GameboardModel &g) const override;
    ~NonAdmissibleHeuristic();
};
