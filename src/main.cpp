// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <iostream>

#include "view/gui/TerminalGUIColor.h"
#include "model/GameboardModel.h"
#include "view/GameboardView.h"
#include "model/ScoreboardModel.h"
#include "view/ScoreboardView.h"
#include "model/MainMenuModel.h"
#include "view/MainMenuView.h"

#include <unistd.h>
#include "controller/state/State.h"

using namespace std;

int main(){
    TerminalGUI *terminal = new TerminalGUIColor();
    State::initializeStates(terminal);

    State *currentState = State::mainMenuState;
    while(currentState != nullptr){
        currentState = currentState->run();
    }
    
    return 0;
}
