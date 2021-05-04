#include "Virologist.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& Virologist::treat(City city){
        string st = ToString(city);
        Color c = current_board.colors.at(city);
            if(current_board.infection_level.at(city) <= 0){
                throw logic_error{st+" is already clear"};
            }
            if(current_board.cure.at(c)){
                current_board[city] = 0;
                cout<<"update infection level: "<<
                current_board[city]<<
                " at: "<<st<<endl;
                cout<<st<<" is clear"<<endl;
                current_board.cards[city] = false;
                unsigned int t = 0;
                while(t < this->cards_of_player.size()){
                    if(this->cards_of_player.at(t) == city){
                    this->cards_of_player.erase(this->cards_of_player.begin() + t);
                    }
                t++;
                } 
                return *this;
            }
            current_board[city]--;
            cout<<"update infection level: "<<
            current_board[city]<<
            " at: "<<st<<endl;
            current_board.cards[city] = false;
            unsigned int t = 0;
            while(t < this->cards_of_player.size()){
                if(this->cards_of_player.at(t) == city){
                    this->cards_of_player.erase(this->cards_of_player.begin() + t);
                }
            t++;
            } 
        return *this;
    } 
}

