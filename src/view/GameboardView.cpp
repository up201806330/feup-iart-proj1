// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "view/GameboardView.h"

#include "view/gui/TerminalGUISprite.h"

using namespace std;
using coord_t = TerminalGUI::coord_t;
using pos_t   = TerminalGUI::pos_t;
using Color   = TerminalGUI::Color;

GameboardView::GameboardView(const GameboardModel &gameboardModel):
    _gameboardModel(gameboardModel)
{
}

void GameboardView::draw(TerminalGUI &terminal){
    for(size_t tube = 0; tube < _gameboardModel.size(); ++tube){
        drawTube(terminal, tube);
    }
    for(size_t i = 0; i < _gameboardModel.size(); ++i){
        const Tube &tube = _gameboardModel[i];
        for(size_t j = 0; j < tube.size(); ++j){
            drawPiece(terminal, i, j, tube[j]);
        }
    }
}

void GameboardView::drawPiece(TerminalGUI &terminal, size_t tube, size_t place, color_t piece_color){
    pos_t size(
        coord_t((PIECE_X+2*TUBE_PADDING_X)*_gameboardModel.size      () + TUBE_MARGIN_X*max(size_t(0), _gameboardModel.size      ()-1)),
        coord_t((PIECE_Y                 )*_gameboardModel.tubeHeight() + PIECE_MARGIN_Y*max(size_t(0), _gameboardModel.tubeHeight()-1))
    );

    pos_t pos0 = terminal.getSize()/2 + pos_t(-size.x, +size.y)/2 +
        pos_t(
            coord_t(tube*(PIECE_X+2*TUBE_PADDING_X+TUBE_MARGIN_X))+TUBE_PADDING_X,
            0
        );

    pos_t pos1 = pos0 + pos_t(
        0,
        coord_t(-(PIECE_Y+PIECE_MARGIN_Y)*place - PIECE_Y+PIECE_MARGIN_Y)
    );

    Color c = static_cast<TerminalGUI::Color>(piece_color);
    TerminalGUISprite sprite(
        {
            {"▄","█","█","█","▄"},
            {"█","█","█","█","█"},
            {"▀","█","█","█","▀"}
        },
        {
            {c,c,c,c,c},
            {c,c,c,c,c},
            {c,c,c,c,c}
        }
    );
    sprite.setPosition(pos1);
    terminal.draw(sprite);
}

void GameboardView::drawTube(TerminalGUI &terminal, size_t tube){
    pos_t size(
        coord_t((PIECE_X+2*TUBE_PADDING_X)*_gameboardModel.size      () + TUBE_MARGIN_X*max(size_t(0), _gameboardModel.size      ()-1)),
        coord_t((PIECE_Y                 )*_gameboardModel.tubeHeight() + PIECE_MARGIN_Y*max(size_t(0), _gameboardModel.tubeHeight()-1))
    );

    pos_t pos0 = terminal.getSize()/2 + pos_t(-size.x, +size.y)/2 +
        pos_t(
            coord_t(tube*(PIECE_X+2*TUBE_PADDING_X+TUBE_MARGIN_X)),
            0
        );
    terminal.drawCharacter(pos0 + pos_t(0                         ,TUBE_PADDING_Y), "╚");
    terminal.drawCharacter(pos0 + pos_t(PIECE_X+2*TUBE_PADDING_X-1,TUBE_PADDING_Y), "╝");
    for(coord_t x = 1; x < PIECE_X+2*TUBE_PADDING_X-1; ++x){
        terminal.drawCharacter(pos0+pos_t(x, TUBE_PADDING_Y), "═");
    }
    for(coord_t y = TUBE_PADDING_Y-1; y > -coord_t(_gameboardModel.tubeHeight()*(PIECE_Y+PIECE_MARGIN_Y)); --y){
        pos_t pos1 = pos0 + pos_t(0,y);
        terminal.drawCharacter(pos1+pos_t(0, 0), "║");
        terminal.drawCharacter(pos1+pos_t(PIECE_X+2*TUBE_PADDING_X-1, 0), "║");
    }
    terminal.drawCharacter(pos0 + pos_t(0                         , -coord_t(_gameboardModel.tubeHeight()*(PIECE_Y+PIECE_MARGIN_Y))), "╗");
    terminal.drawCharacter(pos0 + pos_t(PIECE_X+2*TUBE_PADDING_X-1, -coord_t(_gameboardModel.tubeHeight()*(PIECE_Y+PIECE_MARGIN_Y))), "╔");
}
