// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <view/MenuView.h>
#include "MenuModel.h"

/**
 * @brief Main menu model.
 */
class RandomizeModel : public MenuModel {
public:
    /**
     * @brief Construct main menu.
     */
    RandomizeModel();

    /**
     * @brief Check if input values are valid
     * @return True if all values are valid, false otherwise
     */
    bool acceptValues(size_t nTubes, size_t tubeH, size_t nColors, unsigned seed);
};
