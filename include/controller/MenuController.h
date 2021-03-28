// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/MenuModel.h"

class MenuController {
private:
    const MenuModel &_menuModel;
    int selectedOption = -1;
public:
    explicit MenuController(const MenuModel &menuModel);
    void run();
    int getSelectedOption() const;
};
