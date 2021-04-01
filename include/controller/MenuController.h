// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "model/MenuModel.h"

/**
 * @brief Menu controller.
 */
class MenuController {
private:
    const MenuModel &_menuModel;
    int selectedOption = -1;
public:
    /**
     * @brief Construct menu controller from menu model.
     *
     * @param menuModel Menu model
     */
    explicit MenuController(const MenuModel &menuModel);
    /**
     * @brief Run menu controller.
     *
     * Blocks until user chooses an option.
     */
    void run();
    /**
     * @brief Get option selected by user.
     *
     * Is not necessarily one of the options allowed by the menu model.
     *
     * @return  Selected option's ID
     */
    int getSelectedOption() const;
};
