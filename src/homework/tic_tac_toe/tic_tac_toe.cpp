#include "tic_tac_toe.h"

bool TicTacToe::game_over() 
{
  return check_board_full();
}

void TicTacToe::start_game(string first_player)
{
  if (first_player == "X" || first_player == "O")
  {
    player = first_player;
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
