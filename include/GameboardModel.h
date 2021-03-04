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
     * @brief Construct a new GameboardModel.
     * 
     * @param num_tubes     Number of tubes
     * @param tube_height   Tube height
     */
    GameboardModel(size_t num_tubes, size_t tube_height);

    /**
     * @brief Clear GameboardModel.
     */
    void clear();

    /**
     * @brief Fill a GameboardModel with random pieces.
     * 
     * @param num_colors    Number of colors of pieces to place
     * @param num_pieces    Total number of pieces
     */
    void fillRandom(size_t num_colors, size_t num_pieces);

    /**
     * @brief Check if the top piece of a tube can be moved to the top of
     * another tube.
     * 
     * @param tube_orig     Origin tube
     * @param tube_dest     Destination tube
     * @return true         If movement is valid
     * @return false        otherwise
     */
    bool canMove(size_t tube_orig, size_t tube_dest) const;

    /**
     * @brief Move piece from one tube to another.
     * 
     * @param tube_orig     Origin tube
     * @param tube_dest     Destination tube
     */
    void move(size_t tube_orig, size_t tube_dest);
};
