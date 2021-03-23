// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "view/gui/GUI.h"

#include <cstdint>
#include <cwchar>
#include <list>
#include <tuple>

#include "TerminalGUIDrawable.h"

/**
 * @brief Terminal GUI.
 */
class TerminalGUI: public GUI {
public:
    /**
     * @brief Colors allowed for terminals.
     */
    enum Color {
        DEFAULT = 0,
        RED     = 1,
        GREEN   = 2,
        BLUE    = 3,
        MAGENTA = 5,
        YELLOW  = 6,
        CYAN    = 4,
        WHITE   = 7,
        BLACK   = 8,
        GRAY    = 9
    };

    typedef uint32_t effects_t;
    enum Effects : effects_t {
        BOLD = 1,
        UNDERLINED = 2
    };

    /**
     * @brief Type of coordinate primitives.
     */
    typedef int32_t coord_t;

    /**
     * @brief Bidimensional coordinate object. Can be a position or a size.
     */
    struct pos_t {
        coord_t x, y;
        pos_t(coord_t x = 0, coord_t y = 0);
        pos_t operator+(const pos_t &p) const;
        pos_t operator-(const pos_t &p) const;
        pos_t operator/(coord_t c) const;
        pos_t operator-() const;

        bool operator==(const pos_t &p) const;
        bool operator< (const pos_t &p) const;
        bool operator> (const pos_t &p) const;
        bool operator<=(const pos_t &p) const;
        bool operator>=(const pos_t &p) const;
    };
private:
    pos_t corner = {0,0}; ///< @brief Coordinates of leftmost, upmost character.
protected:
    typedef std::tuple<pos_t, std::string, Color, Color, effects_t> ToDrawTypedef;
private:
    std::list<ToDrawTypedef> to_draw;
protected:
    const std::list<ToDrawTypedef>& getToDraw() const;
public:

    /**
     * @brief Get terminal size.
     * 
     * @return pos_t Terminal size
     */
    virtual pos_t getSize() const = 0;

    /**
     * @brief Set position of upper-left corner of terminal.
     * 
     * @param corner Coordinates of the upper-left corner of the terminal
     */
    void setCorner(pos_t corner);

    /**
     * @brief Crear drawing buffer.
     */
    void clear();

    /**
     * @brief Draw character in position, accounting for coordinate of the
     * upper-left corner.
     * 
     * @param pos           Position
     * @param c             Character
     * @param foreground    Foreground color
     * @param background    Background color
     */
    void drawCharacter(pos_t pos, std::string c, Color foreground = DEFAULT, Color background = DEFAULT, effects_t effects = 0);

    /**
     * @brief Draw character in absolute terminal position.
     * 
     * @param pos           Absolute position
     * @param c             Character
     * @param foreground    Foreground color
     * @param background    Background color
     */
    void drawCharacterAbsolute(pos_t pos, std::string c, Color foreground = DEFAULT, Color background = DEFAULT, effects_t effects = 0);

    /**
     * @brief Draw string in position, accounting for coordinate of the
     * upper-left corner.
     * 
     * @param pos           Position
     * @param s             String
     * @param foreground    Foreground color
     * @param background    Background color
     */
    void drawString(pos_t pos, std::string c, Color foreground = DEFAULT, Color background = DEFAULT, effects_t effects = 0);

    /**
     * @brief Draw string in absolute terminal position.
     * 
     * @param pos           Absolute position
     * @param s             String
     * @param foreground    Foreground color
     * @param background    Background color
     */
    void drawStringAbsolute(pos_t pos, std::string c, Color foreground = DEFAULT, Color background = DEFAULT, effects_t effects = 0);

    void draw(TerminalGUIDrawable &drawable);

    /**
     * @brief Display buffer contents.
     */
    virtual void display() = 0;
};
