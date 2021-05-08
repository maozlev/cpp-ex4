#include "FieldDoctor.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& FieldDoctor::treat(City city){
        City this_city = this->currennt_city;
        string st = ToString(city);
        string st1 = ToString(this_city);
        if(city!=this_city){
            if(!this->current_board.is_neighbors(this_city, city)){
                throw invalid_argument{st+" and "+st1+" are no connected"};
            }
        }
        if(current_board[city] == 0){
            throw invalid_argument{st+" already clear"};
        }

        Color color = current_board.colors[city];
        if(current_board.cure[color]){
            current_board[city] = 0;
               return *this;
        }
        current_board[city] --;
        return *this;
    }
        
        
};


