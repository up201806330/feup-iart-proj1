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

using namespace std;

int main(){
    TerminalGUI *gui = new TerminalGUIColor();

    MainMenuModel mainMenuModel;

    MainMenuView mainMenuView(mainMenuModel);
    mainMenuView.draw(*gui);

    gui->display();
    
    return 0;
}
