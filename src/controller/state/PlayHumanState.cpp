// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <iostream>
#include <sstream>

#include "model/GameboardModel.h"
#include "model/ScoreboardModel.h"
#include "view/GameboardView.h"
#include "view/ScoreboardView.h"
#include "controller/state/PlayHumanState.h"

using namespace std;
using pos_t = TerminalGUI::pos_t;

PlayHumanState::PlayHumanState(TerminalGUI *term) : State(term) {
}

State *PlayHumanState::run() {
    getTerminal()->setCorner(pos_t(0,0));

    GameboardModel gameboard(5, 4);
    gameboard.fillRandom(3);
    ScoreboardModel scoreboard;

    GameboardView gameboardView(gameboard);
    ScoreboardView scoreboardView(scoreboard);

    int fr = 0, to = 0;
    bool invalidMove = false;
    string s;
    while(true) {
        getTerminal()->clear();
        gameboardView.draw(*getTerminal());
        scoreboardView.draw(*getTerminal());
        if(invalidMove){
            getTerminal()->drawStringAbsolute(pos_t(0, getTerminal()->getSize().y-2), "Invalid move");
            invalidMove = false;
        }

        getTerminal()->display();

        getline(cin, s);
        stringstream ss(s);
        ss >> fr;
        if(fr == -1) break;
        ss >> to;
        GameboardModel::Move move(static_cast<size_t>(fr), static_cast<size_t>(to));

        if(gameboard.canMove(move)) {
            gameboard.move(move);
        } else {
            invalidMove = true;
        }

        if(gameboard.isGameOver()){
            break;
        }
    }

    return State::mainMenuState;
}
