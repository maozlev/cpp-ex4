#include "Dispatcher.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& Dispatcher::fly_direct(City city){
        if(currennt_city == city){
            throw invalid_argument{"already in city"};
        }
        string st = ToString(city);
        if(current_board.research_lab.at(currennt_city)){
            currennt_city = city;
            return *this;
        }
        //else he need to pay like anyone else
        return Player::fly_direct(city);
        
    }
}

