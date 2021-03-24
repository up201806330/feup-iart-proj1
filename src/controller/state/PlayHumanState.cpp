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

    int option = -1;
    string s;
    while(true) {
        getTerminal()->clear();
        gameboardView.draw(*getTerminal());
        scoreboardView.draw(*getTerminal());

        getTerminal()->display();

        getline(cin, s);
        stringstream ss(s);
        ss >> option;
        if(option == 0) break;
    }

    return State::mainMenuState;
}
