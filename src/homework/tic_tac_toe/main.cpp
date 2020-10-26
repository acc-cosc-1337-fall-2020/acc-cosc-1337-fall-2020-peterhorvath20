#include "tic_tac_toe.h"

int main()
{
	TicTacToe game;
	string player1;
	int pos;

	do {
		cout << "Enter X or O: ";
		cin >> player1;
	} while (player1 != "X" && player1 != "O" && player1 != "x" && player1 != "o");

	game.start_game(player1);

	do {
		do {
			cout << "\nEnter position from 1 to 9: ";
			cin >> pos;
		} while (pos < 0 || pos > 10);
		game.mark_board(pos);
		game.display_board();
	} while (!game.game_over());
	cout << "Game over";
	return 0;
}