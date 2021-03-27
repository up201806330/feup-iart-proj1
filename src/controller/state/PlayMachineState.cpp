// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "controller/state/PlayMachineState.h"

#include "model/GameboardModel.h"
#include "model/ScoreboardModel.h"
#include "view/GameboardView.h"
#include "view/ScoreboardView.h"

using namespace std;
using pos_t = TerminalGUI::pos_t;

PlayMachineState::PlayMachineState(TerminalGUI *term) :
    State(term)
{
}

void PlayMachineState::setSearchStrategy(SearchStrategy *strategy) {
    delete strategy;
    this->searchStrategy = strategy;
}

State *PlayMachineState::run() {
    getTerminal()->setCorner(pos_t(0,0));

    GameboardModel gameboard(5, 4);
    gameboard.fillRandom(3);
    ScoreboardModel scoreboard;

    GameboardView gameboardView(gameboard);
    ScoreboardView scoreboardView(scoreboard);

    searchStrategy->initialize(gameboard);

    while(true) {
        getTerminal()->clear();
        gameboardView.draw(*getTerminal());
        scoreboardView.draw(*getTerminal());

        getTerminal()->display();

        getchar();
        GameboardModel::Move move = searchStrategy->next();

        if(gameboard.canMove(move)) {
            gameboard.move(move);
        } else {
            return State::mainMenuState;
        }

        if(gameboard.isGameOver()){
            break;
        }
    }

    return State::mainMenuState;
}
