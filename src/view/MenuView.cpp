// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "MenuView.h"
#include "Rectangle.h"

using namespace std;
using coord_t = TerminalGUI::coord_t;
using pos_t   = TerminalGUI::pos_t;
using Color   = TerminalGUI::Color;

MenuView::MenuView(const MenuModel &menuModel):_menuModel(menuModel),position(pos_t(0,0))
{
}

void MenuView::draw(TerminalGUI &terminal){
    const pos_t BUTTON_PADDING(2, 0);
    const pos_t BUTTON_MARGIN (0, 0);
    const pos_t MENU_PADDING(1, 0);

    const vector< pair<string, void (*)()> > &v = _menuModel.getButtons();
    size_t maxTextSize = 0;
    for(size_t i = 0; i < v.size(); ++i) maxTextSize = max(maxTextSize, v[i].first.size());

    const pos_t TEXT_SIZE(coord_t(maxTextSize), 1);
    const pos_t BUTTON_SIZE = TEXT_SIZE + pos_t(2*BUTTON_PADDING.x + 2, 2*BUTTON_PADDING.y + 2);
    const pos_t MENU_SIZE = pos_t(
        BUTTON_SIZE.x + 2*MENU_PADDING.x + 2,
        BUTTON_SIZE.y * coord_t(v.size()) + BUTTON_MARGIN.y*coord_t(v.size()-1) + MENU_PADDING.y*2 + 2
    );

    Rectangle buttonRectangle(pos_t(0, 0), BUTTON_SIZE);
    
    for(size_t i = 0; i < v.size(); ++i){
        coord_t y = (BUTTON_SIZE.y + BUTTON_MARGIN.y)*coord_t(i) + 1 + MENU_PADDING.y;
        buttonRectangle.setPosition(getPosition() + pos_t(-BUTTON_SIZE.x/2, y));
        terminal.draw(buttonRectangle);
        terminal.drawString(getPosition() + pos_t(-TEXT_SIZE.x/2, y + 1 + BUTTON_PADDING.y), v[i].first);
    }

    Rectangle menuRectangle(getPosition() + pos_t(-MENU_SIZE.x/2, 0), MENU_SIZE);
    menuRectangle.setMode(Rectangle::Mode::THICK);
    terminal.draw(menuRectangle);
}

void MenuView::setPosition(const pos_t &pos) {
    position = pos;
}

const pos_t &MenuView::getPosition() const {
    return position;
}
