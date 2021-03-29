// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/TerminalGUI.h"
#include "model/MenuModel.h"

/**
 * @brief Menu view.
 */
class MenuView {
private:
    const MenuModel &_menuModel;

    TerminalGUI::pos_t position;
public:
    /**
     * @brief Build menu view from menu model.
     *
     * @param menuModel Menu model
     */
    explicit MenuView(const MenuModel &menuModel);
    /**
     * @brief Draw view on terminal.
     *
     * @param terminal  Terminal to draw view to
     */
    void draw(TerminalGUI &terminal);

    /**
     * @brief Set menu position.
     *
     * @param pos Menu position
     */
    void setPosition(const TerminalGUI::pos_t &pos);
    /**
     * @brief Get menu position.
     *
     * @return Menu position
     */
    const TerminalGUI::pos_t& getPosition() const;
};
