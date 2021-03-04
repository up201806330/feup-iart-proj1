#include "Gameboard.h"

#include <stdexcept>

using namespace std;

Gameboard::Gameboard(size_t num_tubes, size_t tube_height):
    std::vector<Tube>(num_tubes),
    _num_tubes(num_tubes),
    _tube_height(tube_height)
{

}

void Gameboard::clear(){
    for(size_t i = 0; i < _num_tubes; ++i){
        (*this)[i] = stack<color_t>();
    }
}

void Gameboard::fillRandom(size_t num_colors, size_t num_pieces){
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
            color = rand()%num_colors;

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
                tube = rand()%num_tubes;
            } while((*this)[tube].size() >= _tube_height);
            // i is the index, i+1 is the color ID.
            (*this)[tube].push(i+1);
        }
    }
}

void Gameboard::canMove(size_t tube_orig, size_t tube_dest) const {
    return (
        // Origin is not empty
        !(*this)[tube_orig].empty() &&
        // Destination is not full
        (*this)[tube_dest].size() < _tube_height &&
        (
            // Destination is empty; or
            (*this)[tube_dest].empty() ||
            // Destination top is same color as origin top
            (*this)[tube_orig].top() == (*this)[tube_dest].top()
        )
    );
}
