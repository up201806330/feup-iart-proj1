// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <chrono>

/**
 * @brief Scoreboard model.
 */
class ScoreboardModel {
private:
    int score = 0;
public:
    /**
     * @brief Construct scoreboard model.
     */
    ScoreboardModel();
    /**
     * @brief Reset score.
     */
    void resetScore();
    /**
     * @brief Increment score.
     */
    void addScore();
    /**
     * @brief Get score
     *
     * @return  Score
     */
    int getScore() const;
};
