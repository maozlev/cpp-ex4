#include "Dispatcher.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& Dispatcher::fly_direct(City city){
        if(this->current_board.research_lab.at(this->currennt_city) == true){
            this->currennt_city = city;
            return *this;
        }
        //else he need to pay like anyone else
        else{
            Player::fly_direct(city);
        }
        return *this;
    }
}

