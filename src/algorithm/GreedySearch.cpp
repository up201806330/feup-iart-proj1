// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/GreedySearch.h"

#include <unordered_map>
#include <queue>

using namespace std;
using Move = GameboardModel::Move;

GreedySearch::GreedySearch(Heuristics::heuristic_t heuristic):
    h(heuristic)
{
}

void GreedySearch::initialize(const GameboardModel &gameboardModel){
    unordered_set<GameboardModel> visited;
    unordered_map<GameboardModel, pair<GameboardModel, Move> > prev;

    GameboardModel g;
    {
        priority_queue<
                tuple<double, GameboardModel, Move, GameboardModel>,
                vector<tuple<double, GameboardModel, Move, GameboardModel> >,
                greater<>
        > q;
        q.emplace(h(gameboardModel), gameboardModel, Move(0, 0), gameboardModel);
        double c;
        GameboardModel g_prev;
        Move m(0, 0);
        vector<Move> moves;
        while (!q.empty()) {
            tie(c, g_prev, m, g) = q.top();
            q.pop();
            if (visited.count(g)) continue;
            visited.insert(g);
            prev.emplace(g, make_pair(g_prev, m));
            if (g.isGameOver()) break;
            moves = g.getAllMoves();
            for (const Move &m_new: moves) {
                GameboardModel g_new = g;
                g_new.move(m_new);
                q.emplace(h(g_new), g, m_new, g_new);
            }
        }
    }
    if (!g.isGameOver()) throw failed_to_find_solution("GreedySearch");
    {
        solution.clear();

        GameboardModel g_prev;
        Move m(0, 0);
        while (g != gameboardModel) {
            tie(g_prev, m) = prev.at(g);
            solution.push_front(m);
            g = g_prev;
        }
    }
}

GameboardModel::Move GreedySearch::next() {
    Move ret = solution.front(); solution.pop_front();
    return ret;
}
