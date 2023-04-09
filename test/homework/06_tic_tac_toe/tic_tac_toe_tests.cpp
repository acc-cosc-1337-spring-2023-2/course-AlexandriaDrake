#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

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

TEST_CASE("Test if the game is over after every mark board function call")
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

TEST_CASE("Test first player set to X.")
{
	tic_tac_toe test_instance;
	test_instance.start_game("X");

	REQUIRE(test_instance.get_player() == "X");
}

TEST_CASE("Test first player set to O.")
{
	tic_tac_toe test_instance;
	test_instance.start_game("O");

	REQUIRE(test_instance.get_player() == "O");
}

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
TEST_CASE("Test win diagonlly from top left")
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
TEST_CASE("Test win diagonlly from bottom left")
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
	//Test win diagonlly from bottom left. X Wins 1

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
