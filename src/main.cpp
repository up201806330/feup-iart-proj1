#include <iostream>

#include "TerminalGUIColor.h"
#include "GameboardModel.h"
#include "GameboardView.h"
#include "ScoreboardModel.h"
#include "ScoreboardView.h"

#include <unistd.h>

using namespace std;

int main(){
    TerminalGUI *gui = new TerminalGUIColor();

    GameboardModel gameboard(5, 4);
    gameboard.fillRandom(3);
    ScoreboardModel scoreboard;

    GameboardView gameboardView(gameboard);
    ScoreboardView scoreboardView(scoreboard);

    gameboardView.draw(*gui);
    scoreboardView.draw(*gui);

    gui->display();
    
    return 0;
}
