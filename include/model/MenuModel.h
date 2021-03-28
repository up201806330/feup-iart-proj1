// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <vector>
#include <string>

class MenuModel {
public:
    struct Button {
        int id;
        std::string label;
        Button(int id, std::string label);
    };
private:
    std::vector<Button> buttons;
public:
    void addButton(int id, const std::string &label);

    const std::vector<Button>& getButtons() const;

    bool hasButtonWithId(int id) const;
};
