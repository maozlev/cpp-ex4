#include "Medic.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& Medic::fly_direct(City city){   
        Color c = this->current_board.colors.at(city);
        if(this->current_board.cure.at(c)){
            this->current_board[city] = 0;
        }
        Player::fly_direct(city);    
        return *this;
    }
    
    
    Player& Medic::fly_charter(City city){
        Color c = this->current_board.colors.at(city);
        if(this->current_board.cure.at(c)){
            this->current_board[city] = 0;
        }
        Player::fly_charter(city);    
        return *this;
    }
    
    
    Player& Medic::fly_shuttle(City city){
         Color c = this->current_board.colors.at(city);
        if(this->current_board.cure.at(c)){
            this->current_board[city] = 0;
        }
        Player::fly_shuttle(city);    
        return *this;
    }
    
    Player& Medic::drive(City city){
        Color c = this->current_board.colors.at(city);
        if(this->current_board.cure.at(c)){
            this->current_board[city] = 0;
        }
        Player::drive(city);
        return *this;
    }

    
    
    Player& Medic::treat(City city){
        string st = ToString(city);
        unsigned int t = 0;
        if(currennt_city == city){
            if(current_board.infection_level.at(city) <= 0){
                throw logic_error{st+" is already clear"};
            }
            if(this->cards_of_player.empty()){
                throw std::invalid_argument{"you dont have any cards"};
            }
            if(current_board.research_lab.at(city)){
                while(t < this->cards_of_player.size()){
                    if(this->cards_of_player.at(t) == city){
                        this->cards_of_player.erase(this->cards_of_player.begin() + t);
                        this->current_board.cards.at(city) = false;
                        current_board[city] = 0;
                        cout<<"update infection level: "<<
                        current_board[city]<<
                        " at: "<<st<<endl;
                        cout<<st<<" is clear"<<endl;
                        return *this;
                    }
                    t++;
                }
                throw std::invalid_argument{"you dont have card of this city"};
            }
            throw std::invalid_argument{"you dont have research Lab in this city"}; 
        }
        throw std::invalid_argument{"go to the city: "+st};
    }
        
}      




