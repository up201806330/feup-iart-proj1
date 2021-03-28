#pragma once

#include <queue>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"

using namespace std;

class BreadthFirstSearch : public SearchStrategy {
private:
   vector<GameboardModel::Move> pathMoves;
   unordered_set<GameboardModel> visited;
public:
    vector<GameboardModel::Move> getPath();
    bool bfs(const GameboardModel& GameboardModel);
    void initialize(const GameboardModel &gameboard) override;
    GameboardModel::Move next() override;
};
