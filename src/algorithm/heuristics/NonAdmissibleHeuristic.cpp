// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <numeric>
#include <algorithm>
#include "algorithm/heuristics/NonAdmissibleHeuristic.h"

using namespace std;

NonAdmissibleHeuristic::NonAdmissibleHeuristic(const Heuristic *heuristic, double factor):
    h(heuristic),
    f(factor)
{
}

Heuristic::heuristic_t NonAdmissibleHeuristic::operator()(const GameboardModel &gameboard) const {
    return (*h)(gameboard)*f;
}

NonAdmissibleHeuristic::~NonAdmissibleHeuristic() {
    delete h;
}

