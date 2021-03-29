// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/GameboardModel.h"
#include "view/gui/TerminalGUI.h"

/**
 * @brief Gameboard view.
 */
class GameboardView {
private:
    const GameboardModel &_gameboardModel;
public:
    /**
     * @brief Construct gameboard view from gameboard model.
     *
     * @param gameboardModel Gameboard model
     */
    explicit GameboardView(const GameboardModel &gameboardModel);
    /**
     * @brief Draw view on terminal.
     *
     * @param terminal  Terminal to draw view to
     */
    void draw(TerminalGUI &terminal);
private:
    TerminalGUI::coord_t TUBE_MARGIN_X = 2;
    TerminalGUI::coord_t PIECE_MARGIN_Y = 1;
    TerminalGUI::coord_t PIECE_X = 5;
    TerminalGUI::coord_t PIECE_Y = 3;
    TerminalGUI::coord_t TUBE_PADDING_X = 2;
    TerminalGUI::coord_t TUBE_PADDING_Y = 1;
    void drawTube (TerminalGUI &terminal, size_t tube);
    void drawPiece(TerminalGUI &terminal, size_t tube, size_t place, color_t piece_color);
};
