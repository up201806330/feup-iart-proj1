// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "ScoreboardModel.h"
#include "TerminalGUI.h"

class ScoreboardView {
private:
    const ScoreboardModel &_scoreboardModel;
public:
    ScoreboardView(const ScoreboardModel &scoreboardModel);
    void draw(TerminalGUI &terminal);
};
