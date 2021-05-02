#pragma once
#include "Color.hpp"
#include "City.hpp"

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

namespace pandemic{

    class Board{
        
        public:

        std::map <City , std::vector<City>> connections;
        std::map <City , Color> colors;
        std::map <City , int> infection_level;
        std::map <City , bool> cards;
        std::map <City , bool> research_lab;
        std::map <Color , bool> cure;



        Board();
        
        

        // ~Board();

        int& operator[] (const City city);
        friend std::ostream& operator<< (std::ostream& os, const Board board);
        bool is_clean();
        bool is_neighbors(City a, City b);
        bool card_in_game(City a);
        void remove_cures();


    };

};