// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <numeric>
#include <algorithm>
#include "algorithm/Heuristics.h"

using namespace std;

double Heuristics::h1(const GameboardModel &gameboard) {
    double ret = 0.0;
    // First part
    for(const Tube &t: gameboard){
        if(t.empty()) continue;
        color_t c = t[0];
        size_t i;
        for(i = 0; i < t.size(); ++i){
            if(t[i] != c) break;
        }
        ret += static_cast<double>(t.size() - i);
    }
    return ret;
}
