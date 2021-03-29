// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/IterativeDeepeningSearch.h"

using namespace std;

using Move = GameboardModel::Move;

bool IterativeDeepeningSearch::dfs(const GameboardModel& gameBoard, size_t depth) {
    if (depth > maxDepth) return false;

    if (visited.count(gameBoard)) return false;

    visited.insert(gameBoard);

    if (gameBoard.isGameOver()) return true;

    vector<Move> moves = gameBoard.getAllMoves();
    for (const Move &move : moves){
        GameboardModel state = gameBoard;
        state.move(move);
        solution.push_back(move);
        if (dfs(state, depth + 1)) return true;
        solution.pop_back();
    }

    return false;
}

void IterativeDeepeningSearch::initialize(const GameboardModel &gameboardModel){
    maxDepth = 0;
    visited.clear();

    while (!dfs(gameboardModel, 0)){
        ++maxDepth;
        solution.clear();
        visited.clear();
    }
}

GameboardModel::Move IterativeDeepeningSearch::next() {
    Move ret = solution.front(); solution.pop_front();
    return ret;
}
