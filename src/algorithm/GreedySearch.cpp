// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/GreedySearch.h"

using namespace std;
using Move = GameboardModel::Move;

const double INF = 1000000000000.0;

GreedySearch::GreedySearch(GreedySearch::heuristic_t heuristic):
    h(heuristic)
{
}

void GreedySearch::initialize(const GameboardModel &gameboardModel){
    gameboard = gameboardModel;

    visited.clear();
    GameboardModel g = gameboard;
    visited.insert(g);
    while(!g.isGameOver()){
        Move bestMove(0, 0);
        GameboardModel bestGameboard;
        {
            double bestScore = -INF;

            GameboardModel g_;
            double score;
            vector<Move> availableMoves = g.getAllMoves();
            for (const Move &m: availableMoves) {
                g_ = g;
                g_.move(m);
                score = h(g_);
                if (score > bestScore) {
                    bestMove = m;
                    bestGameboard = g_;
                    bestScore = score;
                }
            }
        }

        if(visited.count(bestGameboard)) throw Search::failed_to_find_solution("GreedySearch");
        visited.insert(bestGameboard);
        moves.push(bestMove);

        g = bestGameboard;
    }
}

GameboardModel::Move GreedySearch::next() {
    Move ret = moves.front(); moves.pop();
    return ret;
}
