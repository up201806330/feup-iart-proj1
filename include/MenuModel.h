// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <vector>
#include <string>

class MenuModel {
private:
    std::vector< std::pair<std::string, void (*)()> > buttons;
public:
    void addButton(const std::string &label, void (*func)());

    const std::vector<std::pair < std::string, void (*)(void)>>& getButtons() const;
};
