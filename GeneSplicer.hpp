#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class GeneSplicer: public Player {

        public:
        GeneSplicer(Board& board, City city): Player(board, city, "Gencer"){}  
        Player& discover_cure(Color color) override;
    };

}