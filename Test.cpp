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

TEST_CASE("game scenario 0: OperationsExpert"){ // check all function

    Board board;  
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
	OperationsExpert p {board, City::Atlanta}; 
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
	cout<<endl;
	cout<<"end scenario 0"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 1: Dispacher"){ // check only his inheribate function
	Board board1;
	Dispatcher p1 {board1, City::Madrid};
	CHECK_THROWS(p1.fly_direct(City::SanFrancisco));
	CHECK_THROWS(p1.build());
	p1.take_card(City::Madrid);
	CHECK_NOTHROW(p1.build());
	CHECK_NOTHROW(p1.fly_direct(City::SanFrancisco));
	p1.take_card(City::SanFrancisco);
	CHECK_NOTHROW(p1.fly_charter(City::HoChiMinhCity));
	CHECK_THROWS(p1.fly_direct(City::SanFrancisco));
	cout<<endl;
	cout<<"end scenario 1"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 2: Scientist"){ // check only his inheribate function
	Board board2;
	Scientist p3 {board2, City::Osaka, 3};
	Scientist p2 {board2, City::Osaka, 2};
	
	p3.take_card(City::Osaka)
	.take_card(City::Seoul)
	.take_card(City::Taipei)
	.take_card(City::Manila)
	.take_card(City::Sydney);

	p2.take_card(City::Osaka);
	
	p3.build();
	p3.fly_direct(City::Sydney);
	CHECK_THROWS(p3.discover_cure(Color::Red));
	p3.take_card(City::Sydney);
	p3.build();
	CHECK_NOTHROW(p3.discover_cure(Color::Red));
	CHECK_THROWS(p2.discover_cure(Color::Red));
	p2.take_card(City::HoChiMinhCity);
	p2.build();
	p2.take_card(City::HoChiMinhCity);
	CHECK_THROWS(p2.discover_cure(Color::Red));
	p2.take_card(City::Osaka);
	CHECK_NOTHROW(p2.discover_cure(Color::Red));

	cout<<endl;
	cout<<"end scenario 2"<<endl;
	cout<<endl;
}