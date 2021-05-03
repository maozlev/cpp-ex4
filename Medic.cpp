#include "Medic.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& Medic::fly_direct(City city){
        string st = ToString(city);
        if(this->cards_of_player.empty()){
            throw std::invalid_argument{"you dont have any cards"};
        }
        unsigned int t = 0;
        while(t < this->cards_of_player.size()){
            if(this->cards_of_player.at(t) == city){
                this->currennt_city = city;
                this->cards_of_player.erase(this->cards_of_player.begin() + t);
                this->current_board.cards.at(city) = false;
                cout<<"fly to: "+st<<endl;
                cout<<"drop: "+st<<endl;
                current_board[city] = 0;
                return *this;
            }
            t++;
        } 
        throw std::invalid_argument{"you dont have card of this city: "+st};
    }
    
    
    Player& Medic::fly_charter(City city){

        City need_to_drop = this->currennt_city;
        string st = ToString(city);
        string st1 = ToString(need_to_drop);
        unsigned int t = 0;
        if(this->cards_of_player.empty()){
            throw std::invalid_argument{"you dont have any cards"};
        }
        while(t < this->cards_of_player.size()){
            if(this->cards_of_player.at(t) == need_to_drop){
                this->currennt_city = city;
                this->cards_of_player.erase(this->cards_of_player.begin() + t);
                this->current_board.cards.at(need_to_drop) = false;
                cout<<"fly to: "+st<<endl;
                cout<<"drop: "+st1<<endl;
                current_board[city] = 0;
                return *this;
            }
            t++;
        } 
        throw std::invalid_argument{"you dont have card of this city"};
    }
    
    Player& Medic::fly_shuttle(City city){

        string st = ToString(city);
        string st1 = ToString(this->currennt_city);
        if(this->current_board.research_lab.at(city) &&
           this->current_board.research_lab.at(this->currennt_city)){
               cout<<"fly from: "<<st1<<"to "<<st<<endl;
               this->currennt_city = city;
               current_board[city] = 0;
               return *this;
        }
        if(!(this->current_board.research_lab.at(city))){
            throw std::invalid_argument{st+" dont have research lab"};     
        }
        if(!(this->current_board.research_lab.at(this->currennt_city))){
            throw std::invalid_argument{st1+" dont have research lab"};     
        }
        return *this;
    }
    
    Player& Medic::drive(City city){
        string st = ToString(city);
        if(this->current_board.is_neighbors(this->currennt_city, city)){
            this->currennt_city = city;
            cout<<"moving to: "+st<<endl;
            current_board[city] = 0;
            return *this;
        }
        throw std::logic_error{st+" is not connected"};
    }

    
    
    Player& Medic::treat(City city){
        string st = ToString(city);
        if(currennt_city == city){
            if(current_board.infection_level.at(city) <= 0){
                throw logic_error{st+" is already clear"};
            }
            if(current_board.research_lab.at(city)){
                current_board[city] = 0;
                cout<<"update infection level: "<<
                current_board[city]<<
                " at: "<<st<<endl;
                cout<<st<<" is clear"<<endl;
                return *this;
            }
            if(this->current_board.cure.at(this->current_board.colors.at(city))){
                current_board[city] = 0;
                cout<<"update infection level: "<<
                current_board[city]<<
                " at: "<<st<<endl;
                cout<<st<<" is clear"<<endl;
                return *this;   
            }
            current_board[city]--;
            cout<<"update infection level: "<<
            current_board[city]<<
            " at: "<<st<<endl;
            return *this;
        }
        cout<<"go to the city: "<<st<<endl;
        return *this;
    }
    

}      




