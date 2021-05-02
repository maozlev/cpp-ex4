#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"

#include <map>
#include <vector>
#include <iostream>

namespace pandemic{

    class Player{

        public:

        std::string roles;
        std::vector <City> cards_of_player;
        City currennt_city;
        Board current_board;

        Player(Board board, City city, std::string roles);

        Player& drive(City city);
        virtual Player& fly_direct(City city);
        Player& fly_charter(City city);
        Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);

        Player& take_card(City city);
        void role();

        int get_num_of_color(Color color);

            
        
        

        

            



    };

};