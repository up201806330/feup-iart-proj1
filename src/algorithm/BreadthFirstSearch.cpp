#include "algorithm/BreadthFirstSearch.h"

using namespace std;

bool BreadthFirstSearch::bfs(const GameboardModel& gameboardModel) {
    prev.clear();

    queue<GameboardModel> q;
    
   
    q.push(gameboardModel);
    prev.emplace(gameboardModel, make_pair(gameboardModel, GameboardModel::Move(0, 0)));

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
                prev.emplace(v, make_pair(u, m)); 
            }
             
        }
    }
   
   return false;
}

void BreadthFirstSearch::initialize(const GameboardModel &gameboard) {
    this->initialState = gameboard;
    
    if(!bfs(gameboard)) throw SearchStrategy::failed_to_find_solution("BreadthFirstSearch");

    GameboardModel v = finalState;
    GameboardModel u;
    GameboardModel::Move m(0, 0);

    while(v != this->initialState) {
        tie(u, m) = prev.at(v);
        solution.push(m);
        v = u;           
    }

}

GameboardModel::Move BreadthFirstSearch::next() {
    
    GameboardModel::Move nextMove = solution.top();
    solution.pop();

    return nextMove;
}

