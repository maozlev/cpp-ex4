#include "Color.hpp"
#include "City.hpp"

#include <map>
#include <vector>

namespace pandemic{

    class Board{
        
        public:

        Board();
        
        std::map <City , std::vector<City>> connections;
        std::map <City , Color> colors;
        std::map <City , int> infection_level;
        std::map <City , bool> cards;

        // ~Board();

        
        

        int& operator[] (const City city);

        

        

            



    };

};