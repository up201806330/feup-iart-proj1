// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "TerminalGUIColor.h"

#include <vector>

using namespace std;

const string EFFECT_RESET_ALL         = "\033[0m";
const string EFFECT_BOLD              = "\033[1m";
const string EFFECT_UNDERLINED        = "\033[4m";
const string EFFECT_INVERSE           = "\033[7m";
const string EFFECT_BOLD_OFF          = "\033[21m";
const string EFFECT_UNDERLINED_OFF    = "\033[24m";
const string EFFECT_INVERSE_OFF       = "\033[27m";
const string COLOR_FOREGROUND_BLACK   = "\033[30m";
const string COLOR_FOREGROUND_RED     = "\033[31m";
const string COLOR_FOREGROUND_GREEN   = "\033[32m";
const string COLOR_FOREGROUND_YELLOW  = "\033[33m";
const string COLOR_FOREGROUND_BLUE    = "\033[34m";
const string COLOR_FOREGROUND_MAGENTA = "\033[35m";
const string COLOR_FOREGROUND_CYAN    = "\033[36m";
const string COLOR_FOREGROUND_WHITE   = "\033[37m";
const string COLOR_FOREGROUND_DEFAULT = "\033[39m";
const string COLOR_BACKGROUND_BLACK   = "\033[40m";
const string COLOR_BACKGROUND_RED     = "\033[41m";
const string COLOR_BACKGROUND_GREEN   = "\033[42m";
const string COLOR_BACKGROUND_YELLOW  = "\033[43m";
const string COLOR_BACKGROUND_BLUE    = "\033[44m";
const string COLOR_BACKGROUND_MAGENTA = "\033[45m";
const string COLOR_BACKGROUND_CYAN    = "\033[46m";
const string COLOR_BACKGROUND_WHITE   = "\033[47m";
const string COLOR_BACKGROUND_DEFAULT = "\033[49m";
// const string COLOR_FOREGROUND_WHITE   = "\033[97m";
// const string COLOR_BACKGROUND_WHITE   = "\033[107m";

string getForegroundColor(TerminalGUI::Color c){
    switch(c){
        case TerminalGUI::Color::DEFAULT: return COLOR_FOREGROUND_DEFAULT;
        case TerminalGUI::Color::BLACK  : return COLOR_FOREGROUND_BLACK  ;
        case TerminalGUI::Color::WHITE  : return COLOR_FOREGROUND_WHITE  ;
        case TerminalGUI::Color::RED    : return COLOR_FOREGROUND_RED    ;
        case TerminalGUI::Color::GREEN  : return COLOR_FOREGROUND_GREEN  ;
        case TerminalGUI::Color::BLUE   : return COLOR_FOREGROUND_BLUE   ;
        case TerminalGUI::Color::CYAN   : return COLOR_FOREGROUND_CYAN   ;
        case TerminalGUI::Color::MAGENTA: return COLOR_FOREGROUND_MAGENTA;
        case TerminalGUI::Color::YELLOW : return COLOR_FOREGROUND_YELLOW ;
        default: throw invalid_argument("");
    }
}

string getBackgroundColor(TerminalGUI::Color c){
    switch(c){
        case TerminalGUI::Color::DEFAULT: return COLOR_BACKGROUND_DEFAULT;
        case TerminalGUI::Color::BLACK  : return COLOR_BACKGROUND_BLACK  ;
        case TerminalGUI::Color::WHITE  : return COLOR_BACKGROUND_WHITE  ;
        case TerminalGUI::Color::RED    : return COLOR_BACKGROUND_RED    ;
        case TerminalGUI::Color::GREEN  : return COLOR_BACKGROUND_GREEN  ;
        case TerminalGUI::Color::BLUE   : return COLOR_BACKGROUND_BLUE   ;
        case TerminalGUI::Color::CYAN   : return COLOR_BACKGROUND_CYAN   ;
        case TerminalGUI::Color::MAGENTA: return COLOR_BACKGROUND_MAGENTA;
        case TerminalGUI::Color::YELLOW : return COLOR_BACKGROUND_YELLOW ;
        default: throw invalid_argument("");
    }
}

TerminalGUIColor::TerminalGUIColor(FILE *ofile): TerminalGUIFile(ofile){}

void TerminalGUIColor::display(){
    pos_t size = this->getSize();
    typedef tuple<string, Color, Color, effects_t> ToDrawNoPosTypedef;
    vector<vector<ToDrawNoPosTypedef> > v(
        size.x,
        vector<ToDrawNoPosTypedef>(
            size.y,
            ToDrawNoPosTypedef(" ", DEFAULT, DEFAULT, 0)
        )
    );

    const list<ToDrawTypedef> &toDraw = this->getToDraw();
    for(const ToDrawTypedef &t: toDraw){
        pos_t pos;
        string c;
        Color foreground, background;
        effects_t effects;
        tie(pos, c, foreground, background, effects) = t;
        if(pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y) continue;
        v[pos.x][pos.y] = ToDrawNoPosTypedef(c, foreground, background, effects);
    }

    string s = EFFECT_RESET_ALL;
    for(coord_t y = 0; y < size.y-1; ++y){
        for(coord_t x = 0; x < size.x; ++x){
            string c;
            Color f, b;
            effects_t e;
            tie(c, f, b, e) = v[x][y];
            s += getForegroundColor(f);
            s += getBackgroundColor(b);
            if(e & Effects::BOLD      ){ s += EFFECT_BOLD      ; }
            if(e & Effects::UNDERLINED){ s += EFFECT_UNDERLINED; }
            s += c;
            s += EFFECT_RESET_ALL;
        }
        s += '\n';
    }
    fprintf(getFile(), "%s", s.c_str());
}
