#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

#include <iostream>

namespace pandemic{

    class Scientist: public Player {
        int n;

        public:
        Scientist(Board& board, City city, int num): Player(board, city), n(num){}
        Player& discover_cure(Color color) override;
        std::string role() override{
            std::string city = ToString(Player::currennt_city);
            return "Scientist";
        }
        
    };

}