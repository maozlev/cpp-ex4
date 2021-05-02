#include "Researcher.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& Researcher::discover_cure(Color color){
        string st = ToString(this->currennt_city);
        string c = ToString(color);
        if(this->current_board.cure.at(color) == false){
            int num_of_color_card = get_num_of_color(color);
            if(num_of_color_card < 5){
                throw logic_error{"you not have enoght "+c+" cards"};
            }
            int sum=0;
            for (unsigned int i = 0; i < this->cards_of_player.size(); i++){
                if(sum == 5){
                    break;
                }
                if(this->current_board.colors.at(this->cards_of_player.at(i)) == color){
                    this->cards_of_player.erase(this->cards_of_player.begin() + i);
                    sum++;
                }
            }
            this->current_board.cure.at(color) = true;
            cout<<"drop: "<<sum<<" cards"<<endl;
        }
        cout<<"discoverd: "<<c<<" cure!"<<endl;
        return *this;
    }
}

