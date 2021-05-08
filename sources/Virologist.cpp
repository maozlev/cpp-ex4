#include "Virologist.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>



using namespace std;
namespace pandemic{

    Player& Virologist::treat(City city){
        string st = ToString(city);
        if(city == currennt_city){
            return Player::treat(city);
        }

        if(count(cards_of_player.begin(), cards_of_player.end(), city) == 0){
            throw invalid_argument{"no have card of "+st};
        }

        Color c = current_board.colors.at(city);
        if(current_board[city] == 0){
            throw invalid_argument{st+" is already clear"};
        }
        if(current_board.cure.at(c)){
            current_board[city] = 0;
        }else{
            current_board[city]--;
        }
        current_board.cards[city] = false;
        cards_of_player.erase(remove(cards_of_player.begin(), cards_of_player.end(), city), cards_of_player.end());
        return *this;
    } 
}

