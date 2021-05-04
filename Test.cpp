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

// AUTHOR - MAOZ LEV

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
	CHECK_NOTHROW(p.build()); //build in miami
	CHECK_NOTHROW(p.fly_direct(City::Johannesburg));//drop johannesburg
	CHECK_NOTHROW(p.build());//build in johannesburg - no throw because OperationsExpert
	CHECK_NOTHROW(p.fly_shuttle(City::Miami)); // no throw because 2 cities have stations
	p.take_card(City::Miami);
	CHECK_NOTHROW(p.fly_charter(Chicago)); // drop miami
	CHECK_THROWS(p.fly_direct(City::Johannesburg)); // there is no card of johannesburg
	CHECK_NOTHROW(p.drive(SanFrancisco)); // connected cities chicago ---> SanFrancisco
	CHECK_NOTHROW(p.drive(LosAngeles)); // connected cities SanFrancisco ---> LosAngeles 
	CHECK_NOTHROW(p.build()); // build in LosAngeles
	CHECK_THROWS(p.discover_cure(Color::Yellow)); // no 5 yellow cards
	p.take_card(City::Johannesburg);
	p.take_card(City::Lagos);
	p.take_card(City::Miami);
	CHECK_NOTHROW(p.discover_cure(Color::Yellow)); // drop 5 yellow cards
	CHECK_NOTHROW(cout<<p.role()<<endl); // check if print
	CHECK_NOTHROW(p.drive(MexicoCity));
	CHECK_NOTHROW(p.treat(MexicoCity));
	CHECK(board[City::MexicoCity] == 0); // there is yellow cure
	CHECK_NOTHROW(p.fly_direct(City::Cairo));// drop cairo card
	CHECK_NOTHROW(p.treat(City::Cairo)); // cairo-1 there is no Black cure
	CHECK(board[City::Cairo] == 2);
	CHECK_NOTHROW(p.treat(City::Cairo)); // cairo-1 there is no Black cure
	CHECK(board[City::Cairo] == 1);
	CHECK_NOTHROW(p.treat(City::Cairo)); // cairo-1 there is no Black cure
	CHECK(board[City::Cairo] == 0); // cairo-1 there is no Black cure
	CHECK_THROWS(p.treat(City::Cairo)); // cairo clear it should throw
	cout<<"test some output"<<endl;
	cout<<board<<endl; // check print board some way
	Dispatcher p1 {board, City::Atlanta};
	Scientist p2 {board, City::Atlanta,3};
	Researcher p3 {board, City::Atlanta};
	Medic p4 {board, City::Atlanta};
	Virologist p5 {board, City::Atlanta};
	GeneSplicer p6 {board, City::Atlanta};
	FieldDoctor p7 {board, City::Atlanta};
	std::string st = p.role();
	std::string st1 = p1.role();
	std::string st2 = p2.role();
	std::string st3 = p3.role();
	std::string st4 = p4.role();
	std::string st5 = p5.role();
	std::string st6 = p6.role(); 
	CHECK(st != st1); // check if the role is different for each class..
	CHECK(st != st2);
	CHECK(st != st3);
	CHECK(st != st4);
	CHECK(st != st5);
	CHECK(st != st6);
	cout<<endl;
	cout<<"end scenario 0"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 1: Dispacher"){ // check only his inheribate function
	Board board1;
	Dispatcher p1 {board1, City::Madrid};
	CHECK_THROWS(p1.fly_direct(City::SanFrancisco)); // have no cards
	CHECK_THROWS(p1.build()); // have no cards
	p1.take_card(City::Madrid);
	CHECK_NOTHROW(p1.build());
	CHECK_NOTHROW(p1.fly_direct(City::SanFrancisco)); // can fly because madrid has a station 
	p1.take_card(City::SanFrancisco);
	CHECK_NOTHROW(p1.fly_charter(City::HoChiMinhCity)); // drop SanFrancisco
	CHECK_THROWS(p1.fly_direct(City::SanFrancisco)); // card isnt exist
	cout<<endl;
	cout<<"end scenario 1"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 2: Scientist"){ // check only his inheribate function
	Board board2;
	Scientist p3 {board2, City::Osaka, 3};

	p3.take_card(City::Osaka)
	.take_card(City::Seoul)
	.take_card(City::Taipei)
	.take_card(City::Manila)
	.take_card(City::Sydney);
	
	p3.build(); // build in osaka. drop osaka
	p3.fly_direct(City::Sydney);  // drop sydney
	p3.fly_direct(City::Taipei);  // drop taipei
	CHECK_THROWS(p3.discover_cure(Color::Red)); // have just 2 red cards
	p3.take_card(City::Sydney);
	p3.take_card(City::Taipei);
	p3.build(); // build in taipei. drop taipei
	CHECK_NOTHROW(p3.discover_cure(Color::Red)); // now have 3 red cards

	cout<<endl;
	cout<<"end scenario 2"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 3: Researcher"){
	Board board3;
	Researcher p {board3, City::Mumbai}; // start in mumbai
	p.take_card(City::Mumbai)
	.take_card(City::Tehran)
	.take_card(City::Moscow)
	.take_card(City::Istanbul);
	CHECK_THROWS(p.discover_cure(Color::Black)); // need 5 black cards- have 4
	CHECK_THROWS(p.discover_cure(Color::Blue)); // need 5 blue cards- have 0
	p.take_card(City::Cairo); // 5 black cards
	CHECK_NOTHROW(p.discover_cure(Color::Black)); // cairo have no station but reasearcher can discover cure
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
	p.build(); // build in StPetersburg. drop StPetersburg 
	p.take_card(StPetersburg);
	p.treat(StPetersburg); // treat full StPetersburg
	CHECK(board4[StPetersburg] == 0);
	CHECK_THROWS(p.discover_cure(Blue)); // have 4 cards- throw
	p.take_card(Paris);
	p.take_card(NewYork);
	CHECK_NOTHROW(p.discover_cure(Blue)); // good- have 5 cards
	p.drive(Essen);
	CHECK(board4[Essen] == 0); // arrive to blue city with blue cure
	p.take_card(NewYork);
	p.fly_direct(NewYork); // drop new york
	CHECK(board4[NewYork] == 0); // arrive to blue city with blue cure
	p.take_card(NewYork);
	p.fly_charter(Madrid);
	CHECK(board4[Madrid] == 0); // arrive to blue city with blue cure
	p.take_card(Madrid);
	p.build(); // build in madrid
	p.fly_shuttle(StPetersburg);
	CHECK(board4[StPetersburg] == 0); // arrive to blue city with blue cure
	p.fly_direct(Algiers);
	CHECK(board4[Algiers] == 4); // arrive to black city with blue cure noting happen
	p.treat(Algiers);
	CHECK(board4[Algiers] == 0); // medic treat --> 0
	cout<<endl;
	cout<<"end scenario 4"<<endl;
	cout<<endl;
}

