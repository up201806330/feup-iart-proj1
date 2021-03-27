#include "view/gui/TerminalGUISprite.h"

using namespace std;

using coord_t   = TerminalGUI::coord_t;
using pos_t     = TerminalGUI::pos_t;
using Color     = TerminalGUI::Color;
using effects_t = TerminalGUI::effects_t;

TerminalGUISprite::TerminalGUISprite(
    const vector<vector<string>> &cs,
    const vector<vector<Color>> &foregrounds,
    const vector<vector<Color>> &backgrounds,
    const vector<vector<effects_t>> &effects
){
    set(cs, foregrounds, backgrounds, effects);
}

void TerminalGUISprite::set(
    const vector<vector<string>> &cs,
    const vector<vector<Color>> &foregrounds,
    const vector<vector<Color>> &backgrounds,
    const vector<vector<effects_t>> &effects
){
    size_t R = cs.size();
    if(foregrounds.size() > R || backgrounds.size() > R || effects.size() > R) throw invalid_argument("");
    for(size_t y = 0; y < R; ++y){
        size_t C = cs[y].size();
        if(
            (foregrounds.size() > y && foregrounds[y].size() > C) ||
            (backgrounds.size() > y && backgrounds[y].size() > C) ||
            (effects    .size() > y && effects    [y].size() > C)
        ) throw invalid_argument("");
        for(size_t x = 0; x < C; ++x){
            Color     foreground = (foregrounds.size() <= y || foregrounds[y].size() <= x ? Color::DEFAULT : foregrounds[y][x]);
            Color     background = (backgrounds.size() <= y || backgrounds[y].size() <= x ? Color::DEFAULT : backgrounds[y][x]);
            effects_t effect     = (effects    .size() <= y || effects    [y].size() <= x ? 0              : effects    [y][x]);
            setCharacter(pos_t(coord_t(x), coord_t(y)), cs[y][x], foreground, background, effect);
        }
    }
}

void TerminalGUISprite::setCharacter(
    const pos_t &pos,
    const string &c,
    const Color &foreground,
    const Color &background,
    const effects_t &effects
){
    m[pos] = ToDrawNoPosTypedef(c, foreground, background, effects);
}

void TerminalGUISprite::setPosition(const pos_t &pos){
    this->position = pos;
}

void TerminalGUISprite::draw(TerminalGUI &terminal){
    string c;
    Color f, b;
    effects_t e;
    for(const auto &p: m){
        tie(c, f, b, e) = p.second;
        terminal.drawCharacter(position+p.first, c, f, b, e);
    }
}
