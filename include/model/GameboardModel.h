// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include <vector>
#include <deque>

typedef unsigned int color_t;

typedef std::deque<color_t> Tube;

class GameboardModel {
public:
    struct Move {
        size_t from, to;
        Move(size_t fr, size_t to);

        bool operator==(const Move &m) const;
        bool operator< (const Move &m) const;
        bool operator> (const Move &m) const;
        bool operator<=(const Move &m) const;
        bool operator>=(const Move &m) const;
    };
private:
    size_t _num_tubes = 0;
    size_t _tube_height = 0;
    std::vector<Tube> tubes;
    size_t _num_colors = 0;
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

    GameboardModel& operator=(const GameboardModel &gameboard);

    /**
     * @brief Construct a new GameboardModel.
     * 
     * @param num_tubes     Number of tubes
     * @param tube_height   Tube height
     */
    GameboardModel(size_t num_tubes, size_t tube_height);

    const Tube& operator[](size_t i) const;
    Tube& operator[](size_t i);

    const Tube& at(size_t i) const;
    Tube& at(size_t i);

    size_t size() const;

    std::vector<Tube>::iterator begin() noexcept;
    std::vector<Tube>::const_iterator begin() const noexcept;
    std::vector<Tube>::iterator end() noexcept;
    std::vector<Tube>::const_iterator end() const noexcept;

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

    size_t getNumberOfColors() const;

    /**
     * @brief Check if the top piece of a tube can be moved to the top of
     * another tube.
     * 
     * @param tube_orig     Origin tube index
     * @param tube_dest     Destination tube index
     * @return true         If movement is valid
     * @return false        otherwise
     */
    bool canMove(const Move &move) const;

    /**
     * @brief Move piece from one tube to another.
     * 
     * @param tube_orig     Origin tube
     * @param tube_dest     Destination tube
     */
    void move(const Move &move);

    /**
     * @brief Get all possible legal moves from current state
     * 
     * @return std::vector<Move> 
     */
    std::vector<Move> getAllMoves() const;

    /**
     * @brief Get all boards reachable by one move from the current one
     * 
     * @return std::vector<GameboardModel> 
     */
    std::vector<GameboardModel> getAdjacentStates();
    bool isGameOver() const;

    bool operator==(const GameboardModel &model) const;
    bool operator< (const GameboardModel &model) const;
    bool operator> (const GameboardModel &model) const;
    bool operator<=(const GameboardModel &model) const;
    bool operator>=(const GameboardModel &model) const;
};

namespace std {
    template <> struct hash<Tube> {
        hash() = default;
        size_t operator()(const Tube &vec) const;
    };

    template <> struct hash<GameboardModel>{
        hash() = default;
        size_t operator()(const GameboardModel& model) const;
    };
}
