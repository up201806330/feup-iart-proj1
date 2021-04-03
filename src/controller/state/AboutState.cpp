// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "controller/state/AboutState.h"
#include "view/AboutView.h"

#include <iostream>

using namespace std;
using pos_t = TerminalGUI::pos_t;

AboutState::AboutState(TerminalGUI *term) :
    State(term)
{
}

State *AboutState::run() {
    AboutView aboutView;
    getTerminal()->clear();
    aboutView.draw(*getTerminal());
    getTerminal()->display();
    getchar();
    return State::mainMenuState;
}

AboutState::~AboutState() = default;
