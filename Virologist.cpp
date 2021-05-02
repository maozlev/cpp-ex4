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
        if(currennt_city == city){
            if(current_board.infection_level.at(city) <= 0){
                throw logic_error{st+" is already clear"};
            }
            if(current_board.research_lab.at(city) == true){
                current_board[city] = 0;
                cout<<"update infection level: "<<
                current_board[city]<<
                " at: "<<st<<endl;
                cout<<st<<" is clear"<<endl;
                return *this;
            }
            current_board[city]--;
            cout<<"update infection level: "<<
            current_board[city]<<
            " at: "<<st<<endl;
            return *this;
        }
        cout<<"go to the city: "<<st<<endl;
        return *this;
    }
}

