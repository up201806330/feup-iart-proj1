#include <iostream>

#include "TerminalGUIColor.h"
#include "GameboardModel.h"
#include "GameboardView.h"

using namespace std;

int main(){
    TerminalGUI *gui = new TerminalGUIColor();

    /*
    gui->clear();
    gui->drawCharacter({13, 5}, 'H');
    gui->drawCharacter({14, 5}, 'E', TerminalGUI::Color::RED, TerminalGUI::Color::DEFAULT, TerminalGUI::Effects::BOLD);
    gui->drawCharacter({15, 5}, 'L', TerminalGUI::Color::RED, TerminalGUI::Color::BLUE   , TerminalGUI::Effects::UNDERLINED);
    gui->drawCharacter({16, 5}, 'L', TerminalGUI::Color::RED, TerminalGUI::Color::BLUE   , TerminalGUI::Effects::BOLD | TerminalGUI::Effects::UNDERLINED);
    gui->drawCharacter({17, 5}, 'O');
    gui->display();
     */

    GameboardModel model(5, 4);
    model.fillRandom(3);
    GameboardView view(model);
    view.display(*gui);

    getchar();

    return 0;
}
