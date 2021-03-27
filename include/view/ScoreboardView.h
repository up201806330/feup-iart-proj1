// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/ScoreboardModel.h"
#include "view/gui/TerminalGUI.h"

class ScoreboardView {
private:
    const ScoreboardModel &_scoreboardModel;
public:
    explicit ScoreboardView(const ScoreboardModel &scoreboardModel);
    void draw(TerminalGUI &terminal);
};
