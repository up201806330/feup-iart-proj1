// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/TerminalGUI.h"
#include "model/MainMenuModel.h"
#include "view/MenuView.h"

/**
 * @brief Main menu view.
 */
class MainMenuView {
private:
    MenuView menuView;
public:
    /**
     * @brief Build main menu view from main menu model (which is a menu model).
     *
     * @param mainMenuModel Main menu model.
     */
    explicit MainMenuView(const MainMenuModel &mainMenuModel);
    /**
     * @brief Draw view on terminal.
     *
     * @param terminal  Terminal to draw view to
     */
    void draw(TerminalGUI &terminal);
};
