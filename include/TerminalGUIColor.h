#pragma once

#include "TerminalGUIFile.h"

class TerminalGUIColor: public TerminalGUIFile {
public:
    TerminalGUIColor(FILE *ofile = stdout);
    virtual void display();
};
