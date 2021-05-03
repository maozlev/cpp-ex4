#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

#include <iostream>

namespace pandemic{

    class Researcher: public Player {

        public:
        Researcher(Board& board, City city): Player(board, city){}
        Player& discover_cure(Color color) override;
        std::string role() override{
            return "Researcher";
        }
        
    };
}