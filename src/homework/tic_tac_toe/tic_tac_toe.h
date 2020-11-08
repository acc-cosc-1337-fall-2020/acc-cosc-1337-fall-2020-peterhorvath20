#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TicTacToe {

public:
  bool game_over();
  void start_game(string first_player);
  void mark_board(int position);
  string get_player() const;
  string get_winner();

  friend ostream& operator<<(ostream& os, const TicTacToe& game);
  friend istream& operator>>(istream& is, TicTacToe& game);

private:
  string player;
  vector<string> pegs{ " ", " ", " ", " ", " ", " ", " ", " ", " " };
  string winner;

  void set_next_player();
  bool check_board_full();
  void clear_board();
  bool check_column_win();
  bool check_row_win();
  bool check_diagonal_win();
  void set_winner();
};