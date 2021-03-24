// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "model/GameboardModel.h"

#include <stdexcept>
#include <algorithm>

using namespace std;

GameboardModel::GameboardModel(size_t num_tubes, size_t tube_height):
    std::vector<Tube>(num_tubes),
    _num_tubes(num_tubes),
    _tube_height(tube_height)
{

}

size_t GameboardModel::tubeHeight() const{ return _tube_height; }

void GameboardModel::clear(){
    for(size_t i = 0; i < _num_tubes; ++i){
        (*this)[i] = deque<color_t>();
    }
}

void GameboardModel::fillRandom(size_t num_colors){
    size_t num_pieces = num_colors*_tube_height;
    // There must be at least as many tubes as there are colors, since each
    // color will be in a separate tube.
    if(num_colors > _num_tubes) throw invalid_argument("more colors than tubes");

    // There must be enough tubes to contain all pieces.
    if(num_pieces > _num_tubes*num_colors) throw invalid_argument("too many pieces");

    // There must be at least one piece of each color, otherwise one of the
    // colors would have 0 pieces, in which case it should be included as a
    // color.
    if(num_pieces < num_colors) throw invalid_argument("num_pieces < num_colors");
    vector<size_t> num_pieces_per_color(num_colors, 1);
    num_pieces -= num_colors;

    // Distribute remaining pieces to the colors.
    for(size_t i = 0; i < num_pieces; ++i){
        color_t color;
        do {
            // Select random color.
            color = color_t(rand()%num_colors);

            // Keep trying until a color is found that has not yet been
            // allocated the maximum number of pieces per color.
        } while(num_pieces_per_color[color] >= _tube_height);

        ++num_pieces_per_color[color];
    }

    clear();
    // Distribute colored pieces through the tubes.
    for(size_t i = 0; i < num_colors; ++i){
        while(num_pieces_per_color[i] > 0){
            // Search for tube that is not yet on maximum capacity.
            size_t tube;
            do {
                tube = rand()%_num_tubes;
            } while((*this)[tube].size() >= _tube_height);
            // i is the index, i+1 is the color ID.
            (*this)[tube].push_back(color_t(i+1));
            --num_pieces_per_color[i];
        }
    }
}

bool GameboardModel::canMove(size_t tube_orig, size_t tube_dest) const {
    const Tube &tube_origin = this->at(tube_orig);
    const Tube &tube_destin = this->at(tube_dest);

    return (
        // Origin is not empty
        !tube_origin.empty() &&
        // Destination is not full
        tube_destin.size() < _tube_height &&
        (
            // Destination is empty; or
            tube_destin.empty() ||
            // Destination top is same color as origin top
            tube_origin.back() == tube_destin.back()
        )
    );
}

void GameboardModel::move(size_t tube_orig, size_t tube_dest) {
    if(!canMove(tube_orig, tube_dest)) throw invalid_argument("");

    Tube &tube_origin = this->at(tube_orig);
    Tube &tube_destin = this->at(tube_dest);

    color_t c = tube_origin.back();
    tube_origin.pop_back();
    tube_destin.push_back(c);
}

/**
 * Checks if all elements of a vector are equal to each other.
 *
 * Returns true if all adjacent elements are equal to each other, or if the vector has less than 2 elements.
 *
 * Returns false if there is at least one adjacent pair of different elements.
 *
 * @tparam T
 * @param v Vector
 * @return  False if at least one pair of adjacent elements are different, true otherwise
 */
template<class T>
bool checkAllEqual(const deque<T> &v){
    return adjacent_find(v.begin(), v.end(), not_equal_to<>()) == v.end();
}

bool GameboardModel::isGameOver() const {
    for(size_t i = 0; i < size(); ++i){
        size_t s = this->at(i).size();
        if(!(s == 0 || s == tubeHeight())) return false;
        if(!checkAllEqual(this->at(i))) return false;
    }
    return true;
}
