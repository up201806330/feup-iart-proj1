// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <chrono>

class ScoreboardModel {
private:
    int score = 0;
public:
    ScoreboardModel();
    void resetScore();
    void addScore();
    int getScore() const;
};
