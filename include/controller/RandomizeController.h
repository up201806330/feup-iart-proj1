// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

/**
 * @brief Menu controller.
 */
class RandomizeController {
private:
    std::vector<int> selectedOption;
public:
    /**
     * @brief Construct menu controller.
     */
    explicit RandomizeController();
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
    std::vector<int> getValues() const;
};
