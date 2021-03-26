#pragma once

#include <queue>
#include <vector>
#include "model/GameboardModel.h"

#include <bits/stdc++.h>

using namespace std;

class BFS {
private:
    const GameboardModel _initialBoard;
    const GameboardModel _finalBoard;
    vector<GameboardModel> path;
public:
    BFS(const GameboardModel& initialBoard);
    vector<GameboardModel> getPath();
    void bfs_algorithm();
};
