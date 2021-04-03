#include "algorithm/BreadthFirstSearch.h"

using namespace std;
using Move = GameboardModel::Move;

bool BreadthFirstSearch::bfs(const GameboardModel& gameboardModel) {
    prev.clear();

    queue<GameboardModel> q;

    q.push(gameboardModel);
    prev.emplace(gameboardModel, GameboardModel::Move(0, 0));

    while(!q.empty()) {

        GameboardModel u = q.front();
        q.pop();

        if(u.isGameOver()) {
            finalState = u;
            return true;
        }

        vector<GameboardModel::Move> moves = u.getAllMoves();

        for(const GameboardModel::Move& m: moves) {
            GameboardModel v = u;
            v.move(m);
            if(!prev.count(v)) {
                q.push(v);
                prev.emplace(v, m);
            }
             
        }
    }
   
   return false;
}

void BreadthFirstSearch::initialize(const GameboardModel &gameboard) {
    this->initialState = gameboard;
    
    if(!bfs(gameboard)) throw SearchStrategy::failed_to_find_solution("BreadthFirstSearch");

    GameboardModel v = finalState;
    while(v != this->initialState) {
        const Move &m = prev.at(v);
        solution.push(m);
        v.reverseMove(m);
    }

}

GameboardModel::Move BreadthFirstSearch::next() {

    GameboardModel::Move nextMove = (!solution.empty()) ? solution.top() : *new Move(0,0);
    solution.pop();
    return nextMove;
}

