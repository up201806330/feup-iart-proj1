// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/TerminalGUI.h"

/**
 * @brief Terminal GUI as a file pointer.
 */
class TerminalGUIFile: public TerminalGUI {
private:
    FILE *of;
public:
    /**
     * @brief Construct terminal GUI from file pointer.
     *
     * @param file  File pointer; defaults to stdout
     */
    explicit TerminalGUIFile(FILE *file = stdout);
protected:
    /**
     * @brief Get pointer to file.
     *
     * @return  Pointer to file
     */
    FILE* getFile() const;
public:
    /**
     * @brief Get size of the terminal that the file pointer refers to.
     *
     * @return  Terminal size, in characters
     */
    pos_t getSize() const override;
};
