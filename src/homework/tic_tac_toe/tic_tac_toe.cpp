#include "tic_tac_toe.h"

// pub

bool TicTacToe::game_over()
{
  if (check_column_win() || check_diagonal_win() || check_row_win())
  {
    set_winner();
    return true;
  }
  else if (check_board_full())
  {
    winner = "C";
    return true;
  }
  return false;
}

void TicTacToe::start_game(string first_player)
{
  if (first_player == "X" || first_player == "x")
  {
    player = "X";
    clear_board();
  }
  else if (first_player == "O" || first_player == "o")
  {
    player = "O";
    clear_board();
  }
}

void TicTacToe::mark_board(int position)
{
  pegs[position - 1] = player;
  set_next_player();
}

string TicTacToe::get_player() const
{
  return player;
}

string TicTacToe::get_winner()
{
  return winner;
}

ostream& operator<<(ostream& os, const TicTacToe& game)
{ // print in 3x3 format
  os << "\n" << game.pegs[0] << "|" << game.pegs[1] << "|" << game.pegs[2] << "\n"
    << game.pegs[3] << "|" << game.pegs[4] << "|" << game.pegs[5] << "\n"
    << game.pegs[6] << "|" << game.pegs[7] << "|" << game.pegs[8] << "\n";

  return os;
}

istream& operator>>(istream& is, TicTacToe& game)
{
  int pos;

  do {
    cout << "\nEnter position from 1 to 9: ";
    is >> pos;
  } while (pos < 0 || pos > 10);
  game.mark_board(pos);

  return is;
}

// priv

void TicTacToe::set_next_player()
{
  if (player == "X")
    player = "O";
  else
    player = "X";
}

bool TicTacToe::check_board_full()
{
  for (int i = 0; i < 9; i++)
    if (pegs[i] == " ")
      return false;
  return true;
}

void TicTacToe::clear_board()
{
  for (int i = 0; i < 9; i++)
    pegs[i] = " ";
}

bool TicTacToe::check_column_win()
{
  if ((pegs[0] != " " && pegs[0] == pegs[3] && pegs[0] == pegs[6])
    || (pegs[1] != " " && pegs[1] == pegs[4] && pegs[1] == pegs[7])
    || (pegs[2] != " " && pegs[2] == pegs[5] && pegs[2] == pegs[8]))
    return true;
  return false;
}

bool TicTacToe::check_row_win()
{
  if ((pegs[0] != " " && pegs[0] == pegs[1] && pegs[0] == pegs[2])
    || (pegs[3] != " " && pegs[3] == pegs[4] && pegs[3] == pegs[5])
    || (pegs[6] != " " && pegs[6] == pegs[7] && pegs[6] == pegs[8]))
    return true;
  return false;
}

bool TicTacToe::check_diagonal_win()
{
  if ((pegs[0] != " " && pegs[0] == pegs[4] && pegs[0] == pegs[8])
    || (pegs[2] != " " && pegs[2] == pegs[4] && pegs[2] == pegs[6]))
    return true;
  return false;
}

void TicTacToe::set_winner()
{
  if (player == "X")
  {
    winner = "O";
    return;
  }
  winner = "X";
}