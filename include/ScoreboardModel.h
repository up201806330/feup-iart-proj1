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
