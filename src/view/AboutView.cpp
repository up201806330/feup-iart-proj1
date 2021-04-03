// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "view/AboutView.h"

using namespace std;
typedef TerminalGUI::coord_t coord_t;
typedef TerminalGUI::pos_t pos_t;

AboutView::AboutView(){}

void AboutView::draw(TerminalGUI &terminal){
     terminal.drawStringAbsolute(pos_t(1,0),"Human Interface: Using the graphical interface, users can:");
     terminal.drawStringAbsolute(pos_t(3,1), "1. Play a puzzle or");
     terminal.drawStringAbsolute(pos_t(3,2), "2. Run the Autonomous player.");
     terminal.drawStringAbsolute(pos_t(1,4),"In the former, move balls from one tube to another using the notation");
     terminal.drawStringAbsolute(pos_t(0, 5), "'fromTubeIndex toTubeIndex', where these indexes range from [0, nTubes].");
     terminal.drawStringAbsolute(pos_t(1, 7), "In the latter, navigate the menus to select an algorithm and wait until a solution is");
     terminal.drawStringAbsolute(pos_t(0, 8), "found for a new random puzzle. After that, press Enter to navigate the found solution.");
     terminal.drawStringAbsolute(pos_t(1,10),"Command Line Interface: Useful for testing and data analysis");
     terminal.drawStringAbsolute(pos_t(1,12), "Usage:");
     terminal.drawStringAbsolute(pos_t(4,13), "main cli <nRuns> <BOARD> <STRATEGY>:");
     terminal.drawStringAbsolute(pos_t(4,14),"<BOARD>    : <nTubes> <tubeH> <nColors> <seed>");
     terminal.drawStringAbsolute(pos_t(4,15), "<STRATEGY> : [dfs|bfs|iterative-deepening]");
     terminal.drawStringAbsolute(pos_t(4,16), "<STRATEGY> : informed <INFORMED>");
     terminal.drawStringAbsolute(pos_t(4,17), "<INFORMED> : <HEURISTIC> [dfs-greedy|greedy|astar]");
     terminal.drawStringAbsolute(pos_t(4,18), "<HEURISTIC>: admissible");
     terminal.drawStringAbsolute(pos_t(4,19), "<HEURISTIC>: nonadmissible <factor>");
     terminal.drawStringAbsolute(pos_t(4,20), "<HEURISTIC>: finite-horizon-heuristics <FH>");
     terminal.drawStringAbsolute(pos_t(4,21), "<FH>       : <horizon> [admissible] [finite-horizon]");
}
