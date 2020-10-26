#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Test game over if 9 slots are selected.") {
	TicTacToe game;

	game.start_game("X");

	for (int i = 1; i < 10; i++)
		game.mark_board(i);

	REQUIRE(game.game_over() == true);
}

