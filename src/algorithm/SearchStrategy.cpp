// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/SearchStrategy.h"

SearchStrategy::failed_to_find_solution::failed_to_find_solution(const std::string &s) :
    logic_error(s)
{
}
