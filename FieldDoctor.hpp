#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

#include <iostream>

namespace pandemic{

    class FieldDoctor: public Player {

        public:
        FieldDoctor(Board& board, City city): Player(board, city){}  
        Player& treat(City city) override;
        std::string role() override{
            std::string city = ToString(Player::currennt_city);
            return "FieldDoctor. and locate at: "+city;
        }
    };

}