TEST_CASE("game scenario 5: Virologist"){
	Board board5;
	Virologist p {board5, City::Seoul}; // statrs at seoul

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

	p.take_card(StPetersburg);
	p.take_card(Algiers);
	p.take_card(Kolkata);

	CHECK_NOTHROW(p.treat(StPetersburg)); // treat -1 drop card
	CHECK_THROWS(p.treat(StPetersburg)); // cant treat no card
	CHECK(board5[StPetersburg] == 2); 
	p.take_card(StPetersburg);
	CHECK_NOTHROW(p.treat(StPetersburg)); // treat -1 drop card
	CHECK(board5[StPetersburg] == 1); 
	CHECK_THROWS(p.fly_direct(StPetersburg)); // no card of stpetersburg
	p.take_card(StPetersburg);
	CHECK_NOTHROW(p.treat(StPetersburg)); // treat -1 drop card
	CHECK(board5[StPetersburg] == 0); 
	CHECK_THROWS(p.treat(StPetersburg)); // treat -1 -> throw, already 0
	CHECK_NOTHROW(p.treat(Algiers)); // treat -1 . drop card
	CHECK(board5[Algiers] == 4); 
	p.take_card(Algiers);
	CHECK_NOTHROW(p.fly_direct(Algiers)); // drop Algier
	p.take_card(Algiers);
	CHECK_NOTHROW(p.build()); // build in algiers drop card
	CHECK_NOTHROW(p.discover_cure(Red)); 
	p.take_card(Jakarta);
	CHECK_NOTHROW(p.treat(Jakarta)); // treat with cure  = 0 
	CHECK(board5[Jakarta] == 0);
	p.take_card(Jakarta);
	CHECK_THROWS(p.treat(Jakarta)); // jakarta clear already
	CHECK_NOTHROW(p.fly_direct(Delhi));
	p.take_card(Delhi);
	CHECK_NOTHROW(p.build()); // drop delhi
	CHECK_NOTHROW(p.drive(Kolkata)); 
	p.take_card(Delhi);
	CHECK_NOTHROW(p.treat(Delhi));
	CHECK(board5[Delhi] == 6); // treat -1
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

	// regular treat without cure

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

	// take 5 cards with differnt colors
	// and find all cures

	p.take_card(LosAngeles)
	.take_card(Taipei)
	.take_card(Bangkok)
	.take_card(Beijing)
	.take_card(Manila)
	.take_card(Chicago);
	p.build();
	CHECK_NOTHROW(p.discover_cure(Black)); 
	CHECK_THROWS(p.discover_cure(Red)); // not enought cards
	p.take_card(London)
	.take_card(Taipei)
	.take_card(Bangkok)
	.take_card(Bogota)
	.take_card(Manila);
	CHECK_NOTHROW(p.discover_cure(Yellow));
	CHECK_THROWS(p.discover_cure(Blue)); // not enought cards
	p.take_card(HongKong)
	.take_card(BuenosAires)
	.take_card(Essen)
	.take_card(Beijing)
	.take_card(Manila);
	CHECK_NOTHROW(p.discover_cure(Blue));
	CHECK_THROWS(p.discover_cure(Red)); // not enought cards
	p.take_card(HongKong)
	.take_card(London)
	.take_card(Algiers)
	.take_card(Beijing)
	.take_card(Manila);
	CHECK_NOTHROW(p.discover_cure(Red));

	// already discoverd should not throw
	
	CHECK_NOTHROW(p.discover_cure(Blue));
	CHECK_NOTHROW(p.discover_cure(Black));
	CHECK_NOTHROW(p.discover_cure(Yellow));
	CHECK_NOTHROW(p.discover_cure(Red));

	// cheack if cures working and treats to 0

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

	// check if treat connected cities

	CHECK_NOTHROW(p.treat(Delhi));
	CHECK_NOTHROW(p.treat(Karachi));
	CHECK_NOTHROW(p.treat(Chennai));
	CHECK_NOTHROW(p.treat(Mumbai));

	CHECK(board7[Delhi] == 2);
	CHECK(board7[Karachi] == 6);
	CHECK(board7[Chennai] == 6);
	CHECK(board7[Mumbai] == 2);

	// cant treat no connected cities
	
	CHECK_THROWS(p.treat(London));
	CHECK_THROWS(p.treat(Sydney));
	CHECK_THROWS(p.treat(Tehran));


	p.take_card(Algiers);
	p.take_card(Cairo);
	p.take_card(Istanbul);
	p.take_card(Moscow);
	p.take_card(Tehran);
	p.take_card(Mumbai);
	p.build();
	p.discover_cure(Black);

	// check treat with cure if treat to 0
	p.drive(Karachi);
	CHECK_NOTHROW(p.treat(Baghdad));
	CHECK_NOTHROW(p.treat(Riyadh));
	CHECK_NOTHROW(p.treat(Mumbai));
	
	CHECK(board7[Baghdad] == 0);
	CHECK(board7[Riyadh] == 0);
	CHECK(board7[Mumbai] == 0);

	// cant cure non connected cities

	CHECK_THROWS(p.treat(Moscow));
	CHECK_THROWS(p.treat(Istanbul));
	

	cout<<endl;
	cout<<"end scenario 7"<<endl;
	cout<<endl;
}