#include "tic_tac_toe.h"

class TicTacToeManager {

public:
	void save_game(TicTacToe b);
	void get_winner_total(int& o, int& x, int& t);

	friend ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

private:
	vector<TicTacToe> games;
	int x_win = 0;
	int o_win = 0;
	int ties = 0;

	void update_winner_count(string winner);
};