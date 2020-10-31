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

void TicTacToe::display_board() const
{ // print in 3x3 format
  cout << pegs[0] << "|" << pegs[1] << "|" << pegs[2] << "\n"
    << pegs[3] << "|" << pegs[4] << "|" << pegs[5] << "\n"
    << pegs[6] << "|" << pegs[7] << "|" << pegs[8] << "\n";
}

string TicTacToe::get_winner()
{
  return winner;
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
