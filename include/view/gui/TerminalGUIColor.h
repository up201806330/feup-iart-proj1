// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "TerminalGUIFile.h"

class TerminalGUIColor: public TerminalGUIFile {
public:
    explicit TerminalGUIColor(FILE *file = stdout);
    void display() override;
};
