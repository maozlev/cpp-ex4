#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <vector>

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
	// cout<<board[City::MexicoCity]<<endl;
	CHECK_NOTHROW(p.treat(MexicoCity));
	// cout<<board[City::MexicoCity]<<endl;
	CHECK(board[City::MexicoCity] == 0);
	CHECK_NOTHROW(p.fly_direct(City::Cairo));
	CHECK_NOTHROW(p.treat(City::Cairo));
	CHECK(board[City::Cairo] == 2);
	CHECK_NOTHROW(p.treat(City::Cairo));
	CHECK(board[City::Cairo] == 1);
	CHECK_NOTHROW(p.treat(City::Cairo));
	CHECK(board[City::Cairo] == 0);
	cout<<"test some output"<<endl;
	cout<<board<<endl;
	std::string st = p.role();
	Dispatcher p1 {board, City::Atlanta};
	std::string st1 = p1.role();
	CHECK(st != st1); 

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
	CHECK_NOTHROW(p2.discover_cure(Color::Red));
	cout<<endl;
	cout<<"end scenario 2"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 3: Researcher"){
	Board board3;
	Researcher p {board3, City::Mumbai};
	p.take_card(City::Mumbai)
	.take_card(City::Tehran)
	.take_card(City::Moscow)
	.take_card(City::Istanbul);
	CHECK_THROWS(p.discover_cure(Color::Black));
	CHECK_THROWS(p.discover_cure(Color::Blue));
	p.take_card(City::Cairo);
	CHECK_NOTHROW(p.discover_cure(Color::Black));
	cout<<endl;
	cout<<"end scenario 3"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 4: Medic"){
	Board board4;
	Medic p {board4, City::Moscow};

	board4[StPetersburg] = 3;
	board4[Algiers] = 4;
	board4[Madrid] = 5;
	board4[NewYork] = 2;
	board4[Essen] = 7;

	CHECK(board4[StPetersburg] == 3);
	CHECK(board4[Algiers] == 4);
	CHECK(board4[Madrid] == 5);
	CHECK(board4[NewYork] == 2);
	CHECK(board4[Essen] == 7);

	p.take_card(Milan);
	p.take_card(London);
	p.take_card(Madrid);
	p.take_card(Algiers);
	p.take_card(Lagos);
	p.take_card(StPetersburg);

	p.drive(StPetersburg);
	p.build();
	p.take_card(StPetersburg);
	p.treat(StPetersburg);
	CHECK(board4[StPetersburg] == 0);
	p.take_card(StPetersburg);
	CHECK_THROWS(p.discover_cure(Blue));
	p.take_card(NewYork);
	CHECK_NOTHROW(p.discover_cure(Blue));
	p.drive(Essen);
	CHECK(board4[Essen] == 0);
	p.take_card(NewYork);
	p.fly_direct(NewYork);
	CHECK(board4[NewYork] == 0);
	p.take_card(NewYork);
	p.fly_charter(Madrid);
	CHECK(board4[Madrid] == 0);
	p.take_card(Madrid);
	p.build();
	p.fly_shuttle(StPetersburg);
	CHECK(board4[StPetersburg] == 0);
	p.fly_direct(Algiers);
	CHECK(board4[Algiers] == 4);
	p.take_card(Algiers);
	p.build();
	p.take_card(Algiers);
	p.treat(Algiers);
	CHECK(board4[Algiers] == 0);
	cout<<endl;
	cout<<"end scenario 4"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 5: Virologist"){
	Board board5;
	Virologist p {board5, City::Seoul};

	board5[StPetersburg] = 3;
	board5[Algiers] = 5;
	board5[Madrid] = 5;
	board5[NewYork] = 2;
	board5[Essen] = 7;
	board5[Jakarta] = 7;
	board5[Delhi] = 7;
	board5[Kolkata] = 3;

	CHECK(board5[StPetersburg] == 3);
	CHECK(board5[Algiers] == 5);
	CHECK(board5[Madrid] == 5);
	CHECK(board5[NewYork] == 2);
	CHECK(board5[Essen] == 7);
	CHECK(board5[Jakarta] == 7);
	CHECK(board5[Delhi] == 7);
	CHECK(board5[Kolkata] == 3);

	p.take_card(HongKong)
	.take_card(Taipei)
	.take_card(Bangkok)
	.take_card(Beijing)
	.take_card(Manila)
	.take_card(Seoul)
	.take_card(Delhi);

	p.treat(StPetersburg);
	CHECK(board5[StPetersburg] == 2);
	p.treat(StPetersburg);
	CHECK(board5[StPetersburg] == 1);
	p.treat(StPetersburg);
	CHECK(board5[StPetersburg] == 0);
	CHECK_THROWS(p.treat(StPetersburg));
	p.treat(Algiers);
	CHECK(board5[Algiers] == 4);
	CHECK_NOTHROW(p.build());
	CHECK_NOTHROW(p.discover_cure(Red));
	p.treat(Jakarta);
	CHECK(board5[Jakarta] == 0);
	CHECK_THROWS(p.treat(Jakarta));
	p.fly_direct(Delhi);
	p.take_card(Delhi);
	p.build();
	p.drive(Kolkata);
	p.treat(Delhi);
	CHECK(board5[Delhi] == 0);
	p.drive(Bangkok);
	p.treat(Kolkata);
	CHECK(board5[Kolkata] == 2);

	cout<<endl;
	cout<<"end scenario 5"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 6: GeneSplicer"){
	Board board6;
	GeneSplicer p {board6, City::Chicago};
	board6[StPetersburg] = 3;
	board6[Algiers] = 6;
	board6[Jakarta] = 7;
	board6[Johannesburg] = 3;

	p.take_card(StPetersburg);
	p.fly_direct(StPetersburg);
	p.treat(StPetersburg);
	CHECK(board6[StPetersburg] == 2);
	p.take_card(Algiers);
	p.fly_direct(Algiers);
	p.treat(Algiers);
	CHECK(board6[Algiers] == 5);
	p.take_card(Jakarta);
	p.fly_direct(Jakarta);
	p.treat(Jakarta);
	CHECK(board6[Jakarta] == 6);
	p.take_card(Johannesburg);
	p.fly_direct(Johannesburg);
	p.treat(Johannesburg);
	CHECK(board6[Johannesburg] == 2);
	p.take_card(Johannesburg);

	p.take_card(LosAngeles)
	.take_card(Taipei)
	.take_card(Bangkok)
	.take_card(Beijing)
	.take_card(Manila)
	.take_card(Chicago);
	p.build();
	CHECK_NOTHROW(p.discover_cure(Black));
	CHECK_THROWS(p.discover_cure(Red));
	p.take_card(London)
	.take_card(Taipei)
	.take_card(Bangkok)
	.take_card(Bogota)
	.take_card(Manila);
	CHECK_NOTHROW(p.discover_cure(Yellow));
	CHECK_THROWS(p.discover_cure(Blue));
	p.take_card(HongKong)
	.take_card(BuenosAires)
	.take_card(Essen)
	.take_card(Beijing)
	.take_card(Manila);
	CHECK_NOTHROW(p.discover_cure(Blue));
	CHECK_THROWS(p.discover_cure(Red));
	p.take_card(HongKong)
	.take_card(London)
	.take_card(Algiers)
	.take_card(Beijing)
	.take_card(Manila);
	CHECK_NOTHROW(p.discover_cure(Red));
	CHECK_NOTHROW(p.discover_cure(Blue));
	CHECK_NOTHROW(p.discover_cure(Black));
	CHECK_NOTHROW(p.discover_cure(Yellow));
	CHECK_NOTHROW(p.discover_cure(Red));

	p.take_card(StPetersburg);
	p.fly_direct(StPetersburg);
	p.treat(StPetersburg);
	CHECK(board6[StPetersburg] == 0);
	p.take_card(Algiers);
	p.fly_direct(Algiers);
	p.treat(Algiers);
	CHECK(board6[Algiers] == 0);
	p.take_card(Jakarta);
	p.fly_direct(Jakarta);
	p.treat(Jakarta);
	CHECK(board6[Jakarta] == 0);
	p.take_card(Johannesburg);
	p.fly_direct(Johannesburg);
	p.treat(Johannesburg);
	CHECK(board6[Johannesburg] == 0);
	
	cout<<endl;
	cout<<"end scenario 6"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 7: FieldDoctor"){
	Board board7;
	FieldDoctor p {board7, City::Mumbai};

	board7[Delhi] = 3;
	board7[Karachi] = 7;
	board7[Chennai] = 7;
	board7[Riyadh] = 3;
	board7[Baghdad] = 3;
	board7[Mumbai] = 3;

	p.treat(Delhi);
	p.treat(Karachi);
	p.treat(Chennai);
	p.treat(Mumbai);
	
	CHECK(board7[Delhi] == 2);
	CHECK(board7[Karachi] == 6);
	CHECK(board7[Chennai] == 6);
	CHECK(board7[Mumbai] == 2);

	p.take_card(Algiers);
	p.take_card(Cairo);
	p.take_card(Istanbul);
	p.take_card(Moscow);
	p.take_card(Tehran);
	p.take_card(Mumbai);
	p.build();
	p.discover_cure(Black);
	p.drive(Karachi);
	p.treat(Baghdad);
	p.treat(Riyadh);
	CHECK(board7[Baghdad] == 0);
	CHECK(board7[Riyadh] == 0);
	p.treat(Mumbai);
	CHECK(board7[Mumbai] == 0);

	cout<<endl;
	cout<<"end scenario 7"<<endl;
	cout<<endl;
}