// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "ScoreboardView.h"

using namespace std;
typedef TerminalGUI::coord_t coord_t;
typedef TerminalGUI::pos_t pos_t;

ScoreboardView::ScoreboardView(const ScoreboardModel &scoreboardModel):
    _scoreboardModel(scoreboardModel)
{
}

void ScoreboardView::draw(TerminalGUI &terminal){
    int score = _scoreboardModel.getScore();
    char score_cstr[128];
    sprintf(score_cstr, "Score: %d", score);
    string score_str(score_cstr);

    terminal.drawStringAbsolute(pos_t(0,0), score_str);
}
