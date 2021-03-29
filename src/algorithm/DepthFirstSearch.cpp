// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/DepthFirstSearch.h"

using namespace std;

using Move = GameboardModel::Move;

bool DepthFirstSearch::dfs(const GameboardModel& gameBoard) {
    if (visited.count(gameBoard)) return false;

    visited.insert(gameBoard);

    if (gameBoard.isGameOver()) return true;

    vector<Move> moves = gameBoard.getAllMoves();
    for (const Move &move : moves){
        GameboardModel state = gameBoard;
        state.move(move);
        solution.push_back(move);
        if (dfs(state)) return true;
        solution.pop_back();
    }

    return false;
}

void DepthFirstSearch::initialize(const GameboardModel &gameboardModel){
    visited.clear();

    if (!dfs(gameboardModel)) throw SearchStrategy::failed_to_find_solution("DepthFirstSearch");
}

GameboardModel::Move DepthFirstSearch::next() {
    Move ret = solution.front(); solution.pop_front();
    return ret;
}
