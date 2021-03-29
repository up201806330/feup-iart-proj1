// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/TerminalGUI.h"

class TerminalGUI;

/**
 * @brief Terminal GUI drawable.
 */
class TerminalGUIDrawable {
public:
    /**
     * @brief Draw drawable in a certain terminal.
     *
     * @param terminal  Terminal to draw the drawable to.
     */
    virtual void draw(TerminalGUI &terminal) = 0;
};
