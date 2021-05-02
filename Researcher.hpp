#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Researcher: public Player {

        public:
        Researcher(Board& board, City city): Player(board, city, "Researcher"){}
        Player& discover_cure(Color color) override;
    };

}