#include "Color.hpp"
#include "City.hpp"

#include <map>
#include <vector>

namespace pandemic{

    class Board{

        static std::map <City , vector<City>> connections;
        static std::map <City , Color> colors;
        static std::map <City , int> infection_level;
        
        public:

            Board(){}
            ~Board(){}



    };

};