#include "FieldDoctor.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& FieldDoctor::treat(City city){
        string st = ToString(city);
        City this_city = this->currennt_city;
        string st1 = ToString(this_city);
        Color color = current_board.colors[city];
        if(!this->current_board.is_neighbors(this_city, city)){
            if(this_city != city){
                throw invalid_argument{st+" and "+st1+" are no connected"};
            }
        }
        if((this->current_board.is_neighbors(this_city, city)
           &&this->current_board.cure[color]) || 
           ((this_city == city) &&this->current_board.cure[color]) ){
            current_board[city] = 0;
                cout<<"update infection level: "<<
                current_board[city]<<
                " at: "<<st<<endl;
            return *this;
        }
        if(this->current_board.is_neighbors(this_city, city) || this_city == city){
            current_board[city] --;
                cout<<"update infection level: "<<
                current_board[city]<<
                " at: "<<st<<endl;
            return *this;
        }
        return *this;
    }
        
        
};


