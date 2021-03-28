#pragma once

#include <queue>
#include <vector>
#include "Search.h"

using namespace std;

class BFS : public Search {
private:
    GameboardModel _initialBoard;
    GameboardModel _finalBoard;
    vector<GameboardModel::Move> pathMoves;
public:
    vector<GameboardModel::Move> getPath();
    void initialize(const GameboardModel &gameboard);
    GameboardModel::Move next();
};
