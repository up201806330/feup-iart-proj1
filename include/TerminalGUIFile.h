#pragma once

#include "TerminalGUI.h"

class TerminalGUIFile: public TerminalGUI {
private:
    FILE *of;
public:
    TerminalGUIFile(FILE *ofile = stdout);
protected:
    FILE* getFile() const;
public:
    virtual pos_t getSize() const;
};
