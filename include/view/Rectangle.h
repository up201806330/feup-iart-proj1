// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/GameboardView.h"

class Rectangle : public TerminalGUIDrawable {
public:
    enum Mode {
        NORMAL = 0,
        THICK  = 1,
        DASHED = 2,
        THICK_DASHED = 3,
        DOUBLE = 4,
    };
private:
    TerminalGUI::pos_t position;
    TerminalGUI::pos_t size;
    Mode mode = NORMAL;
public:
    Rectangle(const TerminalGUI::pos_t &pos, const TerminalGUI::pos_t &size);

    void setPosition(const TerminalGUI::pos_t &pos);

    void draw(TerminalGUI &terminal) override;

    const TerminalGUI::pos_t &getPosition();

    TerminalGUI::pos_t getSize();

    void setMode(Mode m);
};
