// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/TerminalGUI.h"

class TerminalGUIFile: public TerminalGUI {
private:
    FILE *of;
public:
    explicit TerminalGUIFile(FILE *file = stdout);
protected:
    FILE* getFile() const;
public:
    pos_t getSize() const override;
};
