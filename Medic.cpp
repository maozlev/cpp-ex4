#include "Medic.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& Medic::fly_direct(City city){   
        Color c = current_board.colors.at(city);
        if(current_board.cure.at(c)){
            current_board[city] = 0;
        }
        return Player::fly_direct(city);    
    }
    
    
    Player& Medic::fly_charter(City city){
        Color c = current_board.colors.at(city);
        if(current_board.cure.at(c)){
            current_board[city] = 0;
        }
        return Player::fly_charter(city);    
    }
    
    
    Player& Medic::fly_shuttle(City city){
         Color c = current_board.colors.at(city);
        if(current_board.cure.at(c)){
            current_board[city] = 0;
        }
        return Player::fly_shuttle(city);    
    }
    
    Player& Medic::drive(City city){
        Color c = this->current_board.colors.at(city);
        if(this->current_board.cure.at(c)){
            this->current_board[city] = 0;
        }
        return Player::drive(city);
    }

    
    
    Player& Medic::treat(City city){
        string st = ToString(city);
        unsigned int t = 0;
        Color c = current_board.colors[city]; 
        if(currennt_city == city){
            if(current_board.infection_level.at(city) <= 0){
                throw logic_error{st+" is already clear"};
            }
            current_board[city] = 0;
            // cout<<"update infection level: "<<
            // current_board[city]<<
            // " at: "<<st<<endl;
            // cout<<st<<" is clear"<<endl;
            return *this;
        }
        throw std::invalid_argument{"go to the city: "+st};
    }
        
}      




