#include "OperationsExpert.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;
namespace pandemic{

    Player& OperationsExpert::build(){
        string city = ToString(this->currennt_city);
        if(this->current_board.research_lab.at(this->currennt_city)){
            cout<<"already have a lab in "<<city<<endl;
            return *this;
        }
        this->current_board.research_lab.at(this->currennt_city) = true;
        cout<<"lab has been built in: "<<city<<endl;
        return *this;
    }
    
}

