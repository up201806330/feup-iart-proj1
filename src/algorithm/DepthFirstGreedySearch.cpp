// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/DepthFirstGreedySearch.h"

#include <algorithm>

using namespace std;
using Move = GameboardModel::Move;

bool DepthFirstGreedySearch::dfs(const GameboardModel& gameBoard) {
    if (visited.count(gameBoard)) return false;

    visited.insert(gameBoard);

    if (gameBoard.isGameOver()) return true;

    vector<Move> moves = gameBoard.getAllMoves();
    {
        vector<pair<double, Move> > moves_scores;
        for (const Move &move : moves) {
            GameboardModel state = gameBoard;
            state.move(move);
            double score = h(state);
            moves_scores.emplace_back(score, move);
        }
        sort(moves_scores.begin(), moves_scores.end());
        for (size_t i = 0; i < moves.size(); ++i)
            moves[i] = moves_scores[i].second;
    }
    for (const Move &move : moves){
        GameboardModel state = gameBoard;
        state.move(move);
        solution.push_back(move);
        if (dfs(state)) return true;
        solution.pop_back();
    }

    return false;
}

void DepthFirstGreedySearch::initialize(const GameboardModel &gameboardModel){
    visited.clear();

    if (!dfs(gameboardModel)) throw SearchStrategy::failed_to_find_solution("DepthFirstGreedySearch");
}

GameboardModel::Move DepthFirstGreedySearch::next() {
    Move ret = solution.front(); solution.pop_front();
    return ret;
}

DepthFirstGreedySearch::DepthFirstGreedySearch(Heuristic::heuristic_t heuristic):
    h(heuristic)
{
}
