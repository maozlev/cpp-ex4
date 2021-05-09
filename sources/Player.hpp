#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"

#include <map>
#include <vector>
#include <iostream>
#include <typeinfo>

namespace pandemic{

    class Player{
        

        public:
        std::vector <City> cards_of_player;
        City currennt_city;
        Board& current_board;

        Player(Board& board, City city);
       

        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);

        Player& take_card(City city);

        int get_num_of_color(Color color);

        virtual std::string role(){
            std::string city = ToString(Player::currennt_city);
            return "Player";
        }
        void remove_cards(){
            cards_of_player.clear();
        }

            
        
        

        

            



    };

};