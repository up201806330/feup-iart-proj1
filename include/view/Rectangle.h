// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/GameboardView.h"

/**
 * @brief Rectangle.
 */
class Rectangle : public TerminalGUIDrawable {
public:
    /**
     * @brief Rectangle border modes.
     */
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
    /**
     * @brief Construct rectangle from upper-left corner position, and size.
     *
     * @param pos   Position of upper-left corner
     * @param size  Size of rectangle
     */
    Rectangle(const TerminalGUI::pos_t &pos, const TerminalGUI::pos_t &size);

    /**
     * @brief Set rectangle position.
     *
     * @param pos Position.
     */
    void setPosition(const TerminalGUI::pos_t &pos);
    /**
     * @brief Get position of the rectangle's upper-left corner.
     *
     * @return Rectangle position.
     */
    const TerminalGUI::pos_t &getPosition();

    /**
     * @brief Set rectangle size.
     *
     * @param sz Rectangle size
     */
    void setSize(const TerminalGUI::pos_t &sz);
    /**
     * @brief Get rectangle size.
     *
     * @return Rectangle size
     */
    TerminalGUI::pos_t getSize();

    /**
     * @brief Draw rectangle on terminal.
     *
     * @param terminal  Terminal to draw view to
     */
    void draw(TerminalGUI &terminal) override;

    /**
     * @brief Set rectangle border mode.
     *
     * @param m     Rectangle border mode.
     */
    void setMode(Mode m);
};
