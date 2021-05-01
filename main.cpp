#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	Board board;  // Initialize an empty board (with 0 disease cubes in any city).
    cout<<board.infection_level.at(City::Algiers)<<endl;
    // board[City::Kinshasa];
    // cout<<board[City::Kinshasa]<<endl;
	// board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
	// board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
	// board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
	// board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
	// board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    
    return 0;
}