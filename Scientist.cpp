#include "Scientist.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& Scientist::discover_cure(Color color){
        string st = ToString(this->currennt_city);
        string c = ToString(color);
        if(!this->current_board.cure.at(color)){
            if(!this->current_board.research_lab.at(this->currennt_city)){
                throw logic_error{st+" have no lab!"};
            }
            int num_of_color_card = get_num_of_color(color);
            if(num_of_color_card < Scientist::n){
                throw logic_error{"you not have enoght "+c+" cards"};
            }
            int sum=0;
            unsigned int i = 0;
            while(true){
                if(sum == Scientist::n){
                    break;
                }
                if(this->current_board.colors.at(this->cards_of_player.at(i)) == color){
                    this->cards_of_player.erase(this->cards_of_player.begin() + i);
                    sum++;
                    i--;
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

