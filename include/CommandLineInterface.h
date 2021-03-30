// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include "model/GameboardModel.h"
#include "algorithm/SearchStrategy.h"
#include "algorithm/heuristics/Heuristic.h"

class CommandLineInterface {
private:
    std::deque<std::string> args;
public:
    explicit CommandLineInterface(const std::vector<std::string> &arguments);
    void run();
private:
    void printHelp() const;
    void run_inside();
    GameboardModel board();
    SearchStrategy *strategy();
    SearchStrategy *informed();
    Heuristic *heuristic();
    Heuristic *finiteHorizonHeuristic();
};
