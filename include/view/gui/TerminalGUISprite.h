// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <map>
#include <vector>

#include "view/gui/TerminalGUI.h"
#include "view/gui/TerminalGUIDrawable.h"

class TerminalGUISprite : public TerminalGUIDrawable {
private:
    typedef std::tuple<std::string, TerminalGUI::Color, TerminalGUI::Color, TerminalGUI::effects_t> ToDrawNoPosTypedef;

    std::map<TerminalGUI::pos_t, ToDrawNoPosTypedef> m;
    TerminalGUI::pos_t position;
public:
    explicit TerminalGUISprite(
        const std::vector<std::vector<std::string>> &cs,
        const std::vector<std::vector<TerminalGUI::Color>> &foregrounds = {},
        const std::vector<std::vector<TerminalGUI::Color>> &backgrounds = {},
        const std::vector<std::vector<TerminalGUI::effects_t>> &effects = {}
    );
    void set(
        const std::vector<std::vector<std::string>> &cs,
        const std::vector<std::vector<TerminalGUI::Color>> &foregrounds = {},
        const std::vector<std::vector<TerminalGUI::Color>> &backgrounds = {},
        const std::vector<std::vector<TerminalGUI::effects_t>> &effects = {}
    );
    void setCharacter(const TerminalGUI::pos_t &pos, const std::string &c, const TerminalGUI::Color &foreground, const TerminalGUI::Color &background, const TerminalGUI::effects_t &effects);
    void setPosition(const TerminalGUI::pos_t &pos);
    void draw(TerminalGUI &terminal) override;
};
