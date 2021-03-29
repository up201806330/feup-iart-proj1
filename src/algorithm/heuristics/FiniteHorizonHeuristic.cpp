// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/heuristics/FiniteHorizonHeuristic.h"

using namespace std;

FiniteHorizonHeuristic::FiniteHorizonHeuristic(const Heuristic *baseHeuristic, size_t horizon):
    depth(horizon)
{
    if(depth <= 1) h = baseHeuristic;
    else           h = new FiniteHorizonHeuristic(baseHeuristic, depth - 1);
}

Heuristic::heuristic_t FiniteHorizonHeuristic::operator()(const GameboardModel &gameboard) const {
    if(gameboard.isGameOver()) return 0.0;
    vector<GameboardModel> adj = gameboard.getAdjacentStates();
    Heuristic::heuristic_t best = INF;
    for(const GameboardModel &g: adj) {
        best = min(best, (*h)(g));
        if(best <= 0.0) return best+1;
    }
    return best+1;
}
