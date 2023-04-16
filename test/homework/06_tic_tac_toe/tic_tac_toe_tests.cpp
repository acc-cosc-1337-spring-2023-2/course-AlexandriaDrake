#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <memory>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

using std::unique_ptr; using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") 
{
	REQUIRE(true == true);
}
/* Homework 6 Test Cases:
1)Create an instance of tic_tac_toe game
2)Call the start game function with X first player
3)Call mark board 9 times using numbers 1 to 9 (this test case will eventually be the test for CAT tie case). Positions: 
1,2,3,4,5,7,6,9,8. 
4)Check if the game is over after every mark board function call.
*/

/* Homework 7 Update to Test Case:
1)Create an instance of tic_tac_toe game
2)Call the start game function
3)Call mark board 9 times using numbers 1 to 9 
4) Verify the winner is C
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/
TEST_CASE("Test if the game is over after every mark board function call.")
{
	unique_ptr<tic_tac_toe> test = make_unique<tic_tac_toe3>();

	test->start_game("X");

	test->mark_board(1);
	REQUIRE(test->game_over() == false);

	test->mark_board(2);
	REQUIRE(test->game_over() == false);
	
	test->mark_board(3);
	REQUIRE(test->game_over() == false);
	
	test->mark_board(4);
	REQUIRE(test->game_over() == false);

	test->mark_board(5);
	REQUIRE(test->game_over() == false);

	test->mark_board(7);
	REQUIRE(test->game_over() == false);

	test->mark_board(6);
	REQUIRE(test->game_over() == false);

	test->mark_board(9);
	REQUIRE(test->game_over() == false);

	test->mark_board(8);
	REQUIRE(test->game_over() == true);

	REQUIRE(test->get_winner() == "C");

}

/* Homework 7 Update: 
Modify this test case to determine if there is a tie
Test game over if 9 slots are selected.
1)Create an instance of tic_tac_toe game
2)Call the start game function
3)Call mark board 9 times using numbers 1 to 9 
4) Verify the winner is C
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/
TEST_CASE("Test if the game is over after every mark board function call - Winner C")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(7);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(6);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(8);
	REQUIRE(test_instance->game_over() == true);

	REQUIRE(test_instance->get_winner() == "C");
;
}

/* Homework 7
Create an instance of tic_tac_toe, 
call start_game() function with argument X, verify that get_player() returns X
*/
TEST_CASE("Test first player set to X.")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	REQUIRE(test_instance->get_player() == "X"); 
}
/* Homework 7
Create an instance of tic_tac_toe, 
call start_game() function with argument O, verify that get_player() returns O
*/

TEST_CASE("Test first player set to O.")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("O");

	REQUIRE(test_instance->get_player() == "O"); 
}

