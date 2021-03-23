// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "TerminalGUI.h"
#include "MainMenuModel.h"
#include "MenuView.h"

class MainMenuView {
private:
    MenuView menuView;
public:
    MainMenuView(const MainMenuModel &mainMenuModel);
    void draw(TerminalGUI &terminal);
};
