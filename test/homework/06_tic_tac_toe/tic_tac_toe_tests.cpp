#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
/* Homework 6 Test Cases:
1)Create an instance of TicTacToe game
2)Call the start game function with X first player
3)Call mark board 9 times using numbers 1 to 9 (this test case will eventually be the test for CAT tie case). Positions: 
1,2,3,4,5,7,6,9,8. 
4)Check if the game is over after every mark board function call.
*/

/* Homework 7 Update to Test Case:
1)Create an instance of TicTacToe game
2)Call the start game function
3)Call mark board 9 times using numbers 1 to 9 
4) Verify the winner is C
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/
TEST_CASE("Test if the game is over after every mark board function call.")
{
	tic_tac_toe game;

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	
	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(7);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
	REQUIRE(game.game_over() == false);

	game.mark_board(8);
	REQUIRE(game.game_over() == true);

}

/* Homework 7 Update: 
Modify this test case to determine if there is a tie
Test game over if 9 slots are selected.
1)Create an instance of TicTacToe game
2)Call the start game function
3)Call mark board 9 times using numbers 1 to 9 
4) Verify the winner is C
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/
TEST_CASE("Test if the game is over after every mark board function call - Winner C")
{
	tic_tac_toe instance;
	instance.start_game("X");

	instance.mark_board(1);
	REQUIRE(instance.game_over() == false);

	instance.mark_board(2);
	REQUIRE(instance.game_over() == false);

	instance.mark_board(3);
	REQUIRE(instance.game_over() == false);

	instance.mark_board(4);
	REQUIRE(instance.game_over() == false);

	instance.mark_board(5);
	REQUIRE(instance.game_over() == false);

	instance.mark_board(7);
	REQUIRE(instance.game_over() == false);

	instance.mark_board(6);
	REQUIRE(instance.game_over() == false);

	instance.mark_board(9);
	REQUIRE(instance.game_over() == false);

	instance.mark_board(8);
	REQUIRE(instance.game_over() == true);
	REQUIRE(instance.get_winner() == "C");
}

/* Homework 7
Create an instance of TicTacToe, 
call start_game() function with argument X, verify that get_player() returns X
*/
TEST_CASE("Test first player set to X.")
{
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	REQUIRE(test_instance.get_player() == "X");
}
/* Homework 7
Create an instance of TicTacToe, 
call start_game() function with argument O, verify that get_player() returns O
*/

TEST_CASE("Test first player set to O.")
{
	tic_tac_toe test_instance;
	test_instance.start_game("O");

	REQUIRE(test_instance.get_player() == "O");
}

/* Homework 7
Create an instance of TicTacToe, 
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
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(4);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(7);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "X");
}
/* Homework 7
Create an instance of TicTacToe, 
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
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(5);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(4);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(8);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "X");
}
/* Homework 7
Create an instance of TicTacToe, 
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
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(6);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(9);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "X");
}
/* Homework 7
Create an instance of TicTacToe, 
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
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(4);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(5);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "X");
}
/* Homework 7
 Create an instance of TicTacToe, 
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
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(4);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(5);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(6);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "X");
}

/* Homework 7
Create an instance of TicTacToe, 
call start_game() function with argument X,
 set positions for first player X to  7,8,9.  
Pick other positions for O. Verify that game_over() is true.  
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win by third row")
{
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(7);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(8);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(9);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "X");
}

/* Homework 7
 Create an instance of TicTacToe, 
call start_game() function with argument X, 
set positions for first player X to 1,5,9.  
Pick other positions for O. Verify that game_over() is true.  
*/

/* Homework 8 Update to Test Cases:
1)add new assertion REQUIRES... to validate that X or O winner
*/

TEST_CASE("Test win diagonally from top left")
{
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(5);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(9);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "X");
}

/* Homework 7
Create an instance of TicTacToe, 
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
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(7);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(5);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "X");
}

/*Homework 8 Test Cases:
add new assertion REQUIRES... to validate that X or O winner (for all test cases)
Play at least 3 games -- X, O, & C as winners
Add the games to the TicTacToeManager class
test get winner total for correct tally 
*/

TEST_CASE("Test tic_tac_toe_manager") 
{
	//Test win diagonally from bottom left. X Wins 1

	tic_tac_toe test_instance;
	tic_tac_toe_manager manager_instance; 
	test_instance.start_game("X");

	test_instance.mark_board(7);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(5);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);
	
	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "X");

	manager_instance.save_game(test_instance);
	int x, o, t;
	manager_instance.get_winner_totals(x, o, t);
	REQUIRE(x == 1);
	REQUIRE(o == 0);
	REQUIRE(t == 0);

	//Test win by first column. O Wins 1

	test_instance.start_game("O");

	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(4);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(7);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "O");

	manager_instance.save_game(test_instance);

	manager_instance.get_winner_totals(x, o, t);
	REQUIRE(x == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 0);

	//Test tied game. T Wins 1.
	test_instance.start_game("X");

	test_instance.mark_board(1);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(2);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(4);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(5);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(7);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(6);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(9);
	REQUIRE(test_instance.game_over() == false);

	test_instance.mark_board(8);
	REQUIRE(test_instance.game_over() == true);
	REQUIRE(test_instance.get_winner() == "C");

	manager_instance.save_game(test_instance);

	manager_instance.get_winner_totals(x, o, t);
	REQUIRE(x == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}
