#include "Dispatcher.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& Dispatcher::fly_direct(City city){
        string st = ToString(city);
        if(this->current_board.research_lab.at(this->currennt_city)){
            this->currennt_city = city;
            // cout<<"fly direct to "<<st<<endl;
            return *this;
        }
        //else he need to pay like anyone else
            Player::fly_direct(city);
        return *this;
    }
}