/* Homework 7
Create an instance of tic_tac_toe, 
call start_game() function with argument X, 
set positions for first player X to 1,4,7.  
Pick other positions for O. 
Verify that game_over() is true. 
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win by first column.")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(7);
	REQUIRE(test_instance->game_over() == true); 
	REQUIRE(test_instance->get_winner() == "X");
}
/* Homework 7
Create an instance of tic_tac_toe, 
call start_game() function with argument X, 
set positions for first player X to 2,5,8.  
Pick other positions for O. 
Verify that game_over() is true.
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win by second column")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(8);
	REQUIRE(test_instance->game_over() == true); 
	REQUIRE(test_instance->get_winner() == "X");
}
/* Homework 7
Create an instance of tic_tac_toe, 
call start_game() function with argument X, 
set positions for first player X to 3,6,9.  
Pick other positions for O. 
Verify that game_over() is true.  
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win by third column")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(6);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == true); 
	REQUIRE(test_instance->get_winner() == "X");
}
/* Homework 7
Create an instance of tic_tac_toe, 
call start_game() function with argument X, 
set positions for first player X to 1,2,3.  
Pick other positions for O. 
Verify that game_over() is true.  
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win by first row")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == true); 
	REQUIRE(test_instance->get_winner() == "X");
}
/* Homework 7
 Create an instance of tic_tac_toe, 
call start_game() function with argument X, 
set positions for first player X to 4,5,6.  
Pick other positions for O. 
Verify that game_over() is true.    
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win by second row")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(6);
	REQUIRE(test_instance->game_over() == true); 
	REQUIRE(test_instance->get_winner() == "X");
}

/* Homework 7
Create an instance of tic_tac_toe, 
call start_game() function with argument X,
 set positions for first player X to  7,8,9.  
Pick other positions for O. Verify that game_over() is true.  
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win by third row")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	test_instance->mark_board(7);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(8);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == true); 
	REQUIRE(test_instance->get_winner() == "X");
}

/* Homework 7
 Create an instance of tic_tac_toe, 
call start_game() function with argument X, 
set positions for first player X to 1,5,9.  
Pick other positions for O. Verify that game_over() is true.  
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win diagonally from top left")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == true); 
	REQUIRE(test_instance->get_winner() == "X");
}

/* Homework 7
Create an instance of tic_tac_toe, 
call start_game() function with argument X, 
set positions for first player X to 7,5,3. 
 Pick other positions for O. 
Verify that game_over() is true.  
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win diagonally from bottom left")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe3>();
	test_instance->start_game("X");

	test_instance->mark_board(7);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == true); 
	REQUIRE(test_instance->get_winner() == "X");
}

/*Homework 8 Test Cases:
add new assertion REQUIRES... to validate that X or O winner (for all test cases)
Play at least 3 games -- X, O, & C as winners
Add the games to the tic_tac_toeManager class
test get winner total for correct tally 
*/

