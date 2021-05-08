#include "Researcher.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>


const int min_card_to_cure = 5;
using namespace std;
namespace pandemic{

    Player& Researcher::discover_cure(Color color){
        string st = ToString(this->currennt_city);
        string c = ToString(color);
        if(!this->current_board.cure.at(color)){
            int num_of_color_card = get_num_of_color(color);
            if(num_of_color_card<min_card_to_cure){
                throw invalid_argument{"you dont have enough "+c+" cards"};
            }
            int sum=0;
            unsigned int i = 0;
            while(true){
                if(sum == min_card_to_cure){
                    break;
                }
                if(this->current_board.colors.at(this->cards_of_player.at(i)) == color){
                    this->cards_of_player.erase(this->cards_of_player.begin() + i);
                    i--;
                    sum++;
                }
                i++;
            }
            this->current_board.cure.at(color) = true;
            // cout<<"drop: "<<sum<<" cards"<<endl;
        }
        // cout<<"discoverd: "<<c<<" cure!"<<endl;
        return *this;
    }    
    
}

