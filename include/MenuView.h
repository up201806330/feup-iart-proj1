// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "TerminalGUI.h"
#include "MenuModel.h"

class MenuView {
private:
    const MenuModel &_menuModel;

    TerminalGUI::pos_t position;
public:
    MenuView(const MenuModel &menuModel);
    void draw(TerminalGUI &terminal);

    void setPosition(const TerminalGUI::pos_t &pos);
    const TerminalGUI::pos_t& getPosition() const;
};
