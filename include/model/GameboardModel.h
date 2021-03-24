// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <vector>
#include <deque>

typedef unsigned int color_t;
const color_t INVALID_COLOR = 0;

typedef std::deque<color_t> Tube;

class GameboardModel : public std::vector<Tube> {
private:
    size_t _num_tubes;
    size_t _tube_height;
public:
    /**
     * @brief Default constructor
     * 
     */
    GameboardModel();

    /**
     * @brief Copy constructor
     * 
     */
    GameboardModel(const GameboardModel& original);

    /**
     * @brief Construct a new GameboardModel.
     * 
     * @param num_tubes     Number of tubes
     * @param tube_height   Tube height
     */
    GameboardModel(size_t num_tubes, size_t tube_height);

    /**
     * @brief Get tubes' height.
     * 
     * @return size_t Tube height
     */
    size_t tubeHeight() const;

    /**
     * @brief Clear GameboardModel.
     */
    void clear();

    /**
     * @brief Fill a GameboardModel with random pieces.
     * 
     * @param num_colors    Number of colors of pieces to place
     */
    void fillRandom(size_t num_colors);

    /**
     * @brief Check if the top piece of a tube can be moved to the top of
     * another tube.
     * 
     * @param tube_orig     Origin tube index
     * @param tube_dest     Destination tube index
     * @return true         If movement is valid
     * @return false        otherwise
     */
    bool canMove(size_t tube_orig, size_t tube_dest) const;

    /**
     * @brief Check if the top piece of a tube can be moved to the top of
     * another tube.
     * 
     * @param tube_origin     Origin tube
     * @param tube_destin     Destination tube
     * @return true         If movement is valid
     * @return false        otherwise
     */
    static bool canMove(Tube tube_origin, Tube tube_destin);

    /**
     * @brief Move piece from one tube to another.
     * 
     * @param tube_orig     Origin tube
     * @param tube_dest     Destination tube
     */
    void move(size_t tube_orig, size_t tube_dest);

    /**
     * @brief Get all possible legal moves from current state
     * 
     * @return std::vector<std::pair<size_t, size_t>> 
     */
    std::vector<std::pair<size_t, size_t>> getAllMoves();

    /**
     * @brief Get all boards reacheable by one move from the current one
     * 
     * @return std::vector<GameboardModel> 
     */
    std::vector<GameboardModel> getAdjacentStates();
};
