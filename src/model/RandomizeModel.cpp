// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "model/RandomizeModel.h"

RandomizeModel::RandomizeModel(){
    addButton(1, "1. Play"             );
    addButton(2, "2. Autonomous player");
    addButton(3, "3. About"            );
    addButton(0, "0. Exit"             );
}

bool RandomizeModel::acceptValues(size_t nTubes, size_t tubeH, size_t nColors, unsigned seed) {
    return nColors < nTubes;
}
