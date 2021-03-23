// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "MainMenuModel.h"

MainMenuModel::MainMenuModel(){
    addButton("1. Play"             , [](){});
    addButton("2. Autonomous player", [](){});
    addButton("3. About"            , [](){});
    addButton("4. Exit"             , [](){});
}
