#include "ScoreboardModel.h"

using namespace std;

using hrc = chrono::high_resolution_clock;

ScoreboardModel::ScoreboardModel(){}

void ScoreboardModel::resetScore(){
    score = 0;
}

void ScoreboardModel::addScore(){
    ++score;
}
 
int ScoreboardModel::getScore() const {
    return score;
}
