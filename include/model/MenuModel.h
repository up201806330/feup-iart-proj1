// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <vector>
#include <string>

/**
 * @brief Menu model.
 */
class MenuModel {
public:
    /**
     * @brief Menu button.
     */
    struct Button {
        int id;             ///< @brief Button ID.
        std::string label;  ///< @brief Button label.
        /**
         * @brief Construct button from ID and label.
         *
         * @param id        ID
         * @param label     Label
         */
        Button(int id, std::string label);
    };
private:
    std::vector<Button> buttons;
public:
    /**
     * @brief Add button to menu.
     *
     * @param id    Button ID
     * @param label Label
     */
    void addButton(int id, const std::string &label);

    /**
     * @brief Get all buttons in a menu.
     *
     * @return Buttons of that menu.
     */
    const std::vector<Button>& getButtons() const;

    /**
     * @brief Check if menu has button with a certain ID.
     *
     * @param id    ID to check
     * @return      True if the menu has a button with that ID, false otherwise
     */
    bool hasButtonWithId(int id) const;
};
