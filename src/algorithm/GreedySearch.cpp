// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/GreedySearch.h"

#include <map>
#include <queue>

using namespace std;
using Move = GameboardModel::Move;

GreedySearch::GreedySearch(const Heuristic *heuristic):
    h(heuristic)
{
}

void GreedySearch::initialize(const GameboardModel &src){
    set<GameboardModel> visited;
    map<GameboardModel, Move> prev;

    GameboardModel finalGameboard = src;
    {
        priority_queue<
            pair<double, GameboardModel>,
            vector< pair<double, GameboardModel> >,
            greater<>
        > q;

        prev.emplace(src, Move(0,0));
        q.emplace((*h)(src), src);

        GameboardModel u;
        while (!q.empty()) {
            u = q.top().second;
            q.pop();

            if (u.isGameOver()){
                finalGameboard = u;
                break;
            }

            if (visited.count(u)) continue;
            visited.insert(u);

            vector<Move> moves = u.getAllMoves();
            for (const Move &e: moves) {
                GameboardModel v = u;
                v.move(e);
                if(!visited.count(v)) {
                    prev.emplace(v, e);
                    q.emplace((*h)(v), v);
                }
            }
        }
    }
    if (!finalGameboard.isGameOver()) throw failed_to_find_solution("GreedySearch");
    {
        solution.clear();

        GameboardModel v = finalGameboard;
        while (v != src) {
            const Move &m = prev.at(v);
            solution.push_front(m);
            v.reverseMove(m);
        }
    }
}

GameboardModel::Move GreedySearch::next() {
    Move ret = solution.front(); solution.pop_front();
    return ret;
}

GreedySearch::~GreedySearch() {
    delete h;
}
