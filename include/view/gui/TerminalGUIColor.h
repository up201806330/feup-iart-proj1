// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "TerminalGUIFile.h"

/**
 * @brief Terminal GUI with color.
 *
 * Uses ANSI escape codes of colors to color the terminal.
 */
class TerminalGUIColor: public TerminalGUIFile {
public:
    /**
     * @brief Construct terminal GUI from file to print to.
     *
     * @param file  Pointer to file; defaults to stdout
     */
    explicit TerminalGUIColor(FILE *file = stdout);
    /**
     * @brief Draw the content of the buffer to the file.
     */
    void display() override;
};
