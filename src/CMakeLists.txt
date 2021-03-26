# Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
# Distributed under the terms of the GNU General Public License, version 3

cmake_minimum_required(VERSION 3.10)

project(iart-proj1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/..)

include_directories(../include)

add_executable(main
    main.cpp
    model/GameboardModel.cpp
    model/MainMenuModel.cpp
    model/MenuModel.cpp
    model/ScoreboardModel.cpp
    view/gui/TerminalGUI.cpp
    view/gui/TerminalGUIColor.cpp
    view/gui/TerminalGUIFile.cpp
    view/gui/TerminalGUISprite.cpp
    view/GameboardView.cpp
    view/MainMenuView.cpp
    view/MenuView.cpp
    view/Rectangle.cpp
    view/ScoreboardView.cpp
    controller/state/State.cpp
    controller/state/MainMenuState.cpp
    controller/state/PlayHumanState.cpp
    controller/MenuController.cpp
    algorithm/BFS.cpp
    algorithm/Dfs.cpp
)

set(CPP_COMPILER_WARNINGS -Wall -Wunused-result -pedantic-errors -Wextra -Wcast-align -Wcast-qual -Wchar-subscripts
                          -Wcomment -Wconversion -Wdisabled-optimization -Wfloat-equal  -Wformat  -Wformat=2
                          -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimport -Winit-self -Winvalid-pch
                          -Wmissing-braces -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs
                          -Wmissing-noreturn -Wpacked -Wparentheses  -Wpointer-arith -Wredundant-decls -Wreturn-type
                          -Wsequence-point  -Wshadow -Wsign-compare  -Wstack-protector -Wstrict-aliasing -Wstrict-aliasing=2
                          -Wswitch  -Wswitch-default -Wswitch-enum -Wtrigraphs  -Wuninitialized -Wunknown-pragmas 
                          -Wunreachable-code -Wunused -Wunused-function  -Wunused-label  -Wunused-parameter
                          -Wunused-value  -Wunused-variable  -Wvariadic-macros -Wvolatile-register-var  -Wwrite-strings)

set(CPP_COMPILER_OPTIMIZE -ffast-math -O3)

target_compile_options(main PRIVATE -g ${CPP_COMPILER_WARNINGS} ${CPP_COMPILER_OPTIMIZE})
