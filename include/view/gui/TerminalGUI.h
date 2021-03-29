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
        RED     = 0,
        GREEN   = 1,
        BLUE    = 2,
        MAGENTA = 3,
        YELLOW  = 4,
        CYAN    = 5,
        WHITE   = 6,
        BLACK   = 7,
        GRAY    = 8,
        DEFAULT = 255,
    };

    /**
     * @brief Type used to store effects flags as a bitset.
     */
    typedef uint32_t effects_t;
    /**
     * @brief Effects (e.g., bold, underlined).
     */
    enum Effects : effects_t {
        BOLD = 1,
        UNDERLINED = 2
    };

    /**
     * @brief Type of coordinate primitives.
     */
    typedef int32_t coord_t;

    /**
     * @brief Bi-dimensional coordinate object. Can be a position or a size.
     */
    struct pos_t {
        coord_t x; ///< @brief X-coordinate.
        coord_t y; ///< @brief Y-coordinate.

        /**
         * @brief Construct a pos_t object (a position or a size).
         * 
         * @param x X-coordinate
         * @param y Y-coordinate
         */
        explicit pos_t(coord_t x = 0, coord_t y = 0);
        
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
    pos_t corner = pos_t(0,0); ///< @brief Coordinates of leftmost, upmost character.
protected:
    /**
     * @brief Tuple of information required to draw a character.
     */
    typedef std::tuple<pos_t, std::string, Color, Color, effects_t> ToDrawTypedef;
private:
    std::list<ToDrawTypedef> to_draw;
protected:
    /**
     * @brief Get list of all tuples of chars to be drawn.
     * 
     * @return const std::list<ToDrawTypedef>& List of tuples to be drawn
     */
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
     * @brief Clear drawing buffer.
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
     * @param effects       Effects
     */
    void drawCharacter(pos_t pos, const std::string &c, Color foreground = DEFAULT, Color background = DEFAULT, effects_t effects = 0);

    /**
     * @brief Draw character in absolute terminal position.
     * 
     * @param pos           Absolute position
     * @param c             Character
     * @param foreground    Foreground color
     * @param background    Background color
     * @param effects       Effects
     */
    void drawCharacterAbsolute(pos_t pos, const std::string &c, Color foreground = DEFAULT, Color background = DEFAULT, effects_t effects = 0);

    /**
     * @brief Draw string in position, accounting for coordinate of the
     * upper-left corner.
     * 
     * @param pos           Position
     * @param c             String
     * @param foreground    Foreground color
     * @param background    Background color
     * @param effects       Effects
     */
    void drawString(pos_t pos, const std::string &c, Color foreground = DEFAULT, Color background = DEFAULT, effects_t effects = 0);

    /**
     * @brief Draw string in absolute terminal position.
     * 
     * @param pos           Absolute position
     * @param c             String
     * @param foreground    Foreground color
     * @param background    Background color
     * @param effects       Effects
     */
    void drawStringAbsolute(pos_t pos, const std::string &c, Color foreground = DEFAULT, Color background = DEFAULT, effects_t effects = 0);

    /**
     * @brief Draw drawable in this terminal.
     *
     * @param drawable Drawable to draw.
     */
    void draw(TerminalGUIDrawable &drawable);

    /**
     * @brief Display buffer contents.
     */
    virtual void display() = 0;
};

namespace std {
    /**
     * @brief Hash a position.
     *
     * Uses a decent hash function.
     */
    template <> struct hash<TerminalGUI::pos_t>{
        std::size_t operator()(const TerminalGUI::pos_t& p) const;
    };
}
