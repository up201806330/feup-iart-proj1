#include "TerminalGUI.h"

using namespace std;

TerminalGUI::pos_t::pos_t(TerminalGUI::coord_t x_, TerminalGUI::coord_t y_):x(x_),y(y_){}

TerminalGUI::pos_t TerminalGUI::pos_t::operator+(const TerminalGUI::pos_t &p) const { return {x+p.x, y+p.y}; }
TerminalGUI::pos_t TerminalGUI::pos_t::operator-(const TerminalGUI::pos_t &p) const { return {x-p.x, y-p.y}; }
TerminalGUI::pos_t TerminalGUI::pos_t::operator/(TerminalGUI::coord_t c) const { return {x/c, y/c}; }

const std::list<TerminalGUI::ToDrawTypedef>&
    TerminalGUI::getToDraw() const{ return to_draw; }

void TerminalGUI::setCorner(TerminalGUI::pos_t corner_pos){
    this->corner = corner_pos;
}

void TerminalGUI::clear(){
    to_draw.clear();
}

void TerminalGUI::drawCharacter(
    TerminalGUI::pos_t pos,
    string c,
    TerminalGUI::Color foreground,
    TerminalGUI::Color background,
    TerminalGUI::effects_t effects
){
    drawCharacterAbsolute(pos-corner, c, foreground, background, effects);
}

void TerminalGUI::drawCharacterAbsolute(
    TerminalGUI::pos_t pos,
    string c,
    TerminalGUI::Color foreground,
    TerminalGUI::Color background,
    TerminalGUI::effects_t effects
){
    to_draw.push_back(ToDrawTypedef(pos, c, foreground, background, effects));
}
