// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "model/MenuModel.h"

#include <utility>

using namespace std;

MenuModel::Button::Button(int _id, std::string _label):
    id(_id),
    label(std::move(_label))
{
}

void MenuModel::addButton(int id, const string &label){
    buttons.emplace_back(id, label);
}

const vector<MenuModel::Button>& MenuModel::getButtons() const {
    return buttons;
}

bool MenuModel::hasButtonWithId(int id) const {
    for(const Button &b: getButtons())
        if(b.id == id) return true;
    return false;
}
