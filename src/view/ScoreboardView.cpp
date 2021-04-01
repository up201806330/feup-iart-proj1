// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "view/ScoreboardView.h"

using namespace std;
typedef TerminalGUI::coord_t coord_t;
typedef TerminalGUI::pos_t pos_t;

ScoreboardView::ScoreboardView(const ScoreboardModel &scoreboardModel):
    _scoreboardModel(scoreboardModel)
{
}

void ScoreboardView::draw(TerminalGUI &terminal){
    int score = _scoreboardModel.getScore();
    char score_c_str[128];
    sprintf(score_c_str, "Score: %d", score);
    string score_str(score_c_str);

    terminal.drawStringAbsolute(pos_t(0,0), score_str);
}
