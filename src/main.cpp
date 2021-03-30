// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3


#include "CommandLineInterface.h"
#include "view/gui/TerminalGUIColor.h"
#include "controller/state/State.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc >= 2 && string(argv[1]) == "cli"){
        vector<string> args(argv+2, argv+argc);
        CommandLineInterface interface(args);
        interface.run();
        return 0;
    }

    TerminalGUI *terminal = new TerminalGUIColor();
    State::initializeStates(terminal);

    State *currentState = State::mainMenuState;
    while(currentState != nullptr){
        currentState = currentState->run();
    }

    State::deleteStates();
    return 0;
}
