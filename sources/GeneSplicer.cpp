#include "GeneSplicer.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>

const int min_card_to_cure = 5;
using namespace std;
namespace pandemic{

    Player& GeneSplicer::discover_cure(Color color){
        string st = ToString(this->currennt_city);
        string c = ToString(color);
        int num_of_card = cards_of_player.size();
        if(num_of_card < min_card_to_cure){
            throw invalid_argument{"you dont have enough "+c+" cards"};
        }
        if(!this->current_board.cure.at(color)){
            if(!this->current_board.research_lab.at(this->currennt_city)){
                throw invalid_argument{st+" have no lab!"};
            }
            int sum=0;
            unsigned int i = 0;
            while(true){
                if(sum == min_card_to_cure){
                    break;
                }
                this->current_board.cards.at(this->cards_of_player.at(i)) = false;
                this->cards_of_player.erase(this->cards_of_player.begin() + i);
                i--;
                sum++;
                i++;
            }
            this->current_board.cure.at(color) = true;
            // cout<<"drop: "<<sum<<" cards"<<endl;
        }
        // cout<<"discoverd: "<<c<<" cure!"<<endl;
        return *this;
    }

}

