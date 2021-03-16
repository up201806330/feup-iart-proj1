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
