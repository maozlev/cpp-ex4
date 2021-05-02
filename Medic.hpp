#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player {

        public:
        Medic(Board& board, City city): Player(board, city, "Medic"){}
        Player& treat(City city) override;
        Player& drive(City city) override;
        Player& fly_direct(City city) override;
        Player& fly_shuttle(City city) override;
        Player& fly_charter(City city) override;
    };

}