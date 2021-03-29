// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "model/MenuModel.h"

#include <utility>
#include <stdexcept>
#include <algorithm>

using namespace std;

MenuModel::Button::Button(int _id, std::string _label):
    id(_id),
    label(std::move(_label))
{
}

void MenuModel::addButton(int id, const string &label){
    if(hasButtonWithId(id)) throw invalid_argument("id");
    buttons.emplace_back(id, label);
}

const vector<MenuModel::Button>& MenuModel::getButtons() const {
    return buttons;
}

bool MenuModel::hasButtonWithId(int id) const {
    return any_of(buttons.begin(), buttons.end(), [id](const Button &b){ return b.id == id; });
}
