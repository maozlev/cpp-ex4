#include "Medic.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>



using namespace std;
namespace pandemic{

    Player& Medic::fly_direct(City city){ 
        Player::fly_direct(city);
        Color c = current_board.colors.at(city);
        if(current_board.cure.at(c)){
        current_board[city] = 0;
        }
        return *this;
    }
    
    
    Player& Medic::fly_charter(City city){
        Player::fly_charter(city); 
        Color c = current_board.colors.at(city);
        if(current_board.cure.at(c)){
            current_board[city] = 0;
        }
        return *this;
    }
    
    
    Player& Medic::fly_shuttle(City city){
        Player::fly_shuttle(city);  
         Color c = current_board.colors.at(city);
        if(current_board.cure.at(c)){
            current_board[city] = 0;
        }
        return  *this; 
    }
    
    Player& Medic::drive(City city){
        Player::drive(city);
        Color c = this->current_board.colors.at(city);
        if(this->current_board.cure.at(c)){
            this->current_board[city] = 0;
        }
        return *this;
    }

    
    
    Player& Medic::treat(City city){
        string st = ToString(city);
        unsigned int t = 0;
        if(currennt_city == city){
            if(current_board.infection_level.at(city) <= 0){
                throw logic_error{st+" is already clear"};
            }
            current_board[city] = 0;
            return *this;
        }
        throw std::invalid_argument{"go to the city: "+st};
    }
        
}      




