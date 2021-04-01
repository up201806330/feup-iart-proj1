// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "model/ScoreboardModel.h"

using namespace std;

ScoreboardModel::ScoreboardModel() = default;

void ScoreboardModel::resetScore(){
    score = 0;
}

void ScoreboardModel::addScore(){
    ++score;
}
 
int ScoreboardModel::getScore() const {
    return score;
}
