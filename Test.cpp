#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

TEST_CASE("game scenario 1: OperationsExpert"){

    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	bool f=true;
	CHECK(f == board.is_clean());
	
	board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
    CHECK(board[City::Kinshasa] == 3);
	board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
    CHECK(board[City::Kinshasa] == 2);
	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
    CHECK(board[City::MexicoCity] == 3);
	board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
    CHECK(board[City::HoChiMinhCity] == 1);
	board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    CHECK(board[City::Chicago] == 1);
	board[City::Algiers] = 3;
    CHECK(board[City::Algiers] == 3);

	OperationsExpert player {board, City::Atlanta};  // initialize an "operations expert" player on the given board, in Atlanta.
	player.take_card(City::Johannesburg)
	 .take_card(City::Khartoum)
	 .take_card(City::SaoPaulo)
	 .take_card(City::BuenosAires)
	 .take_card(City::HoChiMinhCity);

}