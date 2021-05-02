#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Virologist: public Player {

        public:
        Virologist(Board& board, City city): Player(board, city, "Virologist"){}  
        Player& treat(City city) override;
    };

}