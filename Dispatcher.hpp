#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

#include <iostream>

namespace pandemic{

    class Dispatcher: public Player {

    public:
        Dispatcher(Board& board, City city): Player(board, city){}
        Player& fly_direct(City city) override;
        std::string role() override{
            std::string city = ToString(Player::currennt_city);
            return "Dispatcher. and locate at: "+city;
        }
    };

}