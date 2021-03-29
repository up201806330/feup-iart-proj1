// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief Choose strategy to be used to search for solution.
 */
class ChooseStrategyState: public State {
private:
    SearchStrategy *strategy = nullptr;
public:
    explicit ChooseStrategyState(TerminalGUI *term);

    /**
     * @brief Set search strategy.
     *
     * @param search    Search strategy to be used
     */
    void setSearchStrategy(SearchStrategy *search);
    /**
     * @brief Get search strategy.
     *
     * @return Search strategy to be used
     */
    SearchStrategy *getSearchStrategy() const;

    State* run() override;
};
