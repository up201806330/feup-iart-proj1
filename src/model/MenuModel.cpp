// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "model/MenuModel.h"

#include <utility>

using namespace std;

MenuModel::Button::Button(int _id, std::string _label, void (*_func)()):
    id(_id),
    label(std::move(_label)),
    func(_func)
{
}

void MenuModel::addButton(int id, const string &label, void (*func)()){
    buttons.emplace_back(id, label, func);
}

const vector<MenuModel::Button>& MenuModel::getButtons() const {
    return buttons;
}
