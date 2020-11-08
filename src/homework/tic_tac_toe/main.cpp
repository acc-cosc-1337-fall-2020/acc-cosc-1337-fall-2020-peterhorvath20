#include "tic_tac_toe_manager.h"

int main()
{
	TicTacToe game;
	string player1;
	string win;
	bool repeat = false;
	string cont;
	TicTacToeManager manager;

	do {
		do {
			cout << "Enter X or O: ";
			cin >> player1;
		} while (player1 != "X" && player1 != "O" && player1 != "x" && player1 != "o");

		game.start_game(player1);

		do {
			cin >> game;
			cout << game;
		} while (!game.game_over());
		cout << "Game over\n";
		win = game.get_winner();
		if (win == "C")
			cout << "Tie game.";
		else
			cout << game.get_winner() << " wins!\n";

		manager.save_game(game);

		cout << "Play again? Enter y to continue: ";
		cin >> cont;
		if (cont == "Y" || cont == "y")
			repeat = true;
		else
			repeat = false;
	} while (repeat);

	cout << manager;

	return 0;
}