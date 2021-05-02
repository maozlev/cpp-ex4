#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Scientist: public Player {
        int n;

        public:
        Scientist(Board& board, City city, int num): Player(board, city, "Scientist"), n(num){}
        Player& discover_cure(Color color) override;
    };

}