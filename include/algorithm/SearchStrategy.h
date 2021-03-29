// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <stdexcept>
#include "model/GameboardModel.h"

/**
 * @brief Search strategy.
 *
 * Can be used to search for a solution to a gameboard.
 *
 * It must be initialized to a certain gamestate. Then, on each call to next() it will return a move. Assuming the
 * moves returned by next are consecutively applied to the gameboard supplied to initialize(const GameboardModel &),
 * there is a guarantee that, after a finite number of calls to next(), a final state will be reached. This behavior has
 * an exception when the search strategy cannot find a solution (not that there isn't a solution; the search strategy
 * was simply not able to find one); in this case, either initialize(const GameboardModel &) or next() raise the
 * failed_to_find_solution exception.
 */
class SearchStrategy {
public:
    /**
     * @brief Failed to find solution.
     *
     * Raised when a search strategy fails to find a solution.
     *
     * A solution is a path (a sequence of moves) from a given state to any final state.
     */
    class failed_to_find_solution: public std::logic_error {
    public:
        /**
         * @brief Construct failed_to_find_solution from string description.
         *
         * @param what_arg  Description
         */
        explicit failed_to_find_solution(const std::string &what_arg);
    };
public:
    /**
     * @brief Initialize search strategy with initial state.
     *
     * @param gameboard Initial state/gameboard
     */
    virtual void initialize(const GameboardModel &gameboard) = 0;
    /**
     * @brief Get next move.
     *
     * @return  Next move
     */
    virtual GameboardModel::Move next() = 0;

    /**
     * @brief Destructor.
     */
    virtual ~SearchStrategy();
};
