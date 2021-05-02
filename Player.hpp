#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"

#include <map>
#include <vector>

namespace pandemic{

    class Player{

        public:

        std::vector <City> cards_of_player;
        City currennt_city;
        Board current_board;

        Player(Board board, City city);

        Player& drive(City city);
        Player& fly_direct(City city);
        Player& fly_charter(City city);
        Player& fly_shuttle(City city);
        Player& build(City city);
        Player& discover_cure(City city);
        Player& treat(City city);

        Player& take_card(City city);
        void role();

        int get_num_of_color(Color color);

            
        
        

        

            



    };

};