// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <map>
#include <vector>

#include "view/gui/TerminalGUI.h"
#include "view/gui/TerminalGUIDrawable.h"

/**
 * @brief Terminal sprite.
 */
class TerminalGUISprite : public TerminalGUIDrawable {
private:
    typedef std::tuple<std::string, TerminalGUI::Color, TerminalGUI::Color, TerminalGUI::effects_t> ToDrawNoPosTypedef;

    std::map<TerminalGUI::pos_t, ToDrawNoPosTypedef> m;
    TerminalGUI::pos_t position;
public:
    /**
     * @brief Construct sprite from matrix description of characters, foreground and background colors.
     *
     * The sprite will be as large as the characters matrix; the other matrices must only guarantee they are not larger
     * in height, and for each row that they are not larger in width, than the characters matrix; the missing elements
     * from the foreground/background colors and effects assume default values.
     *
     * @param cs            Characters matrix
     * @param foregrounds   Foreground colors matrix
     * @param backgrounds   Background colors matrix
     * @param effects       Effects matrix
     */
    explicit TerminalGUISprite(
        const std::vector<std::vector<std::string>> &cs,
        const std::vector<std::vector<TerminalGUI::Color>> &foregrounds = {},
        const std::vector<std::vector<TerminalGUI::Color>> &backgrounds = {},
        const std::vector<std::vector<TerminalGUI::effects_t>> &effects = {}
    );
    /**
     * @brief Set sprite description.
     *
     * @see TerminalGUISprite::TerminalGUISprite(
     *  const std::vector<std::vector<std::string>> &,
     *  const std::vector<std::vector<TerminalGUI::Color>> &,
     *  const std::vector<std::vector<TerminalGUI::Color>> &,
     *  const std::vector<std::vector<TerminalGUI::effects_t>> &
     * )
     *
     * @param cs            Characters matrix
     * @param foregrounds   Foreground colors matrix
     * @param backgrounds   Background colors matrix
     * @param effects       Effects matrix
     */
    void set(
        const std::vector<std::vector<std::string>> &cs,
        const std::vector<std::vector<TerminalGUI::Color>> &foregrounds = {},
        const std::vector<std::vector<TerminalGUI::Color>> &backgrounds = {},
        const std::vector<std::vector<TerminalGUI::effects_t>> &effects = {}
    );
    /**
     * @brief Set character at certain position.
     *
     * @param pos           Position of character
     * @param c             Character
     * @param foreground    Foreground color of character
     * @param background    Background color of character
     * @param effects       Effects on the character
     */
    void setCharacter(const TerminalGUI::pos_t &pos, const std::string &c, const TerminalGUI::Color &foreground, const TerminalGUI::Color &background, const TerminalGUI::effects_t &effects);
    /**
     * @brief Set sprite position, which corresponds to the position of the upper-left corner of the sprite.
     *
     * @param pos   Sprite position.
     */
    void setPosition(const TerminalGUI::pos_t &pos);
    void draw(TerminalGUI &terminal) override;
};
