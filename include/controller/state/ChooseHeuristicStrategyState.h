// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "State.h"

/**
 * @brief Having chosen an heuristic, now choose an informed search algorithm to use that heuristic.
 */
class ChooseHeuristicStrategyState: public State {
private:
    const Heuristic *h = nullptr;
public:
    explicit ChooseHeuristicStrategyState(TerminalGUI *term);

    /**
     * @brief Set search strategy.
     *
     * Forwards the search strategy to ChooseStrategyState::setSearchStrategy.
     *
     * @param search    Search strategy
     */
    void setSearchStrategy(SearchStrategy *search);
    /**
     * @brief Get search strategy.
     *
     * Requests the search strategy from ChooseStrategyState::getSearchStrategy.
     *
     * @return  Search strategy
     */
    SearchStrategy *getSearchStrategy() const;

    State* run() override;
};
