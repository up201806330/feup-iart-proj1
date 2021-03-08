#include "TerminalGUI.h"

using namespace std;

TerminalGUI::pos_t::pos_t(TerminalGUI::coord_t x_, TerminalGUI::coord_t y_):x(x_),y(y_){}

TerminalGUI::pos_t TerminalGUI::pos_t::operator+(const TerminalGUI::pos_t &p) const { return {x+p.x, y+p.y}; }
TerminalGUI::pos_t TerminalGUI::pos_t::operator-(const TerminalGUI::pos_t &p) const { return {x-p.x, y-p.y}; }
TerminalGUI::pos_t TerminalGUI::pos_t::operator/(TerminalGUI::coord_t c) const { return {x/c, y/c}; }

using pos_t = TerminalGUI::pos_t;
using Color = TerminalGUI::Color;
using effects_t = TerminalGUI::effects_t;

const std::list<TerminalGUI::ToDrawTypedef>&
    TerminalGUI::getToDraw() const{ return to_draw; }

void TerminalGUI::setCorner(pos_t corner_pos){
    this->corner = corner_pos;
}

void TerminalGUI::clear(){
    to_draw.clear();
}

void TerminalGUI::drawCharacter(
    pos_t pos,
    string c,
    Color foreground,
    Color background,
    effects_t effects
){
    drawCharacterAbsolute(pos-corner, c, foreground, background, effects);
}

void TerminalGUI::drawCharacterAbsolute(
    pos_t pos,
    string c,
    Color foreground,
    Color background,
    effects_t effects
){
    to_draw.push_back(ToDrawTypedef(pos, c, foreground, background, effects));
}

void TerminalGUI::drawString(
    pos_t pos,
    string s,
    Color foreground,
    Color background,
    effects_t effects
){
    drawStringAbsolute(pos-corner, s, foreground, background, effects);
}

void TerminalGUI::drawStringAbsolute(
    pos_t pos,
    string s,
    Color foreground,
    Color background,
    effects_t effects
){
    pos_t p(0,0);
    for(const char &c: s){
        if(c == '\n') p = pos_t(0, p.y+1);
        else {
            to_draw.push_back(ToDrawTypedef(pos+p, string(1, c), foreground, background, effects));
            ++p.x;
        }
    }
}

