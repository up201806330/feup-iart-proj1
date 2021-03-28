// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/TerminalGUI.h"
#include "model/MainMenuModel.h"
#include "view/MenuView.h"

class MainMenuView {
private:
    MenuView menuView;
public:
    explicit MainMenuView(const MainMenuModel &mainMenuModel);
    void draw(TerminalGUI &terminal);
};
