#pragma once

#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"

/**
 * @brief Breadth-first Search
 * 
 * Keep track of visited nodes (nodes added to the path so far) so as to avoid cycles
 * 
 */
class BreadthFirstSearch : public SearchStrategy {
private:
    std::stack<GameboardModel::Move> solution;
    GameboardModel initialState;
    GameboardModel finalState;
    std::unordered_map<GameboardModel, std::pair<GameboardModel, GameboardModel::Move>> prev;
public:
    bool bfs(const GameboardModel& GameboardModel);
    void initialize(const GameboardModel &gameboard) override;
    GameboardModel::Move next() override;
};
