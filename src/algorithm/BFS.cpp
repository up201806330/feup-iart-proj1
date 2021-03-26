#include "algorithm/BFS.h"

BFS::BFS(const GameboardModel& initialBoard): 
    _initialBoard(initialBoard) {
    
}

vector<GameboardModel> BFS::getPath() {
    return this->path;
}

void BFS::bfs_algorithm() {

    queue<GameboardModel> aux;
    aux.push(this->_initialBoard);
    
    while(!aux.empty()) {
        
        GameboardModel currentGameboardState = aux.front();
        aux.pop();

        for(size_t i=0; i<this->path.size(); i++) {
            if(currentGameboardState == this->path[i]) {
                continue;
            }
        }

        if(currentGameboardState.isGameOver()) {
            this->_finalBoard = currentGameboardState;
            return;
        }

        vector<GameboardModel> allStatesFromCurrent = currentGameboardState.getAdjacentStates();

        for(size_t i=0; i<allStatesFromCurrent.size(); i++) {
            aux.push(allStatesFromCurrent[i]);
        }

        path.push_back(currentGameboardState);
    }
}

