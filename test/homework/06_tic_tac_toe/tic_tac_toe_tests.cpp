#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

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

}
