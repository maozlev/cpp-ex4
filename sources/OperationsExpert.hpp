#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

#include <iostream>

namespace pandemic{

    class OperationsExpert: public Player{

        public:
            OperationsExpert(Board& board, City city): Player(board, city){}
            Player& build() override;
            std::string role() override{
                std::string city = ToString(Player::currennt_city);
                return "OperationsExpert";
            }
        };
}