// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "view/Rectangle.h"

using namespace std;
using coord_t = TerminalGUI::coord_t;
using pos_t   = TerminalGUI::pos_t;
using Color   = TerminalGUI::Color;

Rectangle::Rectangle(const pos_t & pos, const pos_t & sz): position(pos), size(sz) {
}

void Rectangle::setPosition(const pos_t &pos) {
    position = pos;
}

vector< vector< string > > boxDrawing = {
        {"┌","┏","┌","┏","╔"},
        {"┐","┓","┐","┓","╗"},
        {"└","┗","└","┗","╚"},
        {"┘","┛","┘","┛","╝"},
        {"─","━","╌","╍","═"},
        {"│","┃","┆","┇","║"}
};

void Rectangle::draw(TerminalGUI &terminal) {
    terminal.drawCharacter(getPosition() + pos_t(0            ,0            ), boxDrawing.at(0).at(mode));
    terminal.drawCharacter(getPosition() + pos_t(getSize().x-1,0            ), boxDrawing.at(1).at(mode));
    terminal.drawCharacter(getPosition() + pos_t(0            ,getSize().y-1), boxDrawing.at(2).at(mode));
    terminal.drawCharacter(getPosition() + pos_t(getSize().x-1,getSize().y-1), boxDrawing.at(3).at(mode));
    for(coord_t x = 1; x < getSize().x-1; ++x){
        terminal.drawCharacter(getPosition() + pos_t(x, 0            ), boxDrawing.at(4).at(mode));
        terminal.drawCharacter(getPosition() + pos_t(x, getSize().y-1), boxDrawing.at(4).at(mode));
    }
    for(coord_t y = 1; y < getSize().y-1; ++y){
        terminal.drawCharacter(getPosition() + pos_t(0            , y), boxDrawing.at(5).at(mode));
        terminal.drawCharacter(getPosition() + pos_t(getSize().x-1, y), boxDrawing.at(5).at(mode));
    }
}

const pos_t &Rectangle::getPosition() {
    return position;
}

void Rectangle::setSize(const pos_t &sz) {
    this->size = sz;
}

TerminalGUI::pos_t Rectangle::getSize() {
    return size;
}

void Rectangle::setMode(Rectangle::Mode m) {
    mode = m;
}
