// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <stdexcept>
#include "model/GameboardModel.h"

class SearchStrategy {
public:
    class failed_to_find_solution: public std::logic_error {
    public:
        explicit failed_to_find_solution(const std::string &what_arg);
    };
public:
    virtual void initialize(const GameboardModel &gameboard) = 0;
    virtual GameboardModel::Move next() = 0;

    virtual ~SearchStrategy();
};
