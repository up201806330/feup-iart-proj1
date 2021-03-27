# Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
# Distributed under the terms of the GNU General Public License, version 3

cmake_minimum_required(VERSION 3.10)

project(iart-proj1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/.)

include_directories(include)

add_executable(main
    src/main.cpp
    src/model/GameboardModel.cpp
    src/model/MainMenuModel.cpp
    src/model/MenuModel.cpp
    src/model/ScoreboardModel.cpp
    src/view/gui/TerminalGUI.cpp
    src/view/gui/TerminalGUIColor.cpp
    src/view/gui/TerminalGUIFile.cpp
    src/view/gui/TerminalGUISprite.cpp
    src/view/GameboardView.cpp
    src/view/MainMenuView.cpp
    src/view/MenuView.cpp
    src/view/Rectangle.cpp
    src/view/ScoreboardView.cpp
    src/controller/state/State.cpp
    src/controller/state/MainMenuState.cpp
    src/controller/state/PlayHumanState.cpp
    src/controller/state/PlayMachineState.cpp
    src/controller/MenuController.cpp
    src/algorithm/SearchStrategy.cpp
    src/algorithm/Dfs.cpp
    src/algorithm/BestFirstSearch.cpp
    src/algorithm/GreedySearch.cpp
    src/algorithm/Heuristics.cpp
    src/controller/state/ChooseMachineState.cpp
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
