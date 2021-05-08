#include "Player.hpp"


#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>


const int min_card_to_cure = 5;
using namespace std;

namespace pandemic{

    Player::Player(Board& board, City city):
    current_board(board), currennt_city(city)
    {
        std::vector <City> cards_of_playerr;
        this->cards_of_player = cards_of_playerr;
    } 

    Player& Player::drive(City city){
        if(currennt_city == city){
            throw std::invalid_argument{"already in city"};
        }
        string st = ToString(city);
        if(this->current_board.is_neighbors(this->currennt_city, city)){
            this->currennt_city = city;
            // cout<<"moving to: "+st<<endl;
            return *this;
        }
        throw std::invalid_argument{st+" is not connected"};
    }

    Player& Player::fly_direct(City city){
        if(currennt_city == city){
            throw invalid_argument{"already in city"};
        }
        if(!(find(cards_of_player.begin(), cards_of_player.end(), city) != cards_of_player.end())){
            throw invalid_argument{"no card of this city"}; 
        }
        cards_of_player.erase(remove(cards_of_player.begin(), cards_of_player.end(), city), cards_of_player.end());
        currennt_city = city;
        return *this;
    }

    Player& Player::fly_charter(City city){
        if(currennt_city == city){
            throw std::invalid_argument{"already in city"};
        }
        City need_to_drop = this->currennt_city;
        string st = ToString(city);
        string st1 = ToString(need_to_drop);
        unsigned int t = 0;
        if(this->cards_of_player.empty()){
            throw std::invalid_argument{"you dont have any cards"};
        }
        while(t < this->cards_of_player.size()){
            if(this->cards_of_player.at(t) == need_to_drop){
                this->currennt_city = city;
                this->cards_of_player.erase(this->cards_of_player.begin() + t);
                this->current_board.cards.at(need_to_drop) = false;
                return *this;
            }
            t++;
        } 
        throw std::invalid_argument{"you dont have card of this city"};
    }

    Player& Player::fly_shuttle(City city){
        if(this->currennt_city == city){
            throw invalid_argument{"already in city"};
        } 
        string st = ToString(city);
        string st1 = ToString(this->currennt_city);
        if(this->current_board.research_lab.at(city)){
            if(this->current_board.research_lab.at(this->currennt_city)){
            //    cout<<"fly from: "<<st1<<"to "<<st<<endl;
               this->currennt_city = city;
               return *this;
            }
        }
        if(!(this->current_board.research_lab.at(city))){
            throw std::invalid_argument{st+" dont have research lab"};     
        }
        if(!(this->current_board.research_lab.at(this->currennt_city))){
            throw std::invalid_argument{st1+" dont have research lab"};     
        }
        return *this;
    }

    Player& Player::build(){
        City city = this->currennt_city;
        string st = ToString(city);
        if(this->current_board.research_lab.at(city)){
            // cout<<"you already have a lab in the city: "<<st<<endl;
            return *this;
        }
        if(this->cards_of_player.empty()){
            throw std::invalid_argument{"you dont have any cards"};
            return *this;
        }
        unsigned int t = 0;
        while(t < this->cards_of_player.size()){
            if(this->cards_of_player.at(t) == city){
                this->current_board.research_lab.at(city) = true;
                this->current_board.cards.at(city) = false;
                this->cards_of_player.erase(this->cards_of_player.begin() + t);
                // cout<<"built lab at: "+st<<endl;
                // cout<<"drop: "+st<<endl;
                return *this;
            }
            t++;
        } 
        throw std::invalid_argument{"you dont have card of this city: "+st};
    }

    Player& Player::discover_cure(Color color){
        string st = ToString(this->currennt_city);
        string c = ToString(color);
        if(!this->current_board.cure.at(color)){
            if(!this->current_board.research_lab.at(this->currennt_city)){
                throw logic_error{st+" have no lab!"};
            }
            int num_of_color_card = get_num_of_color(color);
            if(num_of_color_card < min_card_to_cure){
                throw logic_error{"you dont have enough "+c+" cards"};
            }
            int sum=0;
            unsigned int i = 0;
            while(true){
                if(sum == min_card_to_cure){
                    break;
                }
                if(this->current_board.colors.at(this->cards_of_player.at(i)) == color){
                    this->current_board.cards.at(this->cards_of_player.at(i)) = false;
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

    Player& Player::treat(City city){
        if(currennt_city == city){
            if(current_board[city] <= 0){
                throw invalid_argument{" is already clear"};
            }
            if(current_board.cure.at(current_board.colors.at(city))){
                current_board[city] = 0;
                return *this;
            }
            current_board[city]--;
            return *this;
        }
       throw invalid_argument{"not in city"};
    }


    Player& Player::take_card(City city){
        string st = ToString(city);
        // if(this->current_board.card_in_game(city)){
        //     // cout<<st+" in the game already"<<endl;
        //     return *this;
        // }
        cards_of_player.insert(cards_of_player.begin(), city);
        current_board.cards[city] = true;
        // cout<<"take card: "<<st<<endl;
        return *this;
    }

    int Player::get_num_of_color(Color color){
        int sum = 0;
        for (size_t i = 0; i < this->cards_of_player.size(); i++){
            if(this->current_board.colors.at(this->cards_of_player.at(i)) == color){
                sum++;
            }
        }
            return sum;
    }
    
};
       
