// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/TerminalGUI.h"

class TerminalGUI;

class TerminalGUIDrawable {
public:
    virtual void draw(TerminalGUI &terminal) = 0;
};
