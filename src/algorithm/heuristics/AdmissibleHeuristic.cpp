// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <numeric>
#include <algorithm>
#include "algorithm/heuristics/AdmissibleHeuristic.h"

using namespace std;

Heuristic::heuristic_t AdmissibleHeuristic::operator()(const GameboardModel &gameboard) const {
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
    // Second part
    size_t nColors = gameboard.getNumberOfColors();
    vector< vector<size_t> > colors(nColors);
    for(const Tube &tube: gameboard){
        if(tube.empty()) continue;
        color_t c = tube[0];
        size_t s;
        for(s = 1; s < tube.size(); ++s)
            if(tube[s] != c) break;
        colors[c].push_back(s);
    }
    for(color_t c = 0; c < nColors; ++c) {
        const vector<size_t> c_count = colors.at(c);
        if(c_count.empty()) continue;
        ret += accumulate(c_count.begin(), c_count.end(), 0.0) - (double) *max_element(c_count.begin(), c_count.end());
    }

    return ret;
}
