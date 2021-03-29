// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "view/gui/TerminalGUIFile.h"

#if defined(unix) || defined(__unix__) || defined(__unix)
    #include <sys/ioctl.h>
#elif defined(WIN32)
    #include <windows.h>
#endif

using namespace std;

TerminalGUIFile::TerminalGUIFile(FILE *file): of(file){}

FILE* TerminalGUIFile::getFile() const{ return of; }

TerminalGUIFile::pos_t TerminalGUIFile::getSize() const {
    #if defined(unix) || defined(__unix__) || defined(__unix)
        struct winsize size;
        ioctl(fileno(getFile()), TIOCGWINSZ, &size);
        return pos_t(size.ws_col, size.ws_row);
    #elif defined(WIN32)
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        pos_t size;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        size.x = csbi.srWindow.Right  - csbi.srWindow.Left + 1;
        size.y = csbi.srWindow.Bottom - csbi.srWindow.Top  + 1;

        return size;
    #else
        #error Unknown OS, dont know how to get terminal size
    #endif
}
