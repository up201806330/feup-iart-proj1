// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/TerminalGUI.h"

/**
 * @brief About view.
 */
class AboutView {
private:
public:
    /**
     * @brief Construct about view.
     */
    explicit AboutView();
    /**
     * @brief Draw view on terminal.
     *
     * @param terminal  Terminal to draw view to
     */
    void draw(TerminalGUI &terminal);
};
