// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/ScoreboardModel.h"
#include "view/gui/TerminalGUI.h"

/**
 * @brief Scoreboard view.
 */
class ScoreboardView {
private:
    const ScoreboardModel &_scoreboardModel;
public:
    /**
     * @brief Construct scoreboard view from scoreboard model.
     *
     * @param scoreboardModel Scoreboard model
     */
    explicit ScoreboardView(const ScoreboardModel &scoreboardModel);
    /**
     * @brief Draw view on terminal.
     *
     * @param terminal  Terminal to draw view to
     */
    void draw(TerminalGUI &terminal);
};
