#include "algorithms/BFS.h"

vector<GameboardModel::Move> BFS::getPath() {
    return this->pathMoves;
}

void BFS::initialize(const GameboardModel &gameboard) {
    this->_initialBoard = gameboard;
    
    queue<GameboardModel::Move> auxPathMoves;
    queue<GameboardModel> auxPathState;
    
    auxPathState.push(_initialBoard);

    do {

        GameboardModel currentState = auxPathState.front();
        auxPathState.pop();

        if(currentState.isGameOver()) {
            this->_finalBoard = currentState;
            return;
        }
       
        for(int i=0; i<currentState.getAllMoves().size(); i++) {
           auxPathMoves.push(currentState.getAllMoves()[i]); 
        }

        for(int i=0; i<currentState.getAdjacentStates().size(); i++) {
           auxPathState.push(currentState.getAdjacentStates()[i]); 
        }

        this->pathMoves.push_back(auxPathMoves.front());
        auxPathMoves.pop();

   }while(!auxPathMoves.empty());
}

GameboardModel::Move BFS::next() {
    
    GameboardModel::Move nextMove = this->pathMoves[0];
    this->pathMoves.erase(this->pathMoves.begin());

    return nextMove;
}

