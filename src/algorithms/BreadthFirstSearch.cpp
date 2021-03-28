#include "algorithm/BreadthFirstSearch.h"

vector<GameboardModel::Move> BreadthFirstSearch::getPath() {
    return this->pathMoves;
}

bool BreadthFirstSearch::bfs(const GameboardModel& gameboardModel) {

    queue<GameboardModel::Move> auxPathMoves;
    queue<GameboardModel> auxPathState;
    
    auxPathState.push(gameboardModel);

    do {

        GameboardModel currentState = auxPathState.front();
        auxPathState.pop();

        if(this->visited.count(currentState) == 1) {
            continue;
        }

        if(currentState.isGameOver()) {
            cout << "Descobriu" << endl;
            return true;
        }
       
        for(size_t i=0; i<currentState.getAllMoves().size(); i++) {
           auxPathMoves.push(currentState.getAllMoves()[i]); 
        }

        for(size_t i=0; i<currentState.getAdjacentStates().size(); i++) {
           auxPathState.push(currentState.getAdjacentStates()[i]); 
        }

        this->pathMoves.push_back(auxPathMoves.front());
        auxPathMoves.pop();
        this->visited.insert(currentState);

   }while(!auxPathMoves.empty());

   return false;
}

void BreadthFirstSearch::initialize(const GameboardModel &gameboard) {
    
    if(!bfs(gameboard)) throw SearchStrategy::failed_to_find_solution("BreadthFirstSearch");
}

GameboardModel::Move BreadthFirstSearch::next() {
    
    GameboardModel::Move nextMove = this->pathMoves[0];
    this->pathMoves.erase(this->pathMoves.begin());

    return nextMove;
}

