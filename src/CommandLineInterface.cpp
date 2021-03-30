// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include <iostream>
#include <algorithm/DepthFirstSearch.h>
#include <algorithm/IterativeDeepeningSearch.h>
#include <algorithm/DepthFirstGreedySearch.h>
#include <algorithm/GreedySearch.h>
#include <algorithm/AstarSearch.h>
#include <algorithm/heuristics/AdmissibleHeuristic.h>
#include <algorithm/heuristics/FiniteHorizonHeuristic.h>
#include "model/GameboardModel.h"
#include "CommandLineInterface.h"

using namespace std;
using hrc = chrono::high_resolution_clock;

CommandLineInterface::CommandLineInterface(const vector<string> &arguments):
    args(arguments.begin(), arguments.end())
{
}

void CommandLineInterface::run() {
    try {
        run_inside();
    } catch(const exception &e){
        cerr << "Exception: " << e.what() << endl;
        printHelp();
    }
}

void CommandLineInterface::printHelp() const {
    cerr <<
         "Usage:\n"
         "    main cli <nRuns> <BOARD> <STRATEGY>\n"
         "    <BOARD>    : <nTubes> <tubeH> <nColors> <seed>\n"
         "    <STRATEGY> : [dfs|bfs|iterative-deepening]\n"
         "    <STRATEGY> : informed <INFORMED>\n"
         "    <INFORMED> : <HEURISTIC> [dfs-greedy|greedy|astar]\n"
         "    <HEURISTIC>: admissible\n"
         "    <HEURISTIC>: finite-horizon-heuristics <FH>\n"
         "    <FH>       : <horizon> [admissible] [finite-horizon]\n"
         << flush;
}

void CommandLineInterface::run_inside() {
    size_t nRuns = static_cast<size_t>(atol(args.at(0).c_str())); args.pop_front();

    GameboardModel gameboard = board();
    SearchStrategy *search = strategy();

    size_t mem_prev = search->getMemory();
    try {
        search->initialize(gameboard);
    } catch(const exception &e){
        cout << "-1" << endl;
        return;
    }
    size_t mem = search->getMemory() - mem_prev;

    hrc::time_point begin = hrc::now();
    for(size_t i = 0; i < nRuns; ++i) {
        search->initialize(gameboard);
    }
    size_t nMoves = 0;
    while(!gameboard.isGameOver()){
        gameboard.move(search->next());
        ++nMoves;
    }
    hrc::time_point end = hrc::now();
    hrc::duration d = end-begin;
    cout
        << gameboard.size() << "\t"
        << gameboard.tubeHeight() << "\t"
        << gameboard.getNumberOfColors() << "\t"
        << gameboard.getSeed() << "\t"
        << nMoves << "\t"
        << mem << "\t"
        << static_cast<unsigned long>(chrono::duration_cast<chrono::nanoseconds>(d).count()) / nRuns
    << endl;
}

GameboardModel CommandLineInterface::board() {
    size_t nTubes, tubeH, nColors;
    unsigned seed;

    nTubes  = static_cast<size_t  >(atol(args.at(0).c_str())); args.pop_front();
    tubeH   = static_cast<size_t  >(atol(args.at(0).c_str())); args.pop_front();
    nColors = static_cast<size_t  >(atol(args.at(0).c_str())); args.pop_front();
    seed    = static_cast<unsigned>(atol(args.at(0).c_str())); args.pop_front();

    GameboardModel ret(nTubes, tubeH);
    ret.fillRandom(nColors, seed);

    return ret;
}

SearchStrategy *CommandLineInterface::strategy() {
    string method = args.at(0); args.pop_front();
    if     (method == "dfs"                ) return new DepthFirstSearch        ();
    else if(method == "bfs"                ) return new DepthFirstSearch        ();
    else if(method == "iterative-deepening") return new IterativeDeepeningSearch();
    else if(method == "informed"           ) return informed();
    else throw invalid_argument("");
}

SearchStrategy *CommandLineInterface::informed() {
    Heuristic *h = heuristic();
    string method = args.at(0); args.pop_front();
    if     (method == "dfs-greedy") return new DepthFirstGreedySearch(h);
    else if(method == "greedy"    ) return new GreedySearch          (h);
    else if(method == "astar"     ) return new AstarSearch           (h);
    else throw invalid_argument("");
}

Heuristic *CommandLineInterface::heuristic() {
    string s = args.at(0); args.pop_front();
    if     (s == "admissible"               ) return new AdmissibleHeuristic();
    else if(s == "finite-horizon-heuristics") return finiteHorizonHeuristic();
    else throw invalid_argument("");
}

Heuristic *CommandLineInterface::finiteHorizonHeuristic() {
    size_t horizon = static_cast<size_t>(atol(args.at(0).c_str())); args.pop_front();
    string baseHeuristicStr = args.at(0); args.pop_front();
    Heuristic *baseHeuristic = nullptr;
    if     (baseHeuristicStr == "admissible") baseHeuristic = new AdmissibleHeuristic();
    else throw invalid_argument("");
    string fhStrategyStr = args.at(0); args.pop_front();
    Heuristic *fhStrategy;
    if     (fhStrategyStr == "finite-horizon") fhStrategy = new FiniteHorizonHeuristic(baseHeuristic, horizon);
    else throw invalid_argument("");
    return fhStrategy;
}
