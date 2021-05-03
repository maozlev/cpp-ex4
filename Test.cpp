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
	board[City::Kinshasa] = 3;      
    CHECK(board[City::Kinshasa] == 3);
	board[City::Kinshasa] = 2;      
    CHECK(board[City::Kinshasa] == 2);
	board[City::MexicoCity] = 3; 
    CHECK(board[City::MexicoCity] == 3);
	board[City::HoChiMinhCity] = 1; 
    CHECK(board[City::HoChiMinhCity] == 1);
	board[City::Chicago] = 1;           
	CHECK(board[City::Chicago] == 1);
	board[City::Cairo] = 3;
    CHECK(board[City::Cairo] == 3);
	CHECK(f != board.is_clean());
	OperationsExpert p {board, City::Atlanta};  // initialize an "operations expert" p on the given board, in Atlanta.
	p.take_card(City::Johannesburg)
	 .take_card(City::Khartoum)
	 .take_card(City::SaoPaulo)
	 .take_card(City::BuenosAires)
	 .take_card(City::Cairo);
	CHECK_NOTHROW(p.drive(Miami));
	CHECK_NOTHROW(p.build());
	CHECK_NOTHROW(p.fly_direct(City::Johannesburg));
	CHECK_NOTHROW(p.build());
	CHECK_NOTHROW(p.fly_shuttle(City::Miami));
	p.take_card(City::Miami);
	CHECK_NOTHROW(p.fly_charter(Chicago));
	CHECK_THROWS(p.fly_direct(City::Johannesburg));
	CHECK_NOTHROW(p.drive(SanFrancisco));
	CHECK_NOTHROW(p.drive(LosAngeles));
	CHECK_NOTHROW(p.build());
	CHECK_THROWS(p.discover_cure(Color::Yellow));
	p.take_card(City::Johannesburg);
	p.take_card(City::Lagos);
	p.take_card(City::Miami);
	CHECK_NOTHROW(p.discover_cure(Color::Yellow));
	CHECK_NOTHROW(cout<<p.role()<<endl);
	CHECK_NOTHROW(p.drive(MexicoCity));
	CHECK_NOTHROW(p.treat(MexicoCity));
	CHECK(board[City::MexicoCity] == 0);
	CHECK_NOTHROW(p.fly_direct(City::Cairo));
	CHECK_NOTHROW(p.treat(City::Cairo));
	CHECK(board[City::Cairo] == 2);
	CHECK_NOTHROW(p.treat(City::Cairo));
	CHECK(board[City::Cairo] == 1);
	CHECK_NOTHROW(p.treat(City::Cairo));
	CHECK(board[City::Cairo] == 0);
}
TEST_CASE("game scenario 1: Dispacher"){

}