TEST_CASE("Test tic_tac_toe_manager") 
{
	//Test win diagonally from bottom left. X Wins 1

	tic_tac_toe_manager manager_instance;

	unique_ptr<tic_tac_toe> test_instance1 = make_unique<tic_tac_toe3>();
	test_instance1->start_game("X");

	test_instance1->mark_board(7);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(1);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(5);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(2);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(3);
	REQUIRE(test_instance1->game_over() == true); 
	REQUIRE(test_instance1->get_winner() == "X");

	manager_instance.save_game(test_instance1);
	int x, o, t;
	manager_instance.get_winner_totals(x, o, t);
	REQUIRE(x == 1);
	REQUIRE(o == 0);
	REQUIRE(t == 0);

	//Test win by first column. O Wins 1

	unique_ptr<tic_tac_toe> test_instance2 = make_unique<tic_tac_toe3>();
	test_instance2->start_game("O");

	test_instance2->mark_board(1);
	REQUIRE(test_instance2->game_over() == false);

	test_instance2->mark_board(2);
	REQUIRE(test_instance2->game_over() == false);

	test_instance2->mark_board(4);
	REQUIRE(test_instance2->game_over() == false);

	test_instance2->mark_board(3);
	REQUIRE(test_instance2->game_over() == false);

	test_instance2->mark_board(7);
	REQUIRE(test_instance2->game_over() == true);
	REQUIRE(test_instance2->get_winner() == "O");

	manager_instance.save_game(test_instance2);

	manager_instance.get_winner_totals(x, o, t);
	REQUIRE(x == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 0);

	//Test tied test-> T Wins 1.
	unique_ptr<tic_tac_toe> test_instance3 = make_unique<tic_tac_toe3>();
	test_instance3->start_game("X");

	test_instance3->mark_board(1);
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(2);
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(3);
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(4);
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(5);
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(7);
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(6);
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(9);
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(8);
	REQUIRE(test_instance3->game_over() == true);
	REQUIRE(test_instance3->get_winner() == "C");

	manager_instance.save_game(test_instance3);

	manager_instance.get_winner_totals(x, o, t);
	REQUIRE(x == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}

//Test Cases for tic_taco_toe4 Games:

TEST_CASE("Test game over if 16 slots are selected.")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(1); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(2); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(3); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(4); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(6); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(5); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(7); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(8); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(10); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(9); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(12); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(11); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(13); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(14); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(15); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(16); 
	REQUIRE(test_instance->game_over() == true);

	REQUIRE(test_instance->get_winner() == "C");

	/*
	x|o|x|o 1  2  3  4
	o|x|x|o 5  6  7  8
	o|x|o|x 9  10 11 12
	x|o|x|o
	*/
}
TEST_CASE("Test first player set to X 4.")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	REQUIRE(test_instance->get_player() == "X"); 
}
TEST_CASE("Test first player set to O 4.")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("O");

	REQUIRE(test_instance->get_player() == "O"); 
}
TEST_CASE("Test win by first column 4.")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(1); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(2); 
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(6);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(13);
	REQUIRE(test_instance->game_over() == true); 

	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by second column 4")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(6);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(10);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(14);
	REQUIRE(test_instance->game_over() == true); 

	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by third column 4")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(7);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(11);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(12);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(15);
	REQUIRE(test_instance->game_over() == true); 
	
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by fourth column 4")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(8);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(12);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(11);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(16);
	REQUIRE(test_instance->game_over() == true); 
	
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by first row 4")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(10);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(16);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == true); 
	
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by second row 4")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(6);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(7);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(8);
	REQUIRE(test_instance->game_over() == true); 
	
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by third row 4")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(10);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(11);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(12);
	REQUIRE(test_instance->game_over() == true); 
	
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by fourth row 4")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(13);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(14);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(15);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(16);
	REQUIRE(test_instance->game_over() == true); 
	
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win diagonlly from top left 4")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(6);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(11);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(16);
	REQUIRE(test_instance->game_over() == true); 
	
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win diagonlly from bottom left 4")
{
	unique_ptr<tic_tac_toe> test_instance = make_unique<tic_tac_toe4>();
	test_instance->start_game("X");

	test_instance->mark_board(13);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(10);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(7);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);
	
	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == true); 
	
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Verify that that x_win, o_win, and ties tally correctly 4")
{
	tic_tac_toe_manager manager_instance;

	unique_ptr<tic_tac_toe> test_instance1 = make_unique<tic_tac_toe4>();
	test_instance1->start_game("X");

	test_instance1->mark_board(13);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(1);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(10);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(2);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(7);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(3);
	REQUIRE(test_instance1->game_over() == false);
	
	test_instance1->mark_board(4);
	REQUIRE(test_instance1->game_over() == true); 
	
	REQUIRE(test_instance1->get_winner() == "X");

	manager_instance.save_game(test_instance1);
	int x, o, t;
    manager_instance.get_winner_totals(x, o, t);
    REQUIRE(x == 1);
    REQUIRE(o == 0);
    REQUIRE(t == 0);

	unique_ptr<tic_tac_toe> test_instance2 = make_unique<tic_tac_toe4>();
	test_instance2->start_game("O");
	
	test_instance2->mark_board(13);
	REQUIRE(test_instance2->game_over() == false);
	
	test_instance2->mark_board(1);
	REQUIRE(test_instance2->game_over() == false);
	
	test_instance2->mark_board(14);
	REQUIRE(test_instance2->game_over() == false);
	
	test_instance2->mark_board(2);
	REQUIRE(test_instance2->game_over() == false);
	
	test_instance2->mark_board(15);
	REQUIRE(test_instance2->game_over() == false);
	
	test_instance2->mark_board(3);
	REQUIRE(test_instance2->game_over() == false);
	
	test_instance2->mark_board(16);
	REQUIRE(test_instance2->game_over() == true);
	
	REQUIRE(test_instance2->get_winner() == "O");

	manager_instance.save_game(test_instance2);
	
    manager_instance.get_winner_totals(x, o, t);
    REQUIRE(x == 1);
    REQUIRE(o == 1);
	REQUIRE(t == 0);

	unique_ptr<tic_tac_toe> test_instance3 = make_unique<tic_tac_toe4>();
	test_instance3->start_game("X");

	test_instance3->mark_board(1); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(2); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(3); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(4); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(6); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(5); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(7); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(8); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(10); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(9); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(12); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(11); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(13); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(14); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(15); 
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(16); 
	
	REQUIRE(test_instance3->game_over() == true);
	REQUIRE(test_instance3->get_winner() == "C");

	manager_instance.save_game(test_instance3);
	
    manager_instance.get_winner_totals(x, o, t);
    REQUIRE(x == 1);
	REQUIRE(o == 1);
    REQUIRE(t == 1);
}
