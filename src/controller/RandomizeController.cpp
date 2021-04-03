// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <iostream>
#include <sstream>
#include <vector>
#include "controller/RandomizeController.h"

using namespace std;

RandomizeController::RandomizeController(){}

void RandomizeController::run() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> selectedOption;
    if(ss.fail()) selectedOption = -1;
}

vector<int> RandomizeController::getValues() const {
    return selectedOption;
}
