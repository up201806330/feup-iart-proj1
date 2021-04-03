// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "controller/state/PlayMachineState.h"

#include "model/ScoreboardModel.h"
#include "view/GameboardView.h"
#include "view/ScoreboardView.h"

using namespace std;
using pos_t = TerminalGUI::pos_t;

PlayMachineState::PlayMachineState(TerminalGUI *term) :
    State(term)
{
}

State *PlayMachineState::run() {
    SearchStrategy *searchStrategy = State::chooseMachineState->getSearchStrategy();

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

        if(gameboard.isGameOver()){
            break;
        }

        if(gameboard.canMove(move)) {
            gameboard.move(move);
            scoreboard.addScore();
        } else {
            return State::mainMenuState;
        }
    }

    return State::mainMenuState;
}

PlayMachineState::~PlayMachineState() = default;
