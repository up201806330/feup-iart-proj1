// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <iostream>
#include <sstream>

#include "model/GameboardModel.h"
#include "model/ScoreboardModel.h"
#include "view/GameboardView.h"
#include "view/ScoreboardView.h"
#include "controller/state/PlayHumanState.h"
#include "algorithm/DepthFirstGreedySearch.h"
#include "algorithm/heuristics/AdmissibleHeuristic.h"

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

    SearchStrategy *search = new DepthFirstGreedySearch(new AdmissibleHeuristic());

    int fr = 0, to = 0;
    bool invalidMove = false;
    bool askedForHint = false;
    string s;
    while(true) {
        getTerminal()->clear();
        gameboardView.draw(*getTerminal());
        scoreboardView.draw(*getTerminal());
        if(invalidMove){
            getTerminal()->drawStringAbsolute(pos_t(0, getTerminal()->getSize().y-2), "Invalid move");
            invalidMove = false;
        }
        if(askedForHint){
            search->initialize(gameboard);
            GameboardModel::Move m = search->next();
            getTerminal()->drawStringAbsolute(pos_t(0, getTerminal()->getSize().y-2), "Asked for a hint. Try " + to_string(m.from) + " " + to_string(m.to));
            askedForHint = false;
        }

        getTerminal()->display();

        getline(cin, s);
        if(s == "h"){
            askedForHint = true;
            continue;
        }

        stringstream ss(s);
        ss >> fr;
        if(fr == -1) break;
        ss >> to;
        GameboardModel::Move move(static_cast<size_t>(fr), static_cast<size_t>(to));

        if(gameboard.canMove(move)) {
            gameboard.move(move);
            scoreboard.addScore();
        } else {
            invalidMove = true;
        }

        if(gameboard.isGameOver()){
            break;
        }
    }

    delete search;

    return State::mainMenuState;
}

PlayHumanState::~PlayHumanState() = default;
