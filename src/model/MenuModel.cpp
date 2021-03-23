// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "MenuModel.h"

using namespace std;

void MenuModel::addButton(const string &label, void (*func)()){
    buttons.push_back(make_pair(label, func));
}

const vector< pair<string, void (*)()> >& MenuModel::getButtons() const {
    return buttons;
}
