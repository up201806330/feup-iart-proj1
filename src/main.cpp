// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <iostream>

#include "TerminalGUIColor.h"
#include "GameboardModel.h"
#include "GameboardView.h"
#include "ScoreboardModel.h"
#include "ScoreboardView.h"
#include "MainMenuModel.h"
#include "MainMenuView.h"

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
