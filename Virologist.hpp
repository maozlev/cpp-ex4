#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Virulogist: public Player {

        public:
        Player& treat(City city) override;
    };